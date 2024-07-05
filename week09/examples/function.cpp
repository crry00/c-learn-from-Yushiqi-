#include <iostream>
#include <cstring>

class Student
{
  private:
    char name[4];
    int born;
    bool male; 
  public:
    void setName(const char * s)//默认inline函数
    {
        if (s == NULL)
        {
            std::cerr << "The input is NULL." << std::endl;
            return;
        }
        size_t len = sizeof(name) - 1;
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
    // the declarations, the definitions are out of the class
    void setGender(bool isMale);
    void printInfo();
};

inline void Student::setGender(bool isMale)//inline 函数，建议简单实现用inline，复杂实现不用
{
    male = isMale;
}
void Student::printInfo()//非inline函数
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Born in " << born << std::endl;
    std::cout << "Gender: " << (male ? "Male" : "Female") << std::endl;
}

int main()
{
    Student yu;
    yu.setName("Yu");
    yu.setBorn(2000);
    yu.setGender(true);
    yu.printInfo();
    return 0;
}