#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
T sum(T x, T y)
{
    cout << "The input type is " << typeid(T).name() << endl;
    return x +
     y;
}
// Explicitly instantiate,all is
template double sum<double>(double,double);
template int sum(int,int);
// template char sum<>(char,char);

int main()
{   
    auto val = sum(4.1f, 5.2f);
    cout << val << typeid(int).name()<<endl;
    return 0;
}
