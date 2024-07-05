#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int virtul;
public:
    Complex():real(0),virtul(0){}
    Complex(int a,int b):real(a),virtul(b){}
    Complex(const Complex & other){ this->real=other.real;this->virtul=other.virtul; }

    void add(const Complex& other){
        this->real+=other.real;
        this->virtul+=other.virtul;
        cout<<"add finish!"<<endl;
    }
    
    void sub(const Complex& other){
        this->real-=other.real;
        this->virtul-=other.virtul;
        cout<<"sub finish!"<<endl;
    }

    void display() const;
};

void Complex::display() const
{
    cout<<"ths num: "<<real<<((virtul>0)?" + ":" - ")<<abs(virtul)<<" i "<<endl;
}


int main()
{
    Complex a(2,3),b{-2,-1};//()调用构造函数,{}C++11定义初始化
    a.display();
    a.add(b);
    a.display();

}

