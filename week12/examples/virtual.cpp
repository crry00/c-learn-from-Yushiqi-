#include <iostream>
#include <string>
using namespace std;

class Person
{
  public:
    string name;
    Person(string n): name(n){}
    virtual  void print()
    {
        cout << "Name: " << name << endl;
    }
};

class Person2
{
  public:
    string name;
    Person2(string n): name(n){}
    virtual void print() = 0; //pure virtual funtion,cant objector ,must be virtual derive
};

class Student: public Person
{
  public:
    string id;
    Student(string n, string i): Person(n), id(i){}
    void print() 
    {
        cout << "Name: " << name;
        cout << ". ID: " << id << endl;
    }
};

void printObjectInfo(Person & p)
{
    p.print();//will call the person funtion because no virtual
}

int main()
{
    {
        Student stu("yu", "2019");
        printObjectInfo(stu);  
    }

    {
        Person * p = new Student("xue", "2020");
        p->print(); //if print() is not a virtual function, different output
        delete p; //if its destructor is not virtual
    }

    { //if you want to call a function in the base class
        Student stu("li", "2021");
        stu.Person::print();//by this way can call base's print()

        Person * p = new Student("xue", "2020");
        p->Person::print(); //by this way can call base's print
        p->print();
        delete p; 
    }

    return 0;
}