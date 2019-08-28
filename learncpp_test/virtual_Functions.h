#ifndef VIRTUALFUNC_H
#define VIRTUALFUNC_H

#include "header.h"

//  Virtual functions and polymorphism
class Animal//abstract
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
    virtual const string speak()=0;
};

const string Animal::speak()  // even though it has a body
{
    return "???";
}

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
    //virtual const string speak() { return "vWoam"; }
    virtual const string speak() { return Animal::speak(); }
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

//  Covariant Return Types C++11
class CRTBase
{
public:
	// This version of getThis() returns a pointer to a Base class
	virtual CRTBase* getThis() { std::cout << "called Base::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Base\n"; }
};
 
class CRTDrerived final: public CRTBase
{
public:
	// Normally override functions have to return objects of the same type as the base function
	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
	virtual CRTDrerived* getThis() { std::cout << "called Derived::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Derived\n"; }
};

//  Virtual destructors, virtual assignment, and overriding virtualization

class VDBase
{
public:
    virtual ~VDBase() // note: virtual
    {
        std::cout << "Calling ~Base()" << std::endl;
    }
};
 
class VDDerived: public VDBase
{
private:
    int* m_array;
 
public:
    VDDerived(int length)
    {
        m_array = new int[length];
    }
 
    virtual ~VDDerived() // note: virtual
    {
        std::cout << "Calling ~Derived()" << std::endl;
        delete[] m_array;
    }
};

//  Ignoring virtualization
class IVBase
{
public:
    virtual const char* getName() { return "Base"; }
};
 
class IVDerived: public IVBase
{
public:
    virtual const char* getName() { return "Derived"; }
};

    
int add(int x, int y)
    {
    return x + y;
    }
 
    int subtract(int x, int y)
    {
    return x - y;
    }
 
    int multiply(int x, int y)
    {
    return x * y;
    }

class lBind
{
    protected:
    // Create a function pointer named pFcn (yes, the syntax is ugly)
    int (*pFcn)(int, int) = nullptr;

    int m_x;
    int m_y;
    int m_o;
    
    public:
    lBind()
    {}

    void setX(int x)
    { m_x = x;  }

    void setY(int y)
    { m_y = y;  }

    void calc(int o)
    {
        switch(o)
        {
            case 0 : pFcn = add;break;
            case 1 : pFcn = subtract;break;
            case 2 : pFcn = multiply;break;
        }
        cout << (*pFcn)(m_x,m_y) << endl;
    }

};

//  The virtual table 

class VTBase
{
public:
    //FunctionPointer *__vptr;
    //The compiler also adds a hidden pointer to the most base class that uses virtual functions. 
    virtual void function1() {};
    virtual void function2() {};
};
 
class VTD1: public VTBase
{
public:
    virtual void function1() {};
};
 
class VTD2: public VTBase
{
public:
    virtual void function2() {};
};

//  Pure virtual functions

class IErrorLog//interface
{
    public:
    virtual bool openLog(const char* filename) = 0;
    virtual bool closeLog() = 0;
    virtual bool writeErr(const char* errMsg) = 0;

    virtual ~IErrorLog(){}  
};

// object slicing

class sBase
{
protected:
    int m_value;
 
public:
    sBase(int value)
        : m_value(value)
    {
    }
 
    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};
 
class sDerived: public sBase
{
public:
    sDerived(int value)
        : sBase(value)
    {
    }
 
    virtual const char* getName() const { return "Derived"; }
};

void objslc01()
{
    sDerived derived(5);
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
 
    sBase &ref = derived;
    std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';
 
    sBase *ptr = &derived;
    std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';
}

void objslc02()
{
    sDerived derived(5);
    sBase base = derived; // what happens here?
    std::cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';
}

void prtObjSlc(const sBase &base) // note: base now passed by reference
{
    std::cout << "I am a " << base.getName() << '\n';
}

void objslc03()
{
    std::vector<sBase*> v;
	
	sBase b(5); // b and d can't be anonymous objects
	sDerived d(6);
 
	v.push_back(&b); // add a Base object to our vector
	v.push_back(&d); // add a Derived object to our vector
 
		// Print out all of the elements in our vector
	for (int count = 0; count < v.size(); ++count)
		std::cout << "I am a " << v[count]->getName() << " with value " << v[count]->getValue() << "\n";
 
	for (int count = 0; count < v.size(); ++count)
		delete v[count];
} 

void objslc04()
{
    std::vector<std::reference_wrapper<sBase> > v; // our vector is a vector of std::reference_wrapper wrapped Base (not Base&)
	sBase b(5); // b and d can't be anonymous objects
	sDerived d(6);
	v.push_back(b); // add a Base object to our vector
	v.push_back(d); // add a Derived object to our vector
 
	// Print out all of the elements in our vector
	for (int count = 0; count < v.size(); ++count)
		std::cout << "I am a " << v[count].get().getName() << " with value " << v[count].get().getValue() << "\n"; // we use .get() to get our element from the wrapper
}

//Dynamic casting

enum ClassID
{
	BASE,
	DERIVED
	// Others can be added here later
};
 
class dBase
{
protected:
	int m_value;
 
public:
	dBase(int value)
		: m_value(value)
	{
	}
 
	virtual ~dBase() {}
	virtual ClassID getClassID() { return BASE; }
};
 
class dDerived : public dBase
{
protected:
	std::string m_name;
 
public:
	dDerived(int value, std::string name)
		: dBase(value), m_name(name)
	{
	}
 
	std::string& getName() { return m_name; }
	virtual ClassID getClassID() { return DERIVED; }
 
};
 
dBase* getObject(bool bReturnDerived)
{
	if (bReturnDerived)
		return new dDerived(1, "Apple");
	else
		return new dBase(2);
}

void dyncast00()
{
    dBase *b = getObject(true);
 
        dDerived *d = dynamic_cast<dDerived*>(b); // use dynamic cast to convert Base pointer into Derived pointer
 
        std::cout << "The name of the Derived is: " << d->getName() << '\n';
 
	delete b;
}

void dyncast01()
{
    dBase *b = getObject(true);
 
	if (b->getClassID() == DERIVED)
	{
		// We already proved b is pointing to a Derived object, so this should always succeed
		dDerived *d = static_cast<dDerived*>(b);
		std::cout << "The name of the Derived is: " << d->getName() << '\n';
	}
 
	delete b;
}

void dyncast02()
{
    dDerived apple(1, "Apple"); // create an apple
	dBase &b = apple; // set base reference to object
	dDerived &d = dynamic_cast<dDerived&>(b); // dynamic cast using a reference instead of a pointer
 
	std::cout << "The name of the Derived is: " << d.getName() << '\n'; // we can access Derived::getName through d
}

//Printing inherited classes using operator
class oBase
{
public:
oBase() {}

virtual void print() const { std::cout << "Base";  }

friend std::ostream& operator<<(std::ostream &out, const oBase &b)
{
    return b.print(out);
}

virtual ostream& print(ostream& out) const
{
    out << "Base";
    return out;
}
};

class oDerived : public oBase
{
public:

oDerived() {}

virtual ostream& print(ostream& out) const override
{
    out << "Derived";
    return out;
}
};

void opor00()
{
    oBase b;
    std::cout << b << '\n';
    oDerived d;
    std::cout << d << '\n';
}

void opor01()
{
    oDerived d;
    oBase &bref = d;
    std::cout << bref << '\n';
}

void opor02()
{
    oBase b;

    std::cout << b << '\n';

    oDerived d;

    std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects

    oBase &bref = d;

    std::cout << bref << '\n';
}

// quiz

class Shape
{
    protected:
    virtual ostream& print(ostream& out) const=0;

    friend ostream& operator<<(ostream &out, const Shape& s) 
    {
        return s.print(out);
    }

    virtual ~Shape(){}
};
class Point
{
    private:
    double m_x;
    double m_y;
    double m_z;

    public:
    Point(double x = 0.0,double y = 0.0,double z = 0.0):m_x(x),m_y(y),m_z(z)
    {}
    friend std::ostream& operator<<(std::ostream &out, const Point& p) 
    {
        out << "Point("<<p.m_x<<","<<p.m_y<<","<<p.m_z<<")";
        return out;
    } 
};

class Triangle : public Shape
{
    private:
    Point m_p1;
    Point m_p2;
    Point m_p3;

    public:
    Triangle(Point p1,Point p2,Point p3):m_p1(p1),m_p2(p2),m_p3(p3)
    {}

    virtual ostream& print(ostream& out)  const override
    {
        out <<"Triangle("<<m_p1<<","<<m_p2<<","<<m_p3<<")";
    }

};

class Circle : public Shape
{
    private:
    Point m_p0;
    double m_rad;

    public:
    Circle(Point p0,double rad):m_p0(p0),m_rad(rad)
    {}

    virtual ostream& print(ostream& out) const override
    {
        out <<"Circle("<<m_p0<<","<<"Radius:"<<m_rad<<")";
    }

    double getRad() const
    {
        return m_rad;
    }
};
double getLargestRad(vector<Shape*> vs)
{
    int lr=0;

    for(auto const &s :vs)
    {
        if(Circle *c = dynamic_cast<Circle*>(s))
            if(c->getRad()>lr)
                lr = c->getRad();
    }
    return lr;
}
void quiz2b()
{
    Circle c(Point(1, 2, 3), 7);
    std::cout << c << '\n';

    Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
    std::cout << t << '\n';
}

void quiz2c()
{
    std::vector<Shape*> v;

    v.push_back(new Circle(Point(1, 2, 3), 2));

    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));

    v.push_back(new Circle(Point(4, 5, 6), 3));

    // print each shape in vector v on its own line here

       std::cout << "The largest radius is: " << getLargestRad(v) << '\n'; // write this functio
}
#endif