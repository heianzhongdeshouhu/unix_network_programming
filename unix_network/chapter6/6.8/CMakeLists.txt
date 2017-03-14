cmake_minimum_required(VERSION 3.6)

project(tcpservselect01)

include_directories(../../key/)

aux_source_directory(./ SRC_LIST)
aux_source_directory(../../lib/ SRC_LIST)

add_executable(tcpservselect01 ${SRC_LIST})
