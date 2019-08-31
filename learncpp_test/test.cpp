#include "header.h"
#include "func_Template.hpp"

int main()
{
    Timer t;
    
    StaticArray<int, 4> int4;
	int4[0] = 0;
	int4[1] = 1;
	int4[2] = 2;
	int4[3] = 3;
 
	// Print the array
	prt(int4);

    std::cout <<endl << t.elapsed();
    return 0;
}
