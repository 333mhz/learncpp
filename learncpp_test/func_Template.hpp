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

//3
template <class CType>
class CTArray
{
    private:
    int m_length;
    CType *m_data;

    public:
    CTArray(int length = 0):m_data((length>0)?(new CType[length]):(nullptr)),m_length(length)
    {}

    ~CTArray(){ delete[] m_data;}

    void Erase()
    {
        delete[] m_data;
        m_data  = nullptr;
        m_length = 0;
    }

    CType& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength();
};

template<typename Type>
int CTArray<Type>::getLength(){ return m_length; }

void test01()
{
    CTArray<int> intArray(12);
	CTArray<double> doubleArray(12);
 
	for (int count = 0; count < intArray.getLength(); ++count)
	{
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
	}
 
	for (int count = intArray.getLength()-1; count >= 0; --count)
		std::cout << intArray[count] << "\t" << doubleArray[count] << '\n';
}

//4
template<class CType, int size>
class StaticArray
{
    private:
    CType m_data[size];

    public:
    CType* getArr();

    CType& operator[](int index)
    {
        return m_data[index];
    }

};

template<class CType, int size>
CType* StaticArray<CType,size>::getArr()
{
    return m_data;
}

void test04()
{
    StaticArray<int,12> intArr;
    for(int i = 0;i<12;i++)
    {
        intArr[i] = i;
        cout << intArr[i]<<" ";
    }
    cout << endl;

    StaticArray<double,12> doubleArr;
    for(int i = 0;i<12;i++)
    {
        doubleArr[i] = i+0.5;
        cout << doubleArr[i]<<" ";
    }
    cout << endl;
}

//5
template<class CType>
class Storage
{
    private:
    CType m_val;

    public:
    Storage(CType val):m_val(val)
    {
    }

    ~Storage(){}

    void prt()
    {
        cout << m_val << endl;
    }
};
template<>
void Storage<double>::prt()
{
    cout << scientific << m_val << endl;
}

template<>
Storage<char*>::Storage(char* val)
{
    // Figure out how long the string in value is
    int l = 0;
    while(val[l] != '\0')
        l++;
    l++;//to account for null terminator

    m_val = new char[l];
    for(int i = 0;i < l;i++)
        m_val[i] = val[i];
}

template <>
Storage<char*>::~Storage()
{
    delete[] m_val;
}

void test05()
{
    // Define some storage units
    //Storage<int> nValue(5);
    //Storage<double> dValue(6.7);
 
    // Print out some values
    //nValue.prt();
    //dValue.prt();
    char *string = new char[40];
 
    // Ask user for their name
    std::cout << "Enter your name: ";
    std::cin >> string;
 
    // Store the name
    Storage<char*> storage(string);
 
    // Delete the temporary string
    delete[] string;
 
    // Print out our value
    storage.prt(); // This will print garbage
}

//6
template<class CType,int size>
class Storarray
{
    private:
    CType m_data[size];

    public:
    void set(int index,const CType& val)
    {
        m_data[index] = val;
    }

    const CType& get(int index)
    {
        return m_data[index];
    }
};

template
void test06()
{
    // Define a Storage8 for integers
    Storarray<int,8> intStorage;
 
    for (int count=0; count<8; ++count)
        intStorage.set(count, count);
 
    for (int count=0; count<8; ++count)
        std::cout << intStorage.get(count) << '\n';
 
    // Define a Storage8 for bool
    Storarray<bool,8> boolStorage;
    for (int count=0; count<8; ++count)
        boolStorage.set(count, count & 3);
 
    for (int count=0; count<8; ++count)
        std::cout << (boolStorage.get(count) ? "true" : "false") << '\n';
}
#endif
