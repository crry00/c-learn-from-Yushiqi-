#include <iostream>  
#include <cstdlib>  
#include <string>  
#include <limits>

class Mul {  
private:  
    int a;  
    int b;  
  
public:  
    Mul(int a, int b) : a(a), b(b) {}  
  
    int64_t mul() const {  
        return a * b;  
    }  
  
    friend std::ostream& operator<<(std::ostream& os, const Mul& t) {  
        os << t.a << " * " << t.b << "= " << t.mul() << "\n";  
        return os;  
    }  
  
static bool action() {  
    int tmpa, tmpb;  
    std::cin >> tmpa;  
    if (std::cin.fail()) {  
        std::cerr << "Please input two integers: Invalid input (first number)" << std::endl;  
        std::cin.clear(); // 清除错误状态  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略当前行剩余的所有输入  
        return false;  
    }  
    std::cin >> tmpb;  
    if (std::cin.fail()) {  
        std::cerr << "Please input two integers: Invalid input (second number)" << std::endl;  
        std::cin.clear(); // 清除错误状态  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略当前行剩余的所有输入  
        return false;  
    }  
    std::cout << Mul(tmpa, tmpb);  
    return true;  
}};  
  
int main() {  
    while (true) {  
        std::cout << "input two integers: ";  
        if (Mul::action())  
            break;  
    }  
    return 0;
}