#include <iostream>
#include <string>
using namespace std;

class OutOfRangeException: public exception
{
public:
    const size_t id;
    const int errnum;
    OutOfRangeException(const size_t id, int& errn ) :id(id+1),errnum(errn){}
    virtual const int What() const noexcept 
    { 
        return errnum;
    }
};

float calculateAverage(int grades[])//int* grades is okay
{
    float sum=0;
    for (size_t i=0;i<4;i++)
    {
        try{
            if((grades[i]>100)||(grades[i]<0))
            {
                throw OutOfRangeException(i,grades[i]);
            }
            sum+=grades[i];
        }
        catch(const OutOfRangeException& wrong)
        {
            cerr<<"The parameter "+to_string(wrong.id)+" is "<<wrong.What()<<"which out of range (0-100)."<<endl;
            throw;
        }
    }
    return sum/4;
}

int main()
{
    int grades[4]{0};
    cout<<"Please enter marks for 4 crouse :";
    while (cin>>grades[0]>>grades[1]>>grades[2]>>grades[4])
    {
        float result=0;
        try{
            result=calculateAverage(grades);
             cout<<"the acerage marks is "<<result<<endl;
        }
        catch(...)
        {
            
        }
    }
    std::cout << "Bye!" << std::endl;
    return 0;
    
    cout<<endl;
    
}