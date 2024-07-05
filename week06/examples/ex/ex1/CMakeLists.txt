cmake_minimum_required(VERSION 3.10)

project(swapdemo)

add_library(swap STATIC swap.cpp)

add_executable(swapdemo main.cpp)

target_link_libraries(swapdemo swap)
