#ifndef OVERLOAD_H
#define OVERLOAD_H

#include "header.h"

class Cents
{
    private:
    int m_cents;
    public:
    Cents(int cents = 0):m_cents(cents){}

    operator int() const { return m_cents; }

};

class Dollars
{
    private:
    int m_dollars;
    public:
    Dollars(int d = 0):m_dollars(d){}

    operator Cents() const {return Cents(m_dollars * 8);}

};

class Fraction
{
    private:
    int m_nume;
    int m_deno;

    public:
    Fraction(int n = 0, int d = 1):m_nume(n), m_deno(d)
    {
        assert(m_deno != 0);
        reduc();
    }

    Fraction(const Fraction &f):m_nume(f.m_nume), m_deno(f.m_deno)
    {
        cout << "Copy that->";
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

    void setNume(int n)
    {
        m_nume = n;
    }

    void setDeno(int d)
    {
        m_deno = d;
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

    operator double() const 
    {
        return (static_cast<double>(m_nume)/static_cast<double>(m_deno));
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

class Matrix
{
    private:
    double data[4][4];

    public:
    Matrix()
    {
        //
        for(int x=0;x<4;x++)
        for(int y=0;y<4;y++)
        data[x][y] = 0.0;
    }

    double& operator()(int x, int y)
    {
        assert(x >= 0 && x <=4);
        assert(y >= 0 && y <=4);
        return data[x][y];
    }

    const double& operator()(int x, int y) const
    {
        assert(x >= 0 && x <=4);
        assert(y >= 0 && y <=4);
        return data[x][y];
    }

    void operator()()
    {
        for(int x=0;x<4;x++)
        for(int y=0;y<4;y++)
        data[x][y] = 0.0;
    }
};

class Accumulator
{
    private:
    int m_counter =0;

    public:
    Accumulator(){}

    int operator()(int i){return(m_counter += i);}  
};

class Mystring
{
    private:
    string m_string;

    public:
    Mystring(const string str01):m_string(str01){}

    string operator()(int s,int l)
    {
        assert(s >= 0 && s+l <= m_string.length() && "Mystring: Substring out of range" );
        string p;
        for (int c = 0;c<l;c++)
        p += m_string[s+c];
        return p;
    }
};

class MyString
{
    private:
    string m_string;
    public:
    MyString(int x)
    {
        m_string.resize(x);
    }
    MyString(const char *string)
    {
        m_string = string;
    }
    friend ostream& operator<<(ostream& out,const MyString &s)
    {
        out << s.m_string;
        return out;
    }
};
#endif