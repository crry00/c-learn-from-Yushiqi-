#include <iostream>
using namespace std;

typedef char name[3];

int main()
{
    int num_array[5]; 

    for(int idx = -1; idx <= 5; idx++) //out of bounds
        num_array[idx] = idx * idx;

    for(int idx = -1; idx <= 5; idx++) //out of bounds
        cout << "num_array[" << idx << "] = " << num_array[idx] << endl;

    name cuiyu={'a','b','c'};
    cout<<cuiyu<<endl;

    return 0;
}