在C++中，`typeid`操作符和`type_info`类被用于在运行时获取对象的类型信息。然而，`typeid`操作符在用于多态类型（即包含至少一个虚函数的类）的指针或引用时，其行为与非多态类型有所不同。

对于您的代码示例：

```cpp
class Base { ... }; // 假设这里至少有一个虚函数，否则Derived不是多态的
class Derived : public Base { ... };
Derived *dp = new Derived;
Base *bp = dp; 

// compare the type of two objects at run time
if (typeid(*bp) == typeid(*dp))
{
    // 这里不会执行，因为typeid(*bp)返回的是Base的type_info，而typeid(*dp)返回的是Derived的type_info
    // 除非Base没有虚函数，但这样Derived就不是多态的，上面的代码逻辑也就不适用于多态场景
}

// test whether the run-time type is a specific type
if (typeid(*bp) == typeid(Derived)) 
{
    // 如果Base有虚函数，并且dp确实指向了一个Derived对象，那么这里会执行
    // 因为通过基类指针bp进行解引用时，typeid会返回对象的实际类型（Derived）的type_info
}
```

**重要点**：

1. **多态与`typeid`**：当`typeid`用于多态类型的指针或引用时，它会返回对象的实际类型（即动态类型）的`type_info`对象。这要求基类至少有一个虚函数。

2. **`typeid(*bp) == typeid(*dp)`**：这个比较通常不会为真，因为`*bp`被解释为`Base`类型的对象（尽管它实际上是一个`Derived`对象），而`*dp`是`Derived`类型的对象。在多态情况下，`typeid(*bp)`会返回`Base`的`type_info`，而`typeid(*dp)`会返回`Derived`的`type_info`。

3. **`typeid(*bp) == typeid(Derived)`**：这个比较在`Base`有虚函数且`dp`确实指向了一个`Derived`对象时会为真。因为通过基类指针`bp`进行解引用时，`typeid`能够识别出对象的实际类型是`Derived`。

4. **如果Base没有虚函数**：那么`Derived`就不是多态的，`typeid(*bp)`和`typeid(*dp)`都会返回它们各自的静态类型（即`Base`和`Derived`）的`type_info`，此时`typeid(*bp) == typeid(*dp)`的比较结果将取决于`Base`和`Derived`是否实际上是相同的类型（在这个例子中，它们不是）。

因此，为了使您的代码按预期工作，并确保`Derived`是多态的，`Base`类中应该至少有一个虚函数（通常是虚析构函数，以支持通过基类指针安全地删除派生类对象）。