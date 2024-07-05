#include <iostream>
#include <cstdlib>
#include <chrono>
#include "add.hpp"

#define TIME_START start=std::chrono::steady_clock::now();
#define TIME_END(NAME) end=std::chrono::steady_clock::now();\
            duration=std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();\
            cout<<(NAME)<<": result "<<result[0] \
            <<", duration = "<<duration<<"ms"<<endl;

int main(int argc,char** argv){
    size_t nSize=20000000;
    vector<float> a(nSize,__FLT_MIN__);
    vector<float> b(a);
    vector<float> result(nSize,__FLT_MIN__);
    a.at(0)=20.f;
    b.at(0)=30.f;
    a.at(20000)=20.f;
    b.at(2000)=30.f;
    auto start=std::chrono::steady_clock::now();
    auto end=std::chrono::steady_clock::now();
    auto duration=0L;

    result=add(a,b);
    result=add(a,b);

    TIME_START
    result=add(a,b);
    TIME_END("pure c")

    TIME_START
    result=add_avx2(a,b);
    TIME_END("avx2 c")

    TIME_START
    result=add_avx2_omp(a,b);
    TIME_END("avx2 omp c")

    TIME_START
    result=add_omp(a,b);
    TIME_END("c omp")

}