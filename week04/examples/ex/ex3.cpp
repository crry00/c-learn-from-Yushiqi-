#include <iostream>
using namespace std;
enum class Day{Sunday,Monday,Tuseday,Wed,Thu,Fri,Sat};//强枚举
enum class Weather{Sunny,Rainy,Cloud};

struct Dayinfo{
    Day day;
    Weather weather;  
    //Dayinfo()=default;
    Dayinfo(const Day& da,const Weather& we )
        :day(da),weather(we){};
    Dayinfo(Day&& da,Weather&& we)
        :day(std::move(da)),weather(std::move(we)){}
};

bool canTravel(const Dayinfo& info){
    return (static_cast<int>(info.day)==0||info.day==Day::Sat)&&info.weather==Weather::Sunny;
}

int main(){
    Dayinfo today(Day::Sunday,Weather::Sunny);//Day::Sunday是左值
    // Dayinfo someday;
    cout<<static_cast<int>(someday.day)<<"   "<<static_cast<int>(someday.weather)<<endl;
    if(canTravel(today)){
        cout<<"Let's go!!"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}