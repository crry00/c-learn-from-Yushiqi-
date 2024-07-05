#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
public:
    Person(string name=""):name(name){};
    virtual ~Person(){}
    virtual string getInfo() const {return name;}
};

class Student: public Person
{
    string studentid;
public:
    Student(string name="", string sid=""):Person(name),studentid(sid){};//先调用基类构造函数，再调用子类附加元素
    string getInfo() const override {return name+":("+studentid + ")";}
};
//注意rtti是在运行时对指针和引用进行检查的机制
int main()
{
    Person person("Yu");
    Student student("Sam", "20210212");
    Person* pp = &student;//允许 Student 类包含Person类，从内存角度理解，student的内存包含person的内存，可以向下转换
    Person& rp = student;//允许 向下转换
    Student * ps = (Student*)&person; // danger! 向上，会内存越界，未定义行为
    cout << "person.getInfo():" << person.getInfo() << endl;//都是call person‘s funtion，unless use Virtual
    cout << "pp->getInfo():" << pp->getInfo() << endl;//if virtual+override ,it will call student
    cout << "rp.getInfo():" <<rp.getInfo() << endl;
    cout << "ps->getInfo():" << ps->getInfo() << endl; // danger if getInfo is not virtual

    char * p = (char*) 100;
    ps = dynamic_cast<Student*>(&person);//动态类型转换，注意只能用在多态，即显示指定virtual的类，可以安全的向上转移
    printf("address = %p\n", ps);//如果是danger的向下转移，会返回null
    pp = dynamic_cast<Person*>(&student);//注意！dynamic的《》中只能存放指针，不像static—cast可以是其他变量
    printf("address = %p\n", pp);//成功！返回指针，事实上这里只是作了动态的类型检查，会增加开销？
    //如果不确定一个对象是父类还是子类，可以用——dynamic—cast判断
    /*
    class B { ... };
    class D : public B { ... };
    void f()
    {
    B* pb = new D;
    B* pb2 = new B;
    D* pd = dynamic_cast<D*>(pb); // ok: pb points to D because the pb actually is a D
                                //the dynamic will check the memory if really you call
    ...
    D* pd2 = dynamic_cast<D*>(pb2); // fail,pb2 points to B not D
    // pd2 is NULL
    ...
    }
    
    */


    person=static_cast<Person>(student);//会创建一个副本，包含了student类内部的person部分，如果是虚函数则是调用目标类即person类的，
    cout<<person.getInfo()<<endl;//static_cast base to derive must be check safe
    return 0;
}