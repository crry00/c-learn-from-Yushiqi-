#include <iostream>
using namespace std;
class Polygon 
{
protected:
int width, height;
public:
void set_values (int a, int b)
{ width=a; height=b; }
virtual int area()=0;
// { return 0;}
};

class Rectangle: public Polygon 
{
public:
int area()
{ return width * height; }
};
class Triangle: public Polygon 
{
public:
int area()
{ return width*height/2; }
};

int main () 
{
Rectangle rect;
Triangle trgl;
Polygon * ppoly1 = &rect;
Polygon * ppoly2 = &trgl;
ppoly1->set_values (4,5);
ppoly2->set_values (2,5);
cout << rect.area() << endl;
cout << trgl.area() << endl;
cout << ppoly1->area() << endl;
cout << ppoly2->area() << endl;
return 0;
}

/*
Derived d;  
    cout << "Derived's value: " << d.value << endl; // 输出 Derived 的 value，即 20  
    cout << "Base's value in Derived: " << d.Base::value << endl; // 输出 Base 的 value，即 10  
    return 0;  
}
若基类和子类有同样的成员，子雷可以通过d.value get but base value should by d.base::value get
*/



