#include <iostream>
#include "time.hpp"

using namespace std;

int main()
{
    MyTime t1(1, 20);
    int minutes = t1; //implicit conversion
    float f = (float)t1; //explicit conversion. 
    //(float)t1 or float(t1) both ok
    std::cout << "minutes = " << minutes << std::endl;
    std::cout << "minutes = " << f << std::endl;

    MyTime t2 = 70;//初始化，调用构造函数(int),如果是{2,70},调用（int，int）；如果是（2，70），调用（int），为70
    std::cout << "t2 is " << t2 << std::endl;

    MyTime t3;
    t3 = 80;//赋值
    std::cout << "t3 is " << t3 << std::endl;

    //for(size_t i =0;i<1000000;i++){}

    return 0;

}

