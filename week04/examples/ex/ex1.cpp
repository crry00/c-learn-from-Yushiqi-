#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int cards[4]{};
    int hands[4];
    int price[] = {3,4,5,9};
    char direction[4] {'L',82,'U',68};
    char title[] = "ChartGPT is an awesome tool.";
    cout << "sizeof(cards) = " << sizeof(cards) << ",sizeof of cards[0] = " << sizeof(cards[0]) << endl;//16,4
    cout << "sizeof(price) = " << sizeof(price) << ",sizeof of price[0] = " << sizeof(price[1]) << endl;//16,4
    cout << "sizeof(direction) = " << sizeof(direction) << ",length of direction = " << strlen(direction) << endl;//4,32
    //32 because strlen check \0 ,but this not 
    //sizeof can check all array! what 原理?
    cout << "sizeof(title) = " << sizeof(title) << ",length of title = " << strlen(title) << endl;//29,28
    return 0;
}
/*
sizeof 是 C 和 C++ 中的一个操作符，它用于获取一个对象或类型在内存中所占用的字节大小。尽管 sizeof 在使用时看起来像是一个函数调用（因为它后面跟了括号），但它实际上是一个编译时操作符，这意味着 sizeof 的结果是在编译时确定的，而不是在运行时。
sizeof 的底层原理与编译器的实现紧密相关，但我们可以从概念上理解它是如何工作的：

编译时确定：当你使用 sizeof 操作符时，编译器会在编译时计算该类型或对象的大小。这意味着它不需要任何运行时信息或对象本身的实际存在来执行此操作。
类型信息：编译器为每个类型（如 int、double、struct、class 等）维护有关其内存布局的信息。这包括类型的大小、对齐要求等。当你使用 sizeof 操作符时，编译器会查找该类型的这些信息并返回其大小。
对象大小：对于基本类型（如 int、char、float 等），编译器知道它们的确切大小（这通常取决于编译器和平台）。对于复合类型（如 struct、class、数组等），编译器会递归地计算其成员的大小，并考虑任何填充或对齐要求，以确定整个对象的大小。
对齐：内存对齐是计算机硬件为了提高访问速度而采用的一种技术。编译器会确保对象在内存中的地址满足其对齐要求。这可能会导致对象的大小大于其成员的大小之和，因为编译器可能会在成员之间插入填充字节以满足对齐要求。
静态分配：由于 sizeof 是在编译时确定的，因此它不能用于确定动态分配对象（如通过 malloc、calloc 或 new 创建的对象）的实际大小。这是因为这些对象的大小可以在运行时更改，而 sizeof 操作符只能返回类型的大小，而不是特定对象的大小。

总之，sizeof 操作符的底层原理涉及编译器如何维护和使用类型信息，以及如何在编译时计算对象的大小。由于它是编译时确定的，因此它不需要任何运行时信息或对象本身的实际存在来执行此操作。



*/