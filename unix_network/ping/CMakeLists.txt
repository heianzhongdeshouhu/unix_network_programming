cmake_minimum_required(VERSION 3.3)

PROJECT(cping)

include_directories(
    ../lib
    ../libfree
)

AUX_SOURCE_DIRECTORY(. SRC_LIST)
AUX_SOURCE_DIRECTORY(../lib SRC_LIST)
AUX_SOURCE_DIRECTORY(../libfree SRC_LIST)
ADD_EXECUTABLE(cping ${SRC_LIST})
