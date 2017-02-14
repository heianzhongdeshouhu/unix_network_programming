cmake_minimum_required(VERSION 3.6)

####
project(14.21)

include_directories(../../common/include)

aux_source_directory(. SRC_LIST)
aux_source_directory(../../common/fileio SRC_LIST)
aux_source_directory(../../common/lib SRC_LIST)
aux_source_directory(../../common/ipc1 SRC_LIST)

add_executable(rot13c2 ${SRC_LIST})
target_link_libraries(rot13c2 rt)
