#include <iostream>
#include <vector>



int main(){
    std::vector<int> v={1,2,3,4,5};

    std::cout<<v[10]<<std::endl;

    try{
        int c=v.at(10);
    }   catch (const std::out_of_range& e){
        std::cout<<"Out of range error:"<<e.what()<<std::endl;
    }

    return 0;
}