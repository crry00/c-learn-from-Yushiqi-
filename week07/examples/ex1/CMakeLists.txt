cmake_minimum_required(VERSION 3.10)

project(vabsdemo)

add_library(vabs SHARED vabs.cpp)

add_executable(vabsdemo main.cpp)

target_link_libraries(vabsdemo vabs)

