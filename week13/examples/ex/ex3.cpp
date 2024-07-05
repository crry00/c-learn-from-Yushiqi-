#include <iostream>
#include <string>
using namespace std;
template <class T1,class T2>
class Pair
{
public:
    T1 key; 
    T2 value; 
    Pair(T1 k,T2 v):key(k),value(v) { };
    bool operator < (const Pair<T1,T2> & p) const;
    
    friend ostream& operator<<(ostream& os,const Pair<T1,T2>& b)
    {
        os<<b.key<<"  "+to_string(b.value)<<endl;
        return os;
    }
};

template <class T1,class T2>
bool Pair<T1,T2>::operator < (const Pair<T1,T2> & p) const
{
    return bool(value<p.value);
}

int main()
{

Pair<string,int> one("Tom",19); 
Pair<string,int> two("Alice",20);

if(one < two)
    cout << one;
else
    cout << two;
return 0;
}
