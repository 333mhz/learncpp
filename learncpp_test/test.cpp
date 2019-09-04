#include "header.h"
#include "exception.hpp"

int main()
{
    Timer t;

    test07();

    std::cout <<std::endl << t.elapsed();

    return 0;
}
