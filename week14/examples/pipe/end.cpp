#include<iostream>

using namespace std;

int main()
{
    int a;
    while(cin>>a)
    {
        cout<<"the input is "<<to_string(a)<<endl;//will be better
        // cout<<"the input is "+to_string(a)<<endl;
    }
}//use pipe to connect two program ./start |./end