#include <iostream>
using namespace std;

int main()
{
    unsigned int a = 56789;
    unsigned int b = 56789;
    unsigned int c = a * b;
    cout << "c = " << c << endl;

    // unsigned int c1 = a * b; //danger operation
    // cout << "c1 = " << c1 << endl;
    return 0;
}
