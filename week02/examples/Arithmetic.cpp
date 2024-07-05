// ~a bitwise not,二进制对调,01->10
//a&b
#include <iostream>

using namespace std;

int main()
{
    unsigned char a=255;
    unsigned char b=1;
    int c=a+b;//+ will enhance the char to int 
    cout<<c<<"sizeof(a+b)"<<sizeof(a+b)<<endl;
}