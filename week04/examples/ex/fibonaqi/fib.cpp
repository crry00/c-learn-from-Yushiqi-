#include <iostream>
#include "fib.hpp"

using namespace std;    


int fib(size_t num){
    
    if (num==1||num==2){
        //cout<<" 1 "<<endl;
        return 1;
    }
    else{ 
        int result=fib(num-1)+fib(num-2);
        //cout<<" "<<result<<" "<<endl;
        return result;
    }
}