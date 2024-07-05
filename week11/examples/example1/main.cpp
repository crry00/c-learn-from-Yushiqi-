#include <iostream>
#include "mystring.hpp"

using namespace std;

// Why memory leak and memory double free?
int main()
{
    {
        MyString str1(10, "Shenzhen");
        cout << "str1: " << str1 << endl;

        MyString str2 = str1; //没有写拷贝构造函数，编译器默认创造浅拷贝，拷贝指针，造成指向同一块内存。
        cout << "str2: " << str2 << endl;

        MyString str3;
        cout << "str3: " << str3 << endl;
        str3 = str1;//赋值拷贝未定义，编译器默认创造赋值浅拷贝，拷贝指针，原内存泄漏
        cout << "str3: " << str3 << endl;
    }
    cout << "end of main()" << endl; // it will not be printed out
    return 0;
}