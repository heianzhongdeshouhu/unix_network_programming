cmake_minimum_required(VERSION 3.7)

project(tcpserv01)

include_directories(../../key/)

aux_source_directory(. SRC_LIST)
aux_source_directory(../../lib/ SRC_LIST)

add_executable(tcpserv01 ${SRC_LIST})


