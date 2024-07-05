#include <iostream>

using namespace std;
int main(int argc,char ** argv)
{
    for (size_t i;i<argc;i++)
    {
        cout<<i<<":  "<<argv[i]<<endl;
    }
}
