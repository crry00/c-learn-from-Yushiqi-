#pragma once
#include <iostream>
#include <memory>

using namespace std;

class Matrix
{
private:
    int row;//应改为size——t
    int cow;
    shared_ptr<float[]> data;
public: 
    Matrix():row(0),cow(0),data(nullptr){}

    Matrix(int row,int cow)
    {
        this->row=row;
        this->cow=cow;
        //data=make_shared<float[]>(cow*row);//??
        data=shared_ptr<float[]>(new float[row*cow]{0});
    }
    Matrix(const Matrix& other)
    {
        this->row=other.row;
        this->cow=other.cow;
        this->data=other.data;
    }

    Matrix& operator=(const Matrix& other)
    {
        this->row=other.row;
        this->cow=other.cow;
        this->data=other.data;
        return *this;

    }
    Matrix operator+(const Matrix& other)
    {
        if((this->cow!=other.cow)&&(this->row!=other.row))
        {
            cerr<<"the cow or row is not match!"<<endl;
            Matrix error;
            return error;
        }
        Matrix temp(this->row,this->cow);
        for(size_t i=0;i<cow*row;i++)
        {
            temp.data[i]=this->data[i]+other.data[i];
        }
        return temp;//返回前拷贝但智能指针！！
    }

    float& operator[](size_t composition) {return this->data[composition]; }
    const float operator[](size_t composition) const { return this->data[composition];}

    //如果不要friend，需在类外定义，且不能使用类内保护变量函数
    friend ostream& operator<<(ostream& os,const Matrix& t)
    { 
        if(t.data==nullptr)
        {
            cerr<<"the Matric data is not init!!";
            return os;
        }

        string str("\n");
        for(size_t i=0;i<t.row;i++)
        {
            
            for(size_t j=0;j<t.cow;j++)
            {
                str+=to_string(t.data[i*t.cow+j]);
                str+=" ";//os<<t.data
            }
            str+="\n";
        }
        os<<str;
        return os;
    }


};


