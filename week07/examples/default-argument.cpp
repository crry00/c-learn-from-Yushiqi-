#include <iostream>
#include <cmath>
using namespace std;
//!! (float x) is argument,(float x=0)is a paramter,but they all call 参数
float norm(float x, float y, float z);
float norm(float x, float y, float z = 0);//状态叠加，默认参数从后往前加
float norm(float x, float y = 0, float z);

int main()
{
    cout << norm(3.0f) << endl;
    cout << norm(3.0f, 4.0f) << endl;
    cout << norm(3.0f, 4.0f, 5.0f) << endl;
    return 0;
}

float norm(float x, float y, float z)
{
    return sqrt(x * x + y * y + z * z);
}

// 