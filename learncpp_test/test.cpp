#include "header.h"
#include "inheritance.h"

int main()
{
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a;
 
	const Banana b("Cavendish", "yellow");
	std::cout << b;

    return 0;
}