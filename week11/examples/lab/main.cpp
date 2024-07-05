#include "matrix.h"

int main()
{

    Matrix a(3,4);
    Matrix b(3,4);
    a[3]=10.f;
    b[10]=22.f;

    cout<<a<<endl;
    Matrix c=a+b;
    cout<<c;
}