cmake_minimum_required(VERSION 3.6)

####
project(16.18)

include_directories(../../common/include)

aux_source_directory(. SRC_LIST)
aux_source_directory(../../common/fileio SRC_LIST)
aux_source_directory(../../common/lib SRC_LIST)
aux_source_directory(../../common/ipc1 SRC_LIST)
aux_source_directory(../../common/deamons SRC_LIST)
aux_source_directory(../../common/sockets SRC_LIST)

add_executable(ruptimed-fd ${SRC_LIST})
