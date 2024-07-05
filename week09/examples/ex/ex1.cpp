#include <iostream>
using namespace std;
class Demo 
{
public :
    static int num;
    static void display();
};

void Demo::display(){
        cout << "The value of the static member variable num is: " << num <<endl;
}
int Demo::num=5;

int main() 
{
    Demo obj;
    obj.display();
    Demo::num=10;
    Demo::display();
    return 0;
}
