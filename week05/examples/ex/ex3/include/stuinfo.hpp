#pragma once 

struct Stuinfo{
    char name[20];
    double score[3];
    double ave;
};

void inputStu(Stuinfo stu[],int n);

void showStu(Stuinfo stu[],int n);
