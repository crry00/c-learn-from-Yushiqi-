#include <iostream>  
#include <vector>  
#include <utility> // 包含 std::move  
  
void transferVector(std::vector<int>& source, std::vector<int>& destination) {  
    // 使用 std::move 将 source 的内容转移到 destination 中  
    destination = std::move(source);  
  
    // 此时，source 的内容被清空（大小变为 0），因为它的资源已被移动  
    // 注意：source 仍然是一个有效的 vector，只是不再包含任何元素  
  
    // 如果需要，可以清空 source 以释放其占用的内存  
    // source.clear(); // 或者 source.shrink_to_fit();（如果需要的话）  
}  
  
int main() {  
    std::vector<int> vec1 = {1, 2, 3, 4, 5};  
    std::vector<int> vec2;  
  
    transferVector(vec1, vec2);  
  
    // 输出 vec2 的内容，验证转移是否成功  
    for (int num : vec2) {  
        std::cout << num << ' ';  
    }  
    std::cout << '\n';  
  
    // 输出 vec1 的大小，验证它是否为空  
    std::cout << "Size of vec1 after transfer: " << vec1.size() << '\n';  
  
    return 0;  
}