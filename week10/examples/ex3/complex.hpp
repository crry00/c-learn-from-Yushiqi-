#pragma once

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

    //a+b
    Complex operator+(const Complex& b) const
    {
        Complex temp;
        temp.real=this->real+b.real;
        temp.virtul=this->virtul+b.virtul;
        return temp;
    }
    //a-b
    Complex operator-(const Complex& b) const
    {
        Complex temp;
        temp.real=this->real-b.real;
        temp.virtul=this->virtul-b.virtul;
        return temp;
    }
    //a+=b
    Complex& operator+=(const Complex& b)
    {
        this->real+=b.real;
        this->virtul+=b.virtul;

        return *this;
    }
    //Com+=int
    Complex& operator+=(int b)
    {
        this->real+=b;
        return *this;
    }
    
    //Com-=int
    Complex& operator-=(int b)
    {
        this->real-=b;
        return *this;
    }

    //Com+int
    Complex operator+(int b) const
    {
        Complex temp;
        temp.real=this->real+b;
        temp.virtul=this->virtul;
        return temp;
    }
    
    //Com-int
    Complex operator-(int b) const
    {
        Complex temp;
        temp.real=this->real-b;
        temp.virtul=this->virtul;
        return temp;
    }

    //int+Com
    // friend Complex operator+(int a,const Complex& b)
    // {
    //     return b+a;
    // }

    //int-Com
    friend Complex operator-(int a,const Complex& b)
    {
        return b-a;
    }

    //-=
    Complex& operator-=(const Complex& b)
    {
        this->real-=b.real;
        this->virtul-=b.virtul;
        return *this;
    }
    

    Complex operator*(const Complex& b) const
    {
        Complex temp;
        temp.real= this->real*b.real;
        temp.virtul= this->virtul*b.virtul;
        return temp;
    }//error


    
    //*2
    Complex operator*(int a) const
    {
        Complex temp;
        temp.real= this->real*a;
        temp.virtul= this->virtul*a;
        return temp;
    }

    //int * Complex
    friend Complex operator*(int a,const Complex& b)
    {
        return b*a;
    }

    //~
    Complex operator~()
    {
        Complex temp;
        temp.real=this->real;
        temp.virtul=-this->virtul;
        return temp;
    }
    //==
    bool operator==(const Complex& b) const
    {
        return (this->real==b.real)&&(this->virtul==b.virtul);
    }
    
    bool operator!=(const Complex& b) const
    {
        // return !((this->real==b.real)&&(this->virtul==b.virtul));
        return !(*this==b);
    }
    

    friend std::ostream& operator<<(std::ostream & os,const Complex & t)
    {
        std::string str=to_string(t.real)+((t.virtul>0)?" + ":" - ")+to_string(abs(t.virtul))+"i";
        os<<str;
        return os;
    }
    //friend标识在对应的类内声明即可
    friend std::istream& operator>>(std::istream & is,Complex & t)//不要+const
    {
        is >> t.real>> t.virtul;
        return is;
    }

    void display() const;
};

void Complex::display() const
{
    cout<<"ths num: "<<real<<((virtul>0)?" + ":" - ")<<abs(virtul)<<" i "<<endl;
}

    Complex operator+(int a,const Complex& b)//如果不使用内部的private，不用friend
{
    return b+a;
}




