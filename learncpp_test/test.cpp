#include "header.h"
#include "func_Template.hpp"

int main()
{
    Timer t;
    
    test06();

    std::cout << t.elapsed();
    return 0;
}
