#include <iostream>
#include <typeinfo>
using namespace std;
class Base
{
protected:
    int bvalue;
public:
    Base(int i ) : bvalue(i) {}
    virtual bool equal(const Base& b) const
    {
        if(typeid(*this)==typeid(b))
        {
            if(this->bvalue==b.bvalue)
            {
                cout<<"the two base project is equel"<<endl;
                return true;
            }
            else
            {
                cout<<"the two base project is not equel"<<endl;
                return false;
            }
        }
        else
        {
            cout<<"base::the two project has not equal type"<<endl;
            return false;
        }
    }
    friend bool operator == (const Base& a, const Base& b)//第一个参数代表==前对象
    {
        return a.equal(b);
    }
};

class Derived : public Base
{
private:
int dvalue;
public:
Derived(int a, int b):Base(a), dvalue(b){}
virtual bool equal(const Base& b) const override
{
    const Derived* tryptr=dynamic_cast<const Derived*>(&b);

            if(tryptr)
        {
            
            if((this->bvalue==tryptr->bvalue)&&(this->dvalue==tryptr->dvalue))
            {
                cout<<"the two Derive project is equel"<<endl;
                return true;
            }
            else
            {
                cout<<"the two Derive project is not equel"<<endl;
                return false;
            }
        }
        else
        {
            cout<<"Derive::the two project has not equal type"<<endl;
            return false;
        }

}
};

void process(const Base& a, const Base& b)
{
    // try
    // {
        
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    a.equal(b);
}


int main()
{
Base b1(2);
Base b2(2);
Derived d1(1,2);
Derived d2(2,2);
process(b1,b2);
process(d1,d2); 
process(b1,d1);
cout<<(b1==d2)<<endl;
return 0;
}
