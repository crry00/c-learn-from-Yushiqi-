#include <iostream>
#include <cstring>//strncpy等c语言字符串操作


//类比struct更安全
class Student
{
  public:
    char name[4];
    int born;
    bool male; 
    void setName(const char * s)
    {
        if (s == NULL)
        {
            std::cerr << "The input is NULL." << std::endl;
            return;
        }
        size_t len = sizeof(name) - 1;//只有3个字符留给name，有一个\0
        strncpy(name, s, len);
        name[len] = '\0';
    }
    void setBorn(int b)
    {
        if (b >= 1990 && b <= 2020 )
            born = b;
        else
            std::cerr << "The input b is " << b << ", and should be in [1990, 2020]." << std::endl;
    }
    void setGender(bool isMale)
    {
        male = isMale;
    }
    void printInfo()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Born in " << born << std::endl;
        std::cout << "Gender: " << (male ? "Male" : "Female") << std::endl;
    }
};

int main()
{
    Student yu;
    yu.setName("Yu");
    yu.setBorn(2000);
    yu.setGender(true);
    yu.born = 2001; // it can also be manipulated directly,because not set private 
    yu.printInfo();
    std::cout << "It's name is " << yu.name << std::endl; 
    return 0;
}