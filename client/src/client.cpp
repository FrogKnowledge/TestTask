#include <iostream>
#include <string.h>
#include <regex>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#define ADDR "localhost:40055"

#include "../../protos/testTask.grpc.pb.h"
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;

using handler::Number;
using handler::NumberMassive;
using handler::MassiveHandlerService;


bool CreateMassiveUsingStdIn(NumberMassive& mass){
    bool result = false;
    std::string buffer;
    std::cin>>buffer;
    std::smatch sm;

    if(std::regex_match(buffer,sm,std::regex("\\[((1|0)(,(1|0))*)?\\]"))){
        buffer = sm[0];
        buffer=buffer.substr(1, buffer.length()-2);
        int numbers_conut = buffer.length()>0?buffer.length()/2 + 1 : 0;

        for(int i=0;i<numbers_conut;i++){
            int number = buffer[i*2] - '0';
            mass.add_mass(number);
        }

        result=true;
    }
    else {
        std::cout<<"Something wrong with the entered value\n";
    }
    
    return result;
}

int main(){

    ClientContext context;
    NumberMassive massive;
    Number        number;

    if(CreateMassiveUsingStdIn(massive)){
        auto rpc_controller = MassiveHandlerService::NewStub( 
             grpc::CreateChannel(
                ADDR,
                grpc::InsecureChannelCredentials()
                )
            );
        
        rpc_controller->Handle(&context,massive,&number);
        std::cout<<number.number()<<'\n';
    }
}