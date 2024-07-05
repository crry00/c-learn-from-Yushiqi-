#include <iostream>
using namespace std;

union ipv4address{
    std::uint32_t address32;
    std::uint8_t address8[4];
};
union myaddress{
    std::uint16_t address16;
    std::uint8_t    address8[2];
};

int main()
{
    union ipv4address ip;
    union myaddress mp;
    cout << "sizeof(ip) = " << sizeof(ip) << endl;
    cout << "sizeof(mp) = " << sizeof(mp)  << endl;

    ip.address8[3] = 127;
    ip.address8[2] = 0;
    ip.address8[1] = 0;
    ip.address8[0] = 1;

    cout << "The address is " ;
    cout << +ip.address8[3] << ".";
    cout << +ip.address8[2] << ".";
    cout << static_cast<int>(ip.address8[1]) << ".";
    cout << +ip.address8[0] << endl;

    cout << std::hex;
    cout << "in hex " << ip.address32 << endl;
    cout << std::hex;
    cout<<"in oct"<<+ip.address8[3]<<"?"<<endl;//if no +,will display as char ,not num!!
    return 0;
}
