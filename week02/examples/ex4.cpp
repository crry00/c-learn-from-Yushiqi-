#include <iostream>
using namespace std;
int main()
{
int a, b;
double c, d;
a = 19.99 + 21.99;
b = (int)19.99 + (int)21.99;
c = 23 / 8;
d = 23 / 8.0;
cout<<fixed;
cout << "a = " << a << endl;//41
cout << "b = " << b << endl;//40
cout << "c = " << c << endl;//2.f
cout << "d = " << d << endl;//2.875000
//cout << "0/0= " << 0/0 << endl;//nan

auto g = 10;
g = 20.5;
g += 10.5;
std::cout << g << std::endl;
return 0;
}
