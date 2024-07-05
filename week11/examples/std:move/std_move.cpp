#include <iostream>  
#include <vector>  
#include <utility> // 包含 std::move  
  
int main() {  
    std::vector<int> vec1 = {1, 2, 3, 4, 5};  
    std::vector<int> vec2;  
  
    // 使用 std::move 将 vec1 的内容转移到 vec2 中  
    vec2 = std::move(vec1);  
  
    // 此时，vec1 的内容是未定义的，但 vec2 包含了 vec1 的原始内容  
    // 尝试访问 vec1 的内容可能会导致未定义行为  
  
    // 输出 vec2 的内容，验证转移是否成功  
    for (int num : vec2) {  
        std::cout << num << ' ';  
    }  
  
    return 0;  
}
//ptrHardCopy(const string& s=string())