#include "header.h"
#include "IOstream.hpp"

int main()
{
    Timer t;

    try
    {

        test180301();
            
    }
    catch(...)
    {
        std::cerr << "Oops,unexpected error occured." << '\n';
    }
    

    std::cout <<std::endl <<"Time: "<< t.elapsed();

    return 0;
}
