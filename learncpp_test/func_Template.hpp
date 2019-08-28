#ifndef FUNCTEMP_H
#define FUNCTEMP_H

#include "header.h"

template<typename Type>
//1
const Type& tmax(const Type& x,const Type& y){    return (x>y)?x:y;  }

//2
class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0)
        : m_cents(cents)
    {
    }
    friend bool operator>(const Cents &c1,const Cents &c2)
    {
        return (c1.m_cents>c2.m_cents);
    }
    friend ostream& operator<<(ostream& out,const Cents &c)
    {
        out << c.m_cents;
        return out;
    }
    Cents& operator+=(const Cents &cents)
    {
        m_cents += cents.m_cents;
        return *this;
    }
 
    Cents& operator/(int value)
    {
        m_cents /= value;
        return *this;
    }
};

template <class CType>
CType taverage(CType *array, int length)
{
    CType sum;
    for(int c = 0;c < length;c++)
        sum += array[c];

    //sum/=length;
    return  sum/length;
}
#endif