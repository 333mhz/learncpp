#ifndef SMARTPTR_H
#define SMARTPTR_H

#include "header.h"

//1
template<class CT>
class Auto_ptr1
{
    CT* m_ptr;

public:
    Auto_ptr1(CT* ptr = nullptr):m_ptr(ptr)
    {
        cout << "Auto Pointer Initialized\n";
    }

    ~Auto_ptr1()
    {
        delete m_ptr;
        cout << "Auto Pointer Destroyed\n";
    }

    CT& operator*()  const { return *m_ptr; }
    CT* operator->() const { return m_ptr; }
};

class Resource
{   
    public:
    Resource() { cout << "Resource acquired\n"; }
    ~Resource(){ cout << "Resource destroyed\n"; }
    void sayHi() { std::cout << "Hi\n"; }
};

void test010()
{
    Auto_ptr1<Resource> res1(new Resource);

    int x;
    cout << "Enter an interger: \a";
    cin >> x;
    if(x == 0)
        throw 0;
    
    res1->sayHi();
    Auto_ptr1<Resource> res2(res1); // Alternatively, don't initialize res2 and then assign res2 = res1;
}

#endif