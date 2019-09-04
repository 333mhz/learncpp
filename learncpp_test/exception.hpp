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

//6
class Base6
{
public:
    Base6() {}
    virtual void print() { std::cout << "Base"; }
};
 
class Derived6: public Base6
{
public:
    Derived6() {}
    virtual void print() { std::cout << "Derived"; }
};
 
void test06()
{
    try
    {
        try
        {
            throw Derived6();
        }
        catch (Base6& b)
        {
            std::cout << "Caught Base b, which is actually a ";
            b.print();
            std::cout << "\n";
            //throw b;// b get sliced
            throw; // note: We're now rethrowing the object here
        }
    }
    catch (Base6& b)
    {
        std::cout << "Caught Base b, which is actually a ";
        b.print();
        std::cout << "\n";
    }
}

//7
class A7
{
private:
	int m_x;
public:
	A7(int x) : m_x(x)
	{
		//if (x <= 0)
		//	throw 1;
	}
};
 
class B7 : public A7
{
public:
	B7(int x) try : A7(x) // note addition of try keyword here
	{
        if (x <= 0)
			throw 1;
	}
	catch (...) // note this is at same level of indentation as the function itself
	{
                // Exceptions from member initializer list or constructor body are caught here
 
                std::cerr << "Exception caught\n";
 
                // If an exception isn't explicitly thrown here, the current exception will be implicitly rethrown
	}
};

void test07()
{
    try
	{
		B7 b(0);
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}
}

//8

#endif