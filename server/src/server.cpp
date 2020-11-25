#include <iostream>
#include <grpc++/grpc++.h> 
#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>

#include "../../protos/testTask.grpc.pb.h"

#define ADDR "0.0.0.0:40055"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerWriter;
using grpc::Status;

using handler::Number;
using handler::NumberMassive;
using handler::MassiveHandlerService;


class MassiveHandlerServiceImpl: public MassiveHandlerService::Service{
    public:
    MassiveHandlerServiceImpl(){};

    Status Handle(ServerContext* context, const NumberMassive* massive, Number* number){

        int max_count_of_ones=0;
        int count_of_ones=0;
        int marked_index=-1;
        bool met_a_one = false;

        for(int i=0;i<massive->mass_size();i++){

            if(massive->mass(i)==1){
                count_of_ones++;
                met_a_one = true;
            }
            else if(met_a_one){

                if(marked_index!=-1){
                    max_count_of_ones = MAX(max_count_of_ones, count_of_ones);
                    count_of_ones = 0;
                    i = marked_index;
                    marked_index = -1;
                    met_a_one = false;
                }
                else{
                    marked_index = i;
                }
            }
        }

        number->set_number(MAX(max_count_of_ones, count_of_ones));
        return Status::OK;
    }

};


void RunServer(){
    std::string server_adress= ADDR;
    MassiveHandlerServiceImpl service=MassiveHandlerServiceImpl();

    ServerBuilder builder;
    builder.AddListeningPort(server_adress,grpc::InsecureServerCredentials());
    builder.RegisterService(&service); 
    std::unique_ptr<Server> server(builder.BuildAndStart());
    server->Wait();
    
}


int main(){
    RunServer();
    return 0;
}