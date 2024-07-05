#include "vabs.hpp"
#include <iostream>

using namespace std;

int main()
{
    int p[10]={1,-2,3};
    cout<<p[1]<<endl;
    vabs(p,2);
    cout<<p[1]<<endl;
}