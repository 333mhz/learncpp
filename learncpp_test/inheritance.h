#ifndef HEADER_H
#define HEADER_H

#include "header.h"

class Person
{
    public:
    string m_name;
    int m_age;

    Person(string n,int a):m_name(n),m_age(a)
    {
    }

    string getName()const{return m_name;}
    int getAge()const{return m_age;}
};

class BaseballPlayer:public Person
{
    public:
    double m_battingAverage;
    int m_homeRuns;

    BaseballPlayer(double ba = 0.0,int hr =0):m_battingAverage(ba),m_homeRuns(hr)
    {}

};

#endif

