#ifndef OVERLOAD_H
#define OVERLOAD_H

#include "header.h"

class Pnt2d
{
    private:
    double m_x;
    double m_y;

    public:
    //Pnt2d(double x = 0.0, double y = 0.0):m_x(x),m_y(y){}
    Pnt2d(double x = 0.0, double y = 0.0):m_x(x),m_y(y){}
	//~Pnt2d()
	//{
	//delete this;
	//}
    void prt() const
    {
        cout << "Point2d(" << this->m_x <<", "<<this->m_y<<")\n";
    }

    //double dist2(Pnt2d &other)
    //{   return sqrt(pow((this->m_x - other.m_x),2)+pow((this->m_y - other.m_y),2));    }
    //friend double dist2(Pnt2d &p1,Pnt2d &p2);
    friend ostream& operator<<(ostream& out,const Pnt2d &p)
    {
        out << "Point2d("<<p.m_x<<","<<p.m_y<<")";
        return out;
    }
    void setPnt2d(int x,int y)
    {
        m_x = x;
        m_y = y;


    }
};

class Creature
{
    private:
    string m_name;
    Pnt2d m_location;

    public:
    Creature(const string &n,const Pnt2d &l ):m_name(n),m_location(l)
    {}

    friend ostream& operator<<(ostream& out,const Creature &c)
    {
        out << c.m_name<<" at "<<c.m_location;
        return out;
    }

    void mov2(int x,int y)
    {
        m_location.setPnt2d(x,y);
    }
};

class Teacher
{
    private:
    string m_name;

    public:
    Teacher(string n):m_name(n)
    {}

    string getName(){return m_name;}
};

class Department
{
    private:
    Teacher *m_teachers;

    public:
    Department(Teacher *t = nullptr):m_teachers(t)
    {}
};
#endif