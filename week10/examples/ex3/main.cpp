#include <iostream>
#include "complex.hpp"


int main()
{
    Complex a(3,4),b{2,6};//()调用构造函数,{}C++11定义初始化
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"~b="<<~b<<endl;
    cout<<"a+b="<<a+b<<endl;
    cout<<"a-b="<<a-b<<endl;
    cout<<"a-2="<<a-2<<endl;
    cout<<"a*b"<<a*b<<endl;
    cout<<"2*a"<<2*a<<endl;
    cout<<"2+a"<<2+a<<endl;
    cout<<"------------------------"<<endl;

    Complex c=b;
    cout<<"c="<<c<<endl;
    cout<<"b==c?"<<boolalpha<<(b==c)<<endl;
    cout<<"b!=c?"<<boolalpha<<(b!=c)<<endl;
    cout<<"a==b?"<<boolalpha<<(a==b)<<endl;
    Complex d;
    cin>>d;
    d.display();
}

