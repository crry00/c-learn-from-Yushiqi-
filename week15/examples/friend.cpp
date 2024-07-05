#include <iostream>
using namespace std;

class Sniper;

class Supplier
{
    int storage;
public:
    Supplier(int storage = 1000): storage(storage){}

    // bool foo(Sniper & sniper){sniper.bullets++;}
    bool provide(Sniper & sniper);//由于上面的声明，这里可以调用sniper类型，但不知道sniper类内的具体操作
    //所以函数的具体实现要放到下面，这也是成员函数类外定义的主要用途之一
};

class Sniper
{
private:
    int bullets;
public:
    Sniper(int bullets = 0): bullets(bullets){}
    // friend class Supplier;
    friend bool Supplier::provide(Sniper & sniper);//友元声明，使得provide函数可以调用sniper内私有变量
};

    bool Supplier::provide(Sniper & sniper)
    {
        // bullets is a private member
        if (sniper.bullets < 20) //no enough bullets
        {
            if (this->storage > 100 )
            {
                sniper.bullets += 100;
                this->storage -= 100;
            }
            else if(this->storage > 0)
            {
                sniper.bullets += this->storage;
                this->storage = 0;
            }
            else
                return false;
        }
        cout << "sniper has " << sniper.bullets << " bullets now." << endl;
        return true;
    }

int main()
{
    Sniper sniper(2);
    Supplier supplier(2000);
    supplier.provide(sniper);
    return 0;
}