#include <iostream>
using namespace std;
int main()
{
    int num_array1[5]; //uninitialized array, random values 
    int num_array2[5]={1,2,3,4,5}; //initialization

    for(int a:num_array1)
        cout << a << " ";
    cout << endl;

    for(int idx = 0; idx < 5; idx++)
        cout << num_array2[idx] << " ";
    cout << endl;

    return 0;
}
