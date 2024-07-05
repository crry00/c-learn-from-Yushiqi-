#include "add.h"

long long add(int number1, long long number2)
{
    //这里有内存高位覆盖低位，long long take 64 >int 32 ,so the temp is 64
    return number1 + number2;
}