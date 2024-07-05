#include <iostream>
#include <memory>

class MyTime
{
    int hours;
    int minutes;
  public:
    MyTime(): hours(0), minutes(0)//默认构造
    {
        std::cout << "Constructor MyTime()" << std::endl;
    }
    MyTime(int m): hours(0), minutes(m)
    {
        std::cout << "Constructor MyTime(int)" << std::endl;
        this->hours +=  this->minutes / 60;
        this->minutes %= 60;
    }
    MyTime(int h, int m): hours(h), minutes(m)
    {
        std::cout << "Constructor MyTime(int,int)" << std::endl;
        this->hours +=  this->minutes / 60;
        this->minutes %= 60;
    }
    ~MyTime()
    {
        std::cout << "Destructor MyTime(). Bye!" << std::endl;
    }
    MyTime operator+(int m) const
    {
        MyTime sum;
        sum.minutes = this->minutes + m;
        sum.hours = this->hours;
        sum.hours +=  sum.minutes / 60;
        sum.minutes %= 60;
        return sum;
    }
    friend std::ostream & operator<<(std::ostream & os, const MyTime & t)
    {
        std::string str = std::to_string(t.hours) + " hours and " 
                        + std::to_string(t.minutes) + " minutes.";
        os << str;
        return os;
    }
};


int main()
{
    // std::shared_ptr<MyTime> mt0 = new MyTime(0,70); //error，两边应相同
    // MyTime * mt1 = std::make_shared<MyTime>(1, 70); //error
    // {
    //     std::shared_ptr<MyTime> mt1(new MyTime(10));//调用shareptr的构造函数
    //     std::cout << *mt1 << std::endl;
    // }

    {
        std::shared_ptr<MyTime> mt1 = std::make_shared<MyTime>(1, 70);
        std::shared_ptr<MyTime> mt2 = mt1;//reference +1
        std::shared_ptr<MyTime> mt3 = mt2;

        std::cout << "mt1: " << *mt1 << std::endl;
        std::cout << "mt2: " << *mt2 << std::endl;
        std::cout << "mt3: " << *mt3 << std::endl;
        std::cout << "use_count() = " << mt2.use_count() << std::endl;//get re count

        {
            auto mt4 = mt3;
            *mt4 = *mt4 + 50;//*mt4 + 50 will construct a temp objector
            std::cout << "use_count() = " << mt3.use_count() << std::endl;
        }
        std::cout << "mt3: " << *mt3 << std::endl;
        std::cout << "use_count() = " << mt3.use_count() << std::endl;
    }//the smart ptr actully is a class!! ,when leaf the scope ,it will auto run destruct funtion
     //the destruct funtion will check re count ,if is 1 will run the real release!

    return 0;
}
