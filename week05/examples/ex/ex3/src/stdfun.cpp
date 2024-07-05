#include "stuinfo.hpp"
#include <iostream>

using namespace std;

void inputStu(Stuinfo stu[],int n){
     for(size_t i=0;i<n;i++){
        cout<<"\nplease input the "<<i+1<<"student info"<<endl;
        cout<<"name: ";
        cin.getline(stu[i].name,20);
        cout<<"\nscore1: ";
        cin>>stu[i].score[0];
        cout<<"\nscore2: ";
        cin>>stu[i].score[1];
        cout<<"\nscore3: ";
        cin>>stu[i].score[2];
        cin.get();
        stu[i].ave=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
     }
}

void showStu(Stuinfo stu[] , int n){
    for(size_t i=0;i<n;i++){

        cout<<"name: "<<stu[i].name<<endl;
        
        cout<<"score1: "<<stu[i].score[0]<<endl;
        cout<<"score2: "<<stu[i].score[1]<<endl;
        cout<<"score3: "<<stu[i].score[2]<<endl;

        cout<<"ave:"<<stu[i].ave<<endl;
     }
}