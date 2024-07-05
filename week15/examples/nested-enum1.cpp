#include <iostream>


//该enum actually use by Mat only,but define in out every one can get it
enum DataType
{
    TYPE8U,
    TYPE8S,
    TYPE32F,
    TYPE64F
};//注意枚举wei{} and follow by ;
class Mat
{
private:
    DataType type;
    void * data;
public:
    Mat(DataType type) : type(type), data(NULL){}

    DataType getType() const { return type;  }
};

int main()
{
    Mat image(TYPE8U);//enum 相当于标识符

    if (image.getType() == TYPE8U)
        std::cout << "This is an 8U matrix." << std::endl;
	else
        std::cout << "I am not an 8U matrix." << std::endl;

    return 0;
}
