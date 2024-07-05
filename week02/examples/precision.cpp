#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    float f1 = 23400000000;
    float f2 = f1 + 1100;//注意这里是采样取点，每个点都有间隔。。如果采完比如
    //+10，但是离下个点还是很远，可能会保持不变

    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f1 - f2 = " << f1 - f2 << endl;
    cout << "(f1 - f2 == 0) = " << (f1 - f2 == 0) << endl;

    float a=2.2E+12f;
    float b=2.200e+12f;

    if(a==b)
    {
        cout<<"a==b"<<endl;
    }

    if(fabs(a-b)<__FLT_EPSILON__)
    {
        cout<<std::fixed<<std::setprecision(15)<<a-b<<"    a-b<epison"<<endl;
    }

    return 0;
}
