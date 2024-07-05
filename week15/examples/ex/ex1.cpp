#include<iostream>

using namespace std;

class Car
{
private:
    enum Mode {Off, On}; //Off- non automatically drive, On-automatically drive
    enum {Minvel, Maxvel = 200}; //range of velocity from 0 to 200
    Mode mode; //mode of car, Off or On
    int velocity;
public:
    friend class Driver;//友元声明
    Car(Car::Mode m = On, int v = 50):mode(m),velocity(v){ }
    bool velup(int v)
    {
        if(v<Minvel||v>Maxvel)
        {
            cout<<"the input vel "+to_string(v)+" is out of range(0-200)!"<<endl;
            return false;
        }
        if(!this->mode)
        {
            cout<<"the auto mode is off"<<endl;
            return false;
        }
        cout<<"increase vel by car"<<endl;
        return bool(this->velocity=v);
    } //increase velocity by v
    bool veldown(int v)
    {
        if(v<Minvel||v>Maxvel)
        {
            cout<<"the input vel "+to_string(v)+" is out of range(0-200)!"<<endl;
            return false;
        }
        if(!this->mode)
        {
            cout<<"the auto mode is off"<<endl;
            return false;
        }
        cout<<"decreace by car"<<endl;
        return bool(this->velocity=v);

    } //decrease velocity by v
    bool ison() const
    {
        return mode;
    } //Check whether the mode is on 
    int getvel() const
    {
        return velocity;
    } //get the velocity
    void showinfo() const
    {
        cout<<"the mode is "<<(mode?On:Off)<<"  the Vel is "<<to_string(velocity)<<endl;
    } // show the mode and velocity of car
};

class Driver
{
public:
    bool velup(Car& car,int v)const
    {
        if(v<Car::Minvel||v>Car::Maxvel) 
        {
            cout<<"the input vel "+to_string(v)+" is out of range(0-200)!"<<endl;
            return false;
        }
        cout<<"increase by human"<<endl;
        return bool(car.velocity=v);
    } //increase velocity by v
    bool veldown(Car& car, int v) const
    {
        if(v<Car::Minvel||v>Car::Maxvel)
        {
            cout<<"the input vel "+to_string(v)+" is out of range(0-200)!"<<endl;
            return false;
        }
        cout<<"decreace by human"<<endl;
        return bool(car.velocity=v);

    } //decrease velocity by v
    void setmode(Car& car) const
    {
        car.mode=Car::Mode(~car.mode);//使用类型强转
    } //If the mode is On, set it to Off,otherwise set it to Off
    bool ison(Car& car) const
    {
        return car.mode;//隐式类型强转
    } //Check whether the mode is on 
};


