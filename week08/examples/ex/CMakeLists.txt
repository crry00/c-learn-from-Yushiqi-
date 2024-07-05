cmake_minimum_required(VERSION 3.12)

#add_definitions(-DWITH_NEON)
add_definitions(-DWITH_AVX2)
add_definitions(-mavx2)
add_definitions(-O3)
#告诉编译器在生成的代码中包含AVX2指令集的支持

set(CMAKE_CXX_STANDARD 17)

project(dotp)

ADD_EXECUTABLE(dotp main.cpp add.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message("OpenMP found.")
    target_link_libraries(dotp PUBLIC OpenMP::OpenMP_CXX)
endif()


# 未优化代码下的执行时间
# normal: result=9.1, duration = 426ms
# unloop: result=9.1, duration = 424ms，条件判断看起来影响不大，主要是编译器优化了许多
# AVS: result=9.1, duration = 111ms
# AVS+OpenMP: result=6.9, duration = 836ms，由于多线程对同一个寄存器写，不是线程安全，会出错

#cmake .. -DCMAKE_BUILD_TYPE=Release -o3级优化下//没有aligned内存对齐
# normal: result=9.1, duration = 110ms
# unloop: result=9.1, duration = 112ms
# AVS: result=9.1, duration = 75ms//提速不大其实
# AVS+OpenMP: result=0, duration = 31ms

#cmake .. -DCMAKE_BUILD_TYPE=Release -o3级优化下//aligned内存对齐下
# normal: result=9.1, duration = 105ms
# unloop: result=9.1, duration = 105ms
# AVS: result=9.1, duration = 14ms 刚好近似8倍
# AVS+OpenMP: result=0, duration = 11ms