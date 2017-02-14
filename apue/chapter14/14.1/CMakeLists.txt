cmake_minimum_required(VERSION 3.6)

####
project(14.1)

include_directories(../../common/include)

#aux_source_directory(. ../common/fileio ../common/lib ../common/include SRC_LIST)
aux_source_directory(./ SRC_LIST)
aux_source_directory(../../common/fileio SRC_LIST)
aux_source_directory(../../common/lib SRC_LIST)

add_executable(nonblockw ${SRC_LIST})

