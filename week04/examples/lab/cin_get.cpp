#include <iostream>
#include <string>
using namespace std;

int main()
{
    // char str[20];

    // cout<<"Enter a string:";
    // cin.get(str,20);
    // cout<<"You enter:"<<str<<endl;

    // cin.get();//if ignore ,the \n will be get 
    // cout<<"Enter a string:";
    // cin.get(str,20);
    // cout<<"You enter:"<<str<<endl;

    // cout<<"Enter a string:";
    // cin.getline(str,20);//19char
    // cout<<"You enter:"<<str<<endl;

    // cout<<"Enter a string:";
    // cin.getline(str,20);//will drop \n ,but cin.get()will not drop!!
    // cout<<"You enter:"<<str<<endl;

    //if using string
    string str;
    cout<<"Enter a string:";
    getline(cin,str);
    cout<<"You enter:"<<str<<endl;

    cout<<"Enter a string:";
    getline(cin,str);
    cout<<"You enter:"<<str<<endl;




}
//cin will catch every break,cin.get()and getline() just catch \n