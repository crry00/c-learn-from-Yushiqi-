#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    
    cout << &a << endl;//from bottom to top,isn't top to bottom
    cout << &b << endl;
    cout << &c << endl;

    int * p1 = (int*)malloc (4);
    int * p2 = (int*) malloc (16);
    int * p3 = (int*) malloc (sizeof(int));//if ask for int,use sizeof but not the 4 bytes!

    cout << &p1 << endl;//64bit each gap 8bytes
    cout << &p2 << endl;
    cout << &p3 << endl;
    
    cout << p1 << endl;//each take 32 bytes
    cout << p2 << endl;
    cout << p3 << endl;

    free(p1);
    free(p2);
    free(p3);

    return 0;
}
