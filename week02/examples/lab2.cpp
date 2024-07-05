#include <iostream>
using namespace std;
int main()
{
cout.setf(ios_base::fixed, ios_base::floatfield);
cout << 56.8 << endl;
cout.width(12);
cout.fill('-');
cout << 456.77 << endl;
cout.precision(2);
cout << 123.356 << endl;
cout.precision(5);
cout << 3897.678485 << endl;
return 0;
}