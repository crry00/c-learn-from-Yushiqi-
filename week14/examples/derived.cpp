#include <iostream>

class Base
{
public:
    Base() {}
};

class Derived: public Base
{
public:
    Derived() {}
};

int main()
{
    try
    {
        throw Derived();//throw Derived objector as exception!!
    }
    catch (const Base& base)
    {
        std::cerr << "I caught Base." << std::endl;
    }
    catch (const Derived& derived) 
    { // never reach here
        std::cerr << "I caught Derived." << std::endl;
    }

    return 0;
}

//void fun() noexcept;保证不会有异常