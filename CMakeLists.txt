cmake_minimum_required(VERSION 3.17)
project(csock)
link_libraries(ws2_32)
set(CMAKE_CXX_STANDARD 11)

add_executable(
        csock
        main.cpp
        controller/connection/BaseConnection.cpp controller/connection/BaseConnection.h
        controller/connection/ControlConnection.cpp controller/connection/ControlConnection.h
        controller/connection/TransferConnection.cpp controller/connection/TransferConnection.h
        controller/definition/Notice.h
        controller/connection/Connection.h config.h
        controller/definition/Handshake.h controller/definition/Handshake.cpp
        controller/definition/Slice.cpp controller/definition/Slice.h
        controller/definition/Request.cpp controller/definition/Request.h
        controller/definition/Response.cpp controller/definition/Response.h
        controller/task/BaseTask.h controller/task/BaseTask.cpp

        include/cppbase64/base64.cpp include/cppbase64/base64.h
        )
include_directories(
        include
        controller)
