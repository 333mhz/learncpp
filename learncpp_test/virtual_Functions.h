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

#endif