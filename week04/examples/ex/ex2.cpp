#include <stdio.h>
union data{
    int n;
    char ch;
    short m;
};
int main()
{
    union data a;
    printf("%d, %d\n", sizeof(a), sizeof(union data) );//4
    a.n = 0x40;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.ch = 0x59;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.m = 0x2059;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    a.n = 0x3E25AD54;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);
    return 0;
//one int take 2 0xnumber 
}


