#include <iostream>
using namespace std;

int main()
{
    int num_int1 = 9; // assigning an int value to num_int1
    int num_int2 = 'C'; // implicit conversion
    int num_int3 = (int)'C'; // explicit conversion, C-style
    int num_int4 = int('C'); // explicit conversion, function style
    int num_int5 = 2.8; //implicit conversion,drop little ,just 2
    float num_float = 2.3; // implicit conversion from double to float, may loss precision
    short num_short = 650000; 

    cout << "num_short = " << num_short << endl;
    int num1=0x7ABCDEF0;
    double num1float=num1;
    int num2=(int)num1float;
    cout<<num1<<"     "<<num2<<endl;
    return 0;
}
