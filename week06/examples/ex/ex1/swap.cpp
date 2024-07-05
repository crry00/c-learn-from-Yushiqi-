#include <iostream>
#include "swap.hpp"

using namespace std;


// template<typename T>
void swap(int & a,int & b){
    cout<<"before: a= "<<a<<"b = "<<b<<endl;
    int temp=b;
    b=a;
    a=temp;
    cout<<"after: a= "<<a<< " b = "<<b<<endl;
}