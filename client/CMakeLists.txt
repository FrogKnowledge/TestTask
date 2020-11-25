cmake_minimum_required(VERSION 3.5)
project(Client)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES ../protos/testTask.grpc.pb.cc ../protos/testTask.grpc.pb.h ../protos/testTask.pb.cc ../protos/testTask.pb.h)

add_executable(Client src/client.cpp ../protos/testTask.grpc.pb.cc ../protos/testTask.pb.cc)

target_include_directories(
    Client
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)


target_link_libraries(
    Client
    grpc++
    grpc 
    protobuf::libprotobuf
    )