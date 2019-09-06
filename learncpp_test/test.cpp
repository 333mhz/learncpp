#include "header.h"
#include "smartptr.hpp"

int main()
{
    Timer t;

    try
    {
        test010();
    }
    catch(...)
    {
        std::cerr << "Oops,unexpected error occured." << '\n';
    }
    

    std::cout <<std::endl <<"Time: "<< t.elapsed();

    return 0;
}
