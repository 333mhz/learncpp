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
    vector<Teacher*> m_dept;

    public:
    Department()
    {}

    void add(Teacher *t)
    {
        m_dept.push_back(t);
    }
    friend ostream& operator<<(ostream& out,const Department &d)
    {
        out<<"Deptartment: ";
        for(const auto &t : d.m_dept)
            out<<t->getName()<<" ";
        out<<endl;

        return out;
    }
};
class Patient;
class Doctor
{
    private:
    string m_name{};
    vector<Patient*> m_pat{};

    public:
    Doctor(string n):m_name(n){}

    void addPat(Patient *p);
    
    friend ostream& operator<<(ostream& out,const Doctor& doc);

    string getName()const{return m_name;}
};

class Patient
{
    private:
    string m_name{};
    vector<Doctor*> m_doc{};

    void addDoc(Doctor *d)
    {
        m_doc.push_back(d);
    }

    public:
    Patient(string n):m_name(n)
    {}

    friend ostream& operator<<(ostream& out,const Patient &p);

    friend void Doctor::addPat(Patient* p);

    string getName()const{return m_name;}
};
class Car
{
    private:
    string m_name;
    int m_id;

    public:
    Car(string n,int id):m_name(n),m_id(id)
    {}

    string getName(){return m_name;}
    int getid(){return m_id;}
};

class CarLot
{
    private:
    static Car s_carlot[4];

    public:
    CarLot()=delete;
    static Car* getCar(int id)
    {
        for(int i = 0;i < 4;i++)
        if(s_carlot[i].getid() == id)
        return &(s_carlot[i]);

        return nullptr;
    }
};

class Driver
{
    private:
    string m_name;
    int m_carid;

    public:
    Driver(string n,int ci):m_name(n),m_carid(ci)
    {}

    string getName()const{return m_name;}
    int getCarid()const{return m_carid;}
};
#endif