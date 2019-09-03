#include "header.h"
#include "exception.hpp"

int main()
{
    Timer t;

    test051();

    std::cout <<std::endl << t.elapsed();

    return 0;
}
