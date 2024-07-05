//this is is a two int mul pro
#include<iostream>
#include<cstdlib>
using namespace std;
//templet?
class Mul
{
private:
    int a;
    int b;
    Mul(int a,int b):a(a),b(b){}
    int64_t mul() const //not good
    {
        return a*b;
    }
public:
    friend ostream& operator<<(ostream& os,const Mul& t) //声明const后不能调用t类的非const函数
    {
        os<<to_string(t.a)+" * "+to_string(t.b)+"= "+to_string(t.mul())<<endl;
        return os;
    }
    static bool action()
    {

        int tmpa,tmpb;
        try
        {
            if(!(cin>>tmpa>>tmpb))
            {
                throw 1;
            }
            cout<<Mul(tmpa,tmpb);
            return true;
        }
        catch(const int& e)
        {
            cerr<<"Please input two integers"<<endl;
            return false;
        }
    }
};

int main()
{
    while (true)
    {
        cout<<"please input two integer"<<endl;
        
        if(Mul::action())
            break;
    }
    return 0;
}