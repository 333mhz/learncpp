

#include "header.h"
#include "func_Template.hpp"

int main()
{
    Timer t;
    test08();
    
    std::cout <<std::endl << t.elapsed();
    return 0;
}
