#include <iostream>
using namespace std;

int main()
{
    int value1 = 100;
    const int value2 = 200;
    cout << "value1 = " << value1 << endl;
    cout << "value2 = " << value2 << endl;

    // int * pv1 = &value1;
    int * pv1 = const_cast<int *>(&value1);
    // int * pv2 = &value2; // error
    //const int* pv2=& value2;//true
    int * pv2 = const_cast<int *>(&value2);

    (*pv1)++;
    (*pv2)++;

    cout << "value1 = " << (*pv1) << endl;
    cout << "value2 = " << (value2) << endl;//这是因为 const 变量在编译时可能被放置在只读内存段中，
                                        //且编译器可能选择直接替换其使用处的值为常量值，而不是从内存中读取。
    
    // // int & v2 = value2; //error
    int& v2 = const_cast<int&>(value2);
    v2++;
    cout << "value2 = " << value2 << endl;

    cout << "*pv2 = " << (*pv2) << endl;
    cout << "v2 = " << v2 << endl;
/*
他们修改的是在内存中的“副本”
const_cast 修改了这个位置的值，但这个修改不会影响到通过原始 const 变量名进行的访问。
这是因为编译器在处理 const 变量时可能会进行优化，比如直接在编译时将 const 变量的值替换到使用它的地方，
而不是在运行时从内存中读取它的值。*/
   return 0;
}


