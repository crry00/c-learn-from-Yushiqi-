#include <iostream>
using namespace std;
class Storage
{
public: 
    class Fruit//内嵌类
    {
        string name;
        int weight;
    public:
        Fruit(string name="", int weight=0):name(name), weight(weight){}
        string getInfo(){return name + ", weight " + to_string(weight) + "kg.";}
    };
private:
    Fruit fruit;
public:
    Storage()=delete;
    Storage(Fruit f)
    {
        this->fruit = f;
    }
    void print()
    {
        cout << fruit.getInfo() << endl;
    }

};

int main()
{
    Storage::Fruit apple("apple", 100);//内嵌类不用实例化也能调用，和static有点像
    Storage mystorage(apple);
    //Storage my(); //这个被解析为函数声明
    Storage my; //这才是正确操作！！
    mystorage.print();
    return 0;
}