#include <stdio.h>
int main()
{
signed char a = 127;
unsigned char b = 0xff;
unsigned char c = 0;
a++;//环绕+1变成-128
b++;//环绕变成0
c--;//环绕变成255
printf("a=%d\nb=%d\nc=%d\n",a,b,c);
return 0;
}
