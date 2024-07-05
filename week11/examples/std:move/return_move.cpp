#include <iostream>  
#include <vector>  
#include <utility> // 包含 std::move  
  
std::vector<int> createVector() {  
    std::vector<int> localVector = {1, 2, 3, 4, 5};  
    // 使用 std::move 返回 localVector，但通常编译器会进行优化，这里主要是为了说明  
    return std::move(localVector);  
    // 注意：即使不使用 std::move，现代编译器也会通过返回值优化（RVO）来避免复制  
}  
  
int main() {  
    std::vector<int> myVector = createVector();  
  
    // 输出 myVector 的内容  
    for (int num : myVector) {  
        std::cout << num << ' ';  
    }  
    std::cout << '\n';  
  
    return 0;  
}