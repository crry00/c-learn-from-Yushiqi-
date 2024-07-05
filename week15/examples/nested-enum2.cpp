#include <iostream>


class Mat
{
public://内嵌在函数中，表示主要为该函数所用
    enum DataType
    {
        TYPE8U,
        TYPE8S,
        TYPE32F,
        TYPE64F
    };
private:
    DataType type;
    void * data;
public:
    Mat(DataType type) : type(type), data(NULL){}

    DataType getType() const { return type;  }
};

int main()
{
    //must call by Mat::DataType::TYPE8Ul 来访问类中的枚举变量的某个类型的值
    Mat image(Mat::DataType::TYPE8U);
    
    if (image.getType() == Mat::DataType::TYPE8U)
        std::cout << "This is an 8U matrix." << std::endl;
	else
        std::cout << "I am not an 8U matrix." << std::endl;

    return 0;
}
