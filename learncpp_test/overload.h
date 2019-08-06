#ifndef OVERLOAD_H
#define OVERLOAD_H

#include "header.h"

class cents
{

};

class Fraction
{
    private:
    int m_nume;
    int m_deno;

    public:
    Fraction(int n = 0, int d = 1):m_nume(n), m_deno(d)
    {
        reduc();
    }

    void prt() const
    {

        cout << m_nume << "/" << m_deno << endl;
    }

    friend ostream& operator<<(ostream &out, const Fraction &f1)
    {
        out << "Fraction(" << f1.m_nume << "/" << f1.m_deno <<")";
    }

    friend istream& operator>>(istream &in, Fraction &f1)
    {
        in >> f1.m_nume;
        in >> f1.m_deno;

        return in;
    }
    int getNume() const
    {
        return m_nume;
    }

    int getDeno() const 
    {
        return m_deno;
    }

    //Fraction operator*(const Fraction &f1, const Fraction &f2);
    Fraction operator*(int a)
    {
        return Fraction(m_nume * a, m_deno);
    }
    //Fraction operator*(int a, const Fraction &f1);
    Fraction operator-() const
    {
       return Fraction(- m_nume );
    }

    Fraction operator+() const
    {
        if(m_nume > 0)
            return Fraction(m_nume, m_deno);
        else
            return Fraction(- m_nume, m_deno);
    }
    bool operator!() const
    {
        return (m_nume == 0 && m_deno != 0);
    }
    
    static int gcd(int a, int b)
    {
        return (b == 0)?(a>0 ? a : -a):gcd(b , a%b);
    }

    void reduc()
    {
        int g = gcd(m_nume , m_deno);

        m_nume /= g ; 
        m_deno /= g ;
    }


};

class Car
{
    private:
        string m_make;
        string m_model;

    public:
        Car(string ma = "Undefine", string mo = "Undefine"):m_make(ma), m_model(mo)
        {
        }

        friend bool operator==(const Car &c1, const Car &c2)
        {
            return (c1.m_model == c2.m_model && c1.m_make == c2.m_make);
        }
        friend bool operator!=(const Car &c1, const Car &c2)
        {
            return !(c1 == c2);
        }
        friend ostream& operator<<(ostream& out, const Car &c)
        {
            out << "("<<c.m_make<<", "<<c.m_model<<")";
            return out;
        }
        friend bool operator<(const Car &c1, const Car &c2)
        {
            if(c1.m_make == c2.m_make)
                return (c1.m_model < c2.m_model);
            else
                return (c1.m_make < c2.m_make);

        }

};

class Digit
{
    private:
    int m_digit;

    public:
    Digit(int d = 0):m_digit(d)
    {

    }
    Digit& operator++()
    {
        if(m_digit == 9)
            m_digit = 0;
        else
            ++m_digit;
    }
    Digit& operator--()
    {
        if(m_digit == 0)
            m_digit = 9;
        else
            --m_digit;
    }
        Digit& operator++(int)
    {
        if(m_digit == 9)
            m_digit = 0;
        else
            m_digit++;
    }
    Digit& operator--(int)
    {
        if(m_digit == 0)
            m_digit = 9;
        else
            m_digit--;
    }
    friend ostream& operator<<(ostream &out, const Digit &d)
    {
        out << "Digit(" << d.m_digit <<")";
        return out;
    }
};

class IntList
{
    private:
    int m_list[8] = {7,4,2,5,1,6,3,0};

    public:
    int& operator[](int idx)
    {
        return m_list[idx];
    }
    const int& operator[](int idx) const
    {
        return m_list[idx];
    }
};

class Stupid

{
private:

public:
// It doesn't make sense to overload operator[] to print something
// but it is the easiest way to show that the function parameter can be a non-integer
    void operator[] (std::string index)
    {
    std::cout << index;
    }
};

class GradeMap
{
    public:
    struct StudentGrade
    {
        string name;
        char grade;
    };

    private:
    vector<StudentGrade> m_map{};

    public:
    GradeMap()
    {
    }

    char& operator[](const string &name)
    {
        for(auto &ref : m_map)
        {
            if(ref.name == name)
                return ref.grade;
        }

        StudentGrade temp{name,'X'};

        m_map.push_back(temp);

        return m_map.back().grade;
    }

    //friend ostream& operator<<(ostream& out, const GradeMap &g)

};
#endif