#include <iostream>
#include <string>

using namespace std;
int main()
{
    std::string str1 = "Hello";
    std::string str2 = "SUSTech";
    std::string result = str1 + ", " + str2;//直接加号即可，重载了加号运算符

    cout << "result = " + result << endl;//前后字符串先作连接

    cout << "The length is " << result.length() << endl;
    
    cout << "str1 < str2 is " << (str1 < str2) << endl;

    cout << "str1[100] = (" << str1[100] << ")" << endl;//没有边界检查！！

    return 0;
}