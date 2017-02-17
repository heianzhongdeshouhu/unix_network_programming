cmake_minimum_required(VERSION 3.6)

####
project(15.33)

include_directories(../../common/include)

aux_source_directory(. SRC_LIST)
aux_source_directory(../../common/fileio SRC_LIST)
aux_source_directory(../../common/lib SRC_LIST)
aux_source_directory(../../common/ipc1 SRC_LIST)

add_executable(devzero ${SRC_LIST})
