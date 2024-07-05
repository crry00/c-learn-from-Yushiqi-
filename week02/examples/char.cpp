#include <iostream>
using namespace std;

int main()
{
    char c1 = 'C';
    char c2 = 80;
    char c3 = 0x50;
    char16_t c4 = u'于';//8bit not enough to contain chinese...
    char32_t c5 = U'于';//!u~16,U~32
    cout << c1 << ":" << c2 << ":"<< c3 << endl;//字符串打印
    cout << +c1 << ":" << +c2 << ":" << +c3 << endl;//强制隐式转为整数打印
    cout << c4 << endl;
    cout << c5 << endl;
    
    return 0;
}

