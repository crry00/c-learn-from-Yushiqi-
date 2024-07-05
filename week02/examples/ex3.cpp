#include <iostream>
#include <math.h>
using namespace std;
int main() 
{
cout << fixed;
float f1 = 1.0f;
cout<<"f1 = "<<f1<<endl;
float a = 0.1f;
float f2 = a*10;
cout<<"f2 = "<<f2<<endl;
if(abs(f1-f2)<__FLT_EPSILON__)
cout << "f1 = f2" << endl;
else
cout << "f1 != f2" << endl;
return 0;
}
//可能是0.1处没有很对应的间隔
