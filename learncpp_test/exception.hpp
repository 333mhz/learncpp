#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "header.h"

//2
double mySqrt(double x)
{
    // If the user entered a negative number, this is an error condition
    if (x < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type const char*

    return sqrt(x);
}

void test02()
{
    std::cout << "Enter a number: \a";
    double x;
    std::cin >> x;
    try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        double d = mySqrt(x);
        std::cout << "The sqrt of " << x << " is " << d << '\n';
    }
    catch (const char* exception) // catch exceptions of type const char*
    {
        std::cerr << "Error: " << exception << std::endl;
    }
}

//3

void last() // called by third()
{
    std::cout << "Start last\n";
    std::cout << "last throwing int exception\n";
    throw -1;
    std::cout << "End last\n";
}
void third() // called by second()

{
    std::cout << "Start third\n";
    last();
    std::cout << "End third\n";
}
void second() // called by first()
{
    std::cout << "Start second\n";
    try
    {
        third();
    }
    catch(double)
    {
         std::cerr << "second caught double exception\n";
    }
    std::cout << "End second\n";
}

void first() // called by main()

{
    std::cout << "Start first\n";
    try
    {
        second();
    }
    catch (int)
    {
         std::cerr << "first caught int exception\n";
    }
    catch (double)
    {
         std::cerr << "first caught double exception\n";
    }
    std::cout << "End first\n";
}

void test03()
{
    std::cout << "Start main\n";

    try
    {
        first();
    }

    catch (int)
    {
         std::cerr << "main caught int exception\n";
    }
    std::cout << "End main\n";
}

//5
void test05()
{
    try
	{
		// Your code using standard library goes here
		// We'll trigger one of these exceptions intentionally for the sake of example
                std::string s;
                s.resize(-1); // will trigger a std::bad_alloc
                cout << s.size();
	}
	// This handler will catch std::exception and all the derived exceptions too
	catch (std::exception &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << '\n';
	}
}

void test051()
{
    try
	{
		throw std::runtime_error("Bad things happened");
	}
	// This handler will catch std::exception and all the derived exceptions too
	catch (std::exception &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << '\n';
	}
}

void test052()
{
    
}
#endif