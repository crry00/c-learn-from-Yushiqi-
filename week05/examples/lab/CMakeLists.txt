cmake_minimum_required(VERSION 3.10)

project(hello)

aux_source_directory(./src DIR_SRC)

include_directories(./include)

add_executable(hello main.cpp ${DIR_SRC})
#{}
