#include <iostream>
#include "add.h"

using namespace std;
int main()
{
    long long num1 =2147483647;
    long long num2 =1;
    long long result =0;

    result = add(num1, num2);

    cout << "The result is " << result << endl;
    return 0;
}
// num1 被赋值为 2147483647，这是 int 类型能表示的最大值。当你尝试将这个数与 1 相加时，
// 结果应该是 2147483648，但是这个值超出了 int 类型能表示的范围。因此，结果会回绕（wrap around）
// 到 int 类型能表示的最小值，即 -2147483648。