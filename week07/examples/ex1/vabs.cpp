#include <iostream>
#include "vabs.hpp"

bool vabs(int * p,int n){
    if((n<0)||(p==nullptr)){
        std::cerr<<"the number must >=0!!"<<std::endl;
        return false;
    }
    for(size_t i=0;i<n;i++)
    {
        p[i]=abs(p[i]);
    }
    return true;
}
bool vabs(float * p,int n){
    if((n<0)||(p==nullptr)){
        std::cerr<<"the number must >=0!!"<<std::endl;
        return false;
    }
    for(size_t i=0;i<n;i++)
    {
        p[i]=abs(p[i]);
    }
    return true;
}
bool vabs(double * p,int n){
    if((n<0)||(p==nullptr)){
        std::cerr<<"the number must >=0!!"<<std::endl;
        return false;
    }
    for(size_t i=0;i<n;i++)
    {
        p[i]=abs(p[i]);
    }
    return true;
}
