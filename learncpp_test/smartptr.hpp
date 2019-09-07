#ifndef SMARTPTR_H
#define SMARTPTR_H

#include "header.h"

//1 //3
template<class CT>
class Auto_ptr4
{
    CT* m_ptr;

public:
    Auto_ptr4(CT* ptr = nullptr):m_ptr(ptr)
    {
        cout << "Auto Pointer Normal Initialized\n";
    }
    Auto_ptr4(Auto_ptr4&& a):m_ptr(a.m_ptr)
    {
        a.m_ptr = nullptr;
        cout << "Auto Pointer Move Initialized\n";
    }
    Auto_ptr4(const Auto_ptr4& a)
    {
        m_ptr = new CT;
        *m_ptr = *a.m_ptr;
        cout << "Auto Pointer Copy Initialized\n";
    }
    ~Auto_ptr4()
    {
        delete m_ptr;
        cout << "Auto Pointer Destroyed\n";
    }

    Auto_ptr4& operator=(Auto_ptr4 &&a)
    {
        if(&a == this)
            return *this;

        delete m_ptr;

        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        cout << "Move Auto Pointer\n";

        return *this;
    }
    Auto_ptr4& operator=(const Auto_ptr4 &a)
    {
        if(&a == this)
            return *this;

        delete m_ptr;

        m_ptr = new CT;
        *m_ptr = *a.m_ptr;
        cout << "Copy Auto Pointer\n";

        return *this;
    }
    CT& operator*()  const { return *m_ptr; }
    CT* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr;}
};

class Resource
{   
    public:
    std::weak_ptr<Resource> m_wptr;
    Resource() { cout << "Resource acquired\n"; }
    ~Resource(){ cout << "Resource destroyed\n"; }
    void sayHi() { std::cout << "Hi\n"; }
};

Auto_ptr4<Resource> resGen()
{
    Auto_ptr4<Resource> res(new Resource);
    return res;
}

void test010()
{
    Auto_ptr4<Resource> res1(new Resource);

    int x;
    cout << "Enter an interger: \a";
    cin >> x;
    if(x == 0)
        throw 0;
    
    res1->sayHi();
    Auto_ptr4<Resource> res2(res1); // Alternatively, don't initialize res2 and then assign res2 = res1;
}

void test011()
{
    Auto_ptr4<Resource> res1(new Resource);
    Auto_ptr4<Resource> res2;
    cout << "res1 is " << (res1.isNull()?"null\n":"full\n");
    cout << "res2 is " << (res2.isNull()?"null\n":"full\n");
    res2 = res1;
    cout << "Ownership transferred\n";
    cout << "res1 is " << (res1.isNull()?"null\n":"full\n");
    cout << "res2 is " << (res2.isNull()?"null\n":"full\n");
    
}

vector<Auto_ptr4<Resource>> resVecGen()
{
    vector<Auto_ptr4<Resource>> c;
    c.push_back(resGen());

    cout << "---- exit resVecGen ----" << endl;
    return c;
}
void test030()
{
    vector<Auto_ptr4<Resource>> resv;
    //cout << "res is " << (res.isNull()?"null\n":"full\n");
    resv = resVecGen();
    //cout << "res is " << (res.isNull()?"null\n":"full\n");
}
void test031()
{
    Auto_ptr4<Resource> res;
    //cout << "res is " << (res.isNull()?"null\n":"full\n");
    res = resGen();
    //cout << "res is " << (res.isNull()?"null\n":"full\n");
}

void test032()
{
    Auto_ptr4<Resource> res,res2;
    //cout << "res is " << (res.isNull()?"null\n":"full\n");
    res = res2;
    //cout << "res is " << (res.isNull()?"null\n":"full\n");
}
//2
class Fraction
{
private:
	int m_numerator;
	int m_denominator;
 
public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
        cout << "Initialized\n";
	}
    ~Fraction()
	{
        cout << "deInitialized\n";
	}
	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << "/" << f1.m_denominator;
		return out;
	}
};
 

void test02()
{
	Fraction &&rref = Fraction(3, 5); // r-value reference to temporary Fraction
	std::cout << rref << '\n';
}

//4
template<class CT>
void myswap(CT& a,CT& b)
{
    CT tmp = std::move(a);
    cout <<"tmp: "<< tmp <<"|"<<"a: "<<a<<endl;
    a = std::move(b);
    cout <<"a: "<< a <<"|"<<"b: "<< b <<endl;
    b = std::move(tmp);
    cout <<"b: "<< b <<"|"<<"tmp: "<< tmp <<endl;
    cout <<"-----swap-----\n";
}
void test040()
{
    // Auto_ptr4<Resource> res;
    // cout << "res is " << (res.isNull()?"null\n":"full\n");
    // res = std::move(resGen());
    // cout << "res is " << (res.isNull()?"null\n":"full\n");

    //std::string x{ "abc" };
	//std::string y{ "de" };
	//std::cout << "x: " << x << '\n';
	//std::cout << "y: " << y << '\n';
 
	//myswap(x, y);
	//std::cout << "x: " << x << '\n';
	//std::cout << "y: " << y << '\n';

    std::vector<std::string> v;
	std::string str = "Knock";
 
	std::cout << "Copying str\n";
	v.push_back(str); // calls l-value version of push_back, which copies str into the array element
	
	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << '\n';
 
	std::cout << "\nMoving str\n";
 
	v.push_back(std::move(str)); // calls r-value version of push_back, which moves str into the array element
	
	std::cout << "str: " << str << '\n';
	std::cout << "vector:" << v[0] << ' ' << v[1] << '\n';
}

//5
void test050()
{
    std::unique_ptr<Resource> res0(new Resource);
    std::unique_ptr<Resource> res1;

    std::cout << "res0 is " << (static_cast<bool>(res0)?"full\n":"null\n");
    std::cout << "res1 is " << (static_cast<bool>(res1)?"full\n":"null\n");

    res1 = std::move(res0);
    std::cout << "--Ownership transferred--\n";
    std::cout << "res0 is " << (static_cast<bool>(res0)?"full\n":"null\n");
    std::cout << "res1 is " << (static_cast<bool>(res1)?"full\n":"null\n");

}

void test051()
{
    std::unique_ptr<Fraction> f0 = std::make_unique<Fraction>(2,3);
    cout << *f0 <<endl;
    auto f1 = std:: make_unique<Fraction[]>(4);
    for(int i = 0;i<4;++i)
        cout << f1[i] << ' ';
    std::cout << std::endl;

    f1[0] = *f0;
    for(int i = 0;i<4;++i)
        cout << f1[i] << ' ';
    std::cout << std::endl;

    f1[1] = std::move(*f0);//???
    cout << *f0 << endl;
    for(int i = 0;i<4;++i)
        cout << f1[i] << ' ';
    std::cout << std::endl;
    // std::unique_ptr<Fraction> f2;
    // f2 = std::move(f0);
    // std::cout << "f0 is " << (static_cast<bool>(f0)?"full\n":"null\n");
    // std::cout << "f2 is " << (static_cast<bool>(f2)?"full\n":"null\n");

    myswap(f1[0],f1[2]);
    for(int i = 0;i<4;++i)
        cout << f1[i] << ' ';
    std::cout << std::endl;
}

template<class CT>
std::unique_ptr<CT> createUP()
{
    return std::make_unique<CT>();
}

void test052()
{
    std::unique_ptr<Resource> ptr =  std::make_unique<Resource>();

}
//6
void test061()
{
    // allocate a Resource object and have it owned by std::shared_ptr
	Resource *res = new Resource;
	std::shared_ptr<Resource> ptr1(res);
	{
		std::shared_ptr<Resource> ptr2(ptr1); // use copy initialization to make another std::shared_ptr pointing to the same thing
 
		std::cout << "Killing one shared pointer\n";
	} // ptr2 goes out of scope here, but nothing happens
 
	std::cout << "Killing another shared pointer\n";
}

void test062()
{
    // allocate a Resource object and have it owned by std::shared_ptr
	auto ptr1 = std::make_shared<Resource>();
	{
		auto ptr2 = ptr1; // create ptr2 using copy initialization of ptr1
 
		std::cout << "Killing one shared pointer\n";
	} // ptr2 goes out of scope here, but nothing happens
 
	std::cout << "Killing another shared pointer\n";
}

//7
class Person
{
	std::string m_name;
	std::weak_ptr<Person> m_partner; // note: This is now a std::weak_ptr
 
public:
		
	Person(const std::string &name): m_name(name)
	{ 
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}
 
	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;
 
		p1->m_partner = p2;
		p2->m_partner = p1;
 
		std::cout << p1->m_name << " is now partnered with " << p2->m_name << "\n";
 
		return true;
	}
};

void test071()
{
    auto lucy = std::make_shared<Person>("Lucy");
	auto ricky = std::make_shared<Person>("Ricky");
 
	partnerUp(lucy, ricky);
}
void test072()
{
    auto ptr = std::make_shared<Resource>();

    ptr->m_wptr = ptr;
}
#endif