#include <iostream>

using namespace std;

int sum(int x, int y)
{
    cout << "sum(int, int) is called" << endl;
    return x + y;
}
float sum(float x, float y)
{
    cout << "sum(float, float) is called" << endl;
    return x + y;
}
double sum(double x, double y)
{
    cout << "sum(double, double) is called" << endl;
    return x + y;
}

// //Is the following definition correct? just return deferent can't overload! 
// double sum(int x, int y)
// {
//     cout << "sum(int, int) is called" << endl;
//     return x + y;
// }

int main()
{

    cout << "sum = " << sum(1, 2) << endl;
    cout << "sum = " << sum(1.1f, 2.2f) << endl;
    cout << "sum = " << sum(1.1, 2.2) << endl;

    //which function will be called?
    //cout << "sum = " << sum(1, 2.2) << endl;
    //if many overload ,it will error ,beacuse two meaning!!

    return 0;
}