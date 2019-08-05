#ifndef OVERLOAD_H
#define OVERLOAD_H

#include "header.h"

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



#endif