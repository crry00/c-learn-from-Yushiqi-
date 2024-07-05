#include <iostream>
//#define NDEBUG//before <cassert> that it will really work!!

#include <cassert>

//if define this ,assert will no work,but the define is after #include <cassert>
//in <cassert>,it has allready define it ,istoo late!!
//#define NDEBUG

int main(int argc, char ** argv)//the ./a.out is one param
{
    assert( argc == 2);
    std::cout << "This is an assert example." << std::endl;
    return 0;
}

//fianaly you can by compile follwed by -DNDEBUG to solve it