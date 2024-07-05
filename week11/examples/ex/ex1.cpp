#include <iostream>
#include <memory>
using namespace std;
int main()
{
    double *p_reg = new double(5);
    shared_ptr<double> pd;//不推荐，最好初始化，现在是空的ptr
    //pd = p_reg;//不可以不同类型赋值 
    pd = shared_ptr<double>(p_reg); //接管刚构造的ptr
    cout << "*pd = " << *pd << endl;

    shared_ptr<double> pshared =pd; 
    //shared_ptr<double> pshared(p_reg); 
    cout << "*pshred = " << *pshared << endl;

    string* str=new string("Hello World!");
    shared_ptr<string> pstr(str); 
    cout << "*pstr = " << *pstr << endl;

    return 0;

}
