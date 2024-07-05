#pragma once 

#include <string>
#include <iostream>
template<typename T>
int Compare(const T &a,const T&b){
    std::cout<<"Compare of the two "<<typeid(T).name()<<" : "<<std::endl;
    if(a==b){
        return 0;
    }
    else{
        return a>b?1:-1;
    }
}

struct stuinfo
{
    std::string name;
    int age;
};

template<>
int Compare<stuinfo>(const stuinfo& a,const stuinfo& b){
    std::cout<<"Compare of the two "<<typeid(stuinfo).name()<<" : "<<std::endl;
    if(a.age==b.age){
        return 0;
    }
    else{
        return a.age>b.age?1:-1;
    }

}
