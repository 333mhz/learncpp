#ifndef INHERITANCE_H
#define INHERITANCE_H

#include "header.h"

class Person
{
private:
    string m_name;
    int m_age;
public:
    Person(string n = "UNKNOW",int a = -1):m_name(n),m_age(a)
    {
    }

    string getName()const{return m_name;}
    int getAge()const{return m_age;}
};

class BaseballPlayer:public Person
{
private:
    double m_battingAverage;
    int m_homeRuns;
public:
    BaseballPlayer(string n,int a,double ba = 0.0,int hr =0):Person(n,a),m_battingAverage(ba),m_homeRuns(hr)
    {}

    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }
};

class A
{
public:
    A(int a)
    {
        std::cout << "A: " << a << '\n';
    }
};
 
class B: public A
{
public:
    B(int a, double b)
    : A(a)
    {
        std::cout << "B: " << b << '\n';
    }
};
 
class C: public B
{
public:
    C(int a , double b , char c)
    : B(a, b)
    {
        std::cout << "C: " << c << '\n';
    }
};
 

class Base
{
    private:
   int m_id;

    public:
    Base(int id=0)
        : m_id(id)
    {
    }
 
    int getId() const { return m_id; }
};
 
class Derived: public Base
{
private:
    double m_cost;

public:
    Derived(double cost=0.0, int id = 0)
        : m_cost(cost), Base(id)
    {
    }
 
    double getCost() const { return m_cost; }
};

class Fruit
{
    private:
    string m_name;
    string m_color;

    public:
    Fruit(string n,string c):m_name(n), m_color(c)
    {
    }

    const string getName() const
    {
        return m_name;
    }
    const string getColor() const
    {
        return m_color;
    }
};

class Apple:public Fruit
{
    private:
    double m_fiber;

    public:
    Apple(string n, string c, double f):Fruit(n,c),m_fiber(f)
    {}

    friend ostream& operator<<(ostream& out,const Apple& a)
    {
        out << "Apple("<<a.getName()<<","<<a.getColor()<<","<<a.m_fiber<<")"<<endl;

        return out;
    }
};

class Banana:public Fruit
{
    private:
    public:
    Banana(string n, string c):Fruit(n,c)
    {}
    friend ostream& operator<<(ostream& out,const Banana& b)
    {
        out << "Banana("<<b.getName()<<","<<b.getColor()<<")"<<endl;

        return out;
    }
};
#endif

