#include <iostream>  
#include <memory> // 包含 std::shared_ptr  
  
class B; // 前置声明  
  
class A {  
public:  
    std::shared_ptr<B> pb;  
    A() { std::cout << "Constructor A" << std::endl; }  
    ~A() { std::cout << "Destructor A" << std::endl; }  
};  
  
class B {  
public:  
    std::shared_ptr<A> pa;  
    B() { std::cout << "Constructor B" << std::endl; }  
    ~B() { std::cout << "Destructor B" << std::endl; }  
};  
  
int main() {  
    std::shared_ptr<A> spa = std::make_shared<A>();  
    std::shared_ptr<B> spb = std::make_shared<B>();  
    spa->pb = spb;  
    spb->pa = spa;  
    return 0;  
}

//两个共享指针相互对指，都无法释放，
//block结束后，先释放spb，发现引用数不为1；再释放spa，发现引用数不为1，因为上一个spb手上还有引用
