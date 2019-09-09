#ifndef STDSTRING_H
#define STDSTRING_H

#include "header.h"

//2

template <typename T>
inline std::string ToString(T tx)
{
    std::ostringstream os;
    os << tx;
    return os.str();
}

template <typename T>
inline bool FromString(const std::string& str,T& tx)
{
    std::istringstream is( str );
    return (is >> tx)?true:false;
}

void test02()
{
    string sFour(ToString(4));
    string sSixPointSeven(ToString(6.7));
    string sA(ToString('A'));
    cout << sFour << endl;
    cout << sSixPointSeven << endl;
    cout << sA << endl;

    int ix;
    double dx;
    char cx;

    if(FromString(sFour,ix))
        cout << ix << endl;
    if(FromString(sSixPointSeven,dx))
        cout << dx << endl;
    if(FromString(sA,cx))
        cout << cx << endl;   
}

//3
void test03()
{
     srand(time(0)); // seed random number generator
 
    string sString; // length 0
    sString.reserve(64); // reserve 64 characters
 
    // Fill string up with random lower case characters
    for (int nCount=0; nCount < 64; ++nCount)
        sString += 'a' + rand() % 26;
 
    cout << sString;
}

//4
void test04()
{
    string sSource("sphinx of black quartz, judge my vow");
 
    char szBuf[20];
    int nLength = sSource.copy(szBuf, 5, 0);
    szBuf[nLength]='\0';  // Make sure we terminate the string in the buffer
 
    cout << szBuf << endl;
}
#endif