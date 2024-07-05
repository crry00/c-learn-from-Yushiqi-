#include <iostream>
#include <chrono>
using namespace std;

struct Timer
{
    std::chrono::time_point<std::chrono::system_clock> start,end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start=std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end=std::chrono::high_resolution_clock::now();
        duration=end -start;
        std::cout<<"Timer : "<<duration.count()<<"s\n";
    }
};


int main()
{
    bool isPositive = true;
    int factor = 0;
    //some operations may change isPositive's value
    if(isPositive)
        factor = 1;
    else
        factor = -1;
    //the if-else statement can be replaced by a ternary conditional operation
    {
    cout<<"time1"<<endl;
    Timer time1;
    factor = isPositive ? 1 : -1;
    }
    //sometimes the following code can be more efficient.
    {
    cout<<"time2"<<endl;
    Timer time2;
    factor = isPositive * 2 - 1;
    }
    return 0;
}