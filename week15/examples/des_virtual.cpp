/*
除非你在类定义中显式地将析构函数声明为virtual，否则它不会是virtual的。
在C++中，析构函数默认不是virtual的，这意味着如果你有一个基类指针指向派生类对象，
并通过基类指针删除该对象，那么只有基类的析构函数会被调用，而不会调用派生类的析构函数。
为了避免这种情况，你应该在基类中将析构函数声明为virtual。
这样，当你通过基类指针删除派生类对象时，会首先调用派生类的析构函数，然后再调用基类的析构函数，
从而确保派生类和基类中的资源都被正确释放。
*/
#include <iostream>

class Base {  
public:  
    virtual ~Base() {  
        std::cout<<"Base destor"<<std::endl;
        // 基类析构代码  
    }  
};  
  
class Derived : public Base {  
public:  
    ~Derived() override {  
        std::cout<<"Derive destor"<<std::endl;// 派生类析构代码  
    }  
};  
  
int main() {  
    Base* ptr = new Derived();  
    delete ptr; // 这会首先调用Derived的析构函数，然后调用Base的析构函数  
    return 0;  
}