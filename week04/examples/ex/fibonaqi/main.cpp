#include "fib.hpp"
#include <iostream>

using namespace std;

int main()
{
    size_t num;
    cout<<"please input positive number:";
    cin>>num;
    for(size_t i=num;i>0;i--)
        cout<<"  "<<fib(i);//可以不接返回值
}