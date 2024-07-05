#include<iostream>

using namespace std;

int main()
{
    int a;
    while(cin>>a)
    {
        try
        {
            if(a>=0)
            {
                cout<<a<<endl;
            }
            else
            {
                throw -1;
            }
            
        }
        catch(const int& e)
        {
            cerr<<"the input "<<to_string(e)<<"is <0"<<endl;
        }
    }
}