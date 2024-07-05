#include <stdio.h>

void div2(int n)
{
    if( n % 2 != 0)
    {
        fprintf(stderr, "Error: The input must be an even number. Here it's %d\n", n);
    }
    else
    {
        int result = n / 2;
        fprintf(stdout, "Info: The result is %d\n", result);
    }
    return;
}

int main()
{
    for(int n = -5; n <= 5; n++)
        div2(n);
    return 0;
}
//less 查看程序内容
//stdout 会重定向管道，如./a.out |less
//but stderr will not to pipe ,it will still in terminal

//./a.out > output.log  //override
//./a.out 1> output.log
//./a.out >> output.log  //follow
//./a.out 2> error.log
//./a.out 1> output.log 2> error.log
//./a.out 1>> output.log 2>> error.log
//./a.out   &> all.log




