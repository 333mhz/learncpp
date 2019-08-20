#ifndef VIRTUALFUNC_H
#define VIRTUALFUNC_H

#include "header.h"

class Animal
{
protected:
    std::string m_name;
    const string m_speak;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(const std::string &name)
        : m_name(name)
    {
    }

    Animal(const Animal&) = delete;// prevent shallow copies
    Animal& operator=(const Animal&) = delete;// prevent shallow copies
 
public:
    const std::string& getName() { return m_name; }
    virtual const string speak() { return m_speak; }
};

class Cat:public Animal
{
public:
    Cat(const string &n):Animal(n)
    {}

    virtual const string speak() { return "vMeow"; }
};

class Dog: public Animal
{
public:
    Dog(const string &name)
        : Animal(name)
    {
    }
    virtual const string speak() { return "vWoam"; }
};

void furry()
{
    
    Cat fred("Fred"), misty("Misty"), zeke("Zeke");
    Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");
 
    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    Animal *animals[] = { &fred, &garbo, &misty, &pooky, &truffle, &zeke };
    for (auto animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
}
//override  ,   final   ,   

class covariantReturnTypes
{
public:
	// This version of getThis() returns a pointer to a Base class
	virtual covariantReturnTypes* getThis() { std::cout << "called Base::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Base\n"; }
};
 
class covariantReturnTypesD : public covariantReturnTypes
{
public:
	// Normally override functions have to return objects of the same type as the base function
	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
	virtual covariantReturnTypesD* getThis() { std::cout << "called Derived::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Derived\n"; }
};
#endif