#include "header.h"
#include "inheritance.h"

int main()
{
    // Create a new BaseballPlayer object

    BaseballPlayer joe;

    // Assign it a name (we can do this directly because m_name is public)

    joe.m_name = "Joe";

    // Print out the name

    std::cout << joe.getName() << '\n'; 
	// use the getName() function we've acquired from the Person base class
	return 0;
}