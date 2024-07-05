#include <iostream>

class Base {  
public:  
    virtual void print() {  
        std::cout << "This is Base class" << std::endl;  
    }  
};  
  
class Derived : public Base {  
public:  
    void print() override {  
        std::cout << "This is Derived class" << std::endl;  
    }  
    void derivedFunction() {  
        std::cout << "Derived-specific function" << std::endl;  
    }  
};


int main()
{
    Base* basePtr = new Derived();  
    Derived* derivedPtr = static_cast<Derived*>(basePtr); // 安全的向上转换（子类到父类）后，再尝试向下转换（父类到子类）  
    
    if (derivedPtr) { // 这里实际上没有检查转换是否成功，因为static_cast不执行运行时类型检查  
        derivedPtr->print();   // 输出：This is Derived class  
        derivedPtr->derivedFunction(); // 正确调用，因为basePtr确实指向Derived对象  
    }  
    
    // 注意：如果basePtr没有指向Derived对象，那么上面的derivedPtr->derivedFunction()调用将是未定义的，可能导致运行时错误


    Derived* derivedPtrDynamic = dynamic_cast<Derived*>(basePtr); // 安全的向下转换（父类到子类）  
    
    if (derivedPtrDynamic) { // 检查转换是否成功  
        derivedPtrDynamic->print();   // 输出：This is Derived class  
        derivedPtrDynamic->derivedFunction(); // 正确调用  
    } else {  
        std::cout << "Conversion failed" << std::endl;  
    }  
    
    // 如果basePtr没有指向Derived对象（或任何Derived的派生类对象），derivedPtrDynamic将是nullptr


/*
static_cast：用于编译时类型转换，不进行运行时类型检查，需要程序员确保转换的安全性。多用于数据结构转换，
dynamic_cast：用于运行时类型转换，进行类型检查，如果转换不安全则返回nullptr（对于指针）,多用于类的继承
或抛出异常（对于引用），提供了更高的安全性。
*/
}