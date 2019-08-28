#include "header.h"
#include "func_Template.hpp"

int main()
{
    Timer t;
    
    Cents array3[] = { Cents(5), Cents(10), Cents(15), Cents(14) };
    cout << taverage(array3,4)<<endl;

    std::cout << t.elapsed();
    return 0;
}
