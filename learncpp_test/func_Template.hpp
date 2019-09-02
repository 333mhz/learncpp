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

//4 7
template<class CType, int size>
class StaticArray_Base
{
    protected:
    CType m_data[size];

    public:
    CType* getArr(){ return m_data; }

    CType& operator[](int index)
    {
        return m_data[index];
    }

    virtual void prt()
    {
        for(int i = 0;i<size;i++)
            cout << m_data[i] <<" ";
        
        std::cout << std::endl;
    }
};

template <class T, int size> // size is the expression parameter
class StaticArray: public StaticArray_Base <T, size>
{
public:
	StaticArray()
	{
 
	}
};


template <int size>
class StaticArray<char, size>:public StaticArray_Base <char, size>
{
    public:
    StaticArray()
    {}
    
    //using StaticArray_Base <char, size>::m_data;

    virtual void prt() override
    {
        //StaticArray_Base <char, size>::m_data
	    for (int count = 0; count < size; ++count)
		    std::cout << this->m_data[count];//???this???
        
        std::cout << std::endl;
    }
};

template <int size>
class StaticArray<double, size>:public StaticArray_Base <double, size>
{
    public:
    StaticArray()
    {}
    virtual void prt() override
    {
	    for (int count = 0; count < size; ++count)
		    std::cout << scientific << this->m_data[count]<<" ";//?
        
        std::cout << std::endl;
    }
};

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

void test07()
{
    // declare an integer array with room for 6 integers
	StaticArray<int, 6> intArray;
 
	// Fill it up in order, then print it
	for (int count = 0; count < 6; ++count)
		intArray[count] = count;
 
	intArray.prt();
 
	// declare a double buffer with room for 4 doubles
	StaticArray<double, 4> doubleArray;
 
	for (int count = 0; count < 4; ++count)
		doubleArray[count] = (4.0 + 0.1 * count);
 
	doubleArray.prt();

}
//5 8 
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

template<typename CT>
class Storage<CT*>
{
    private:
    CT* m_val;
    public:
    Storage(CT* val)
    {
            m_val = new CT(*val);
    }

    ~Storage()
    {
        delete m_val;
    }

    void prt()
    {
        std::cout << *m_val <<std::endl;
    }
};

template <>
Storage<char*>::Storage(char* value)
{
	// Figure out how long the string in value is
	int length = 0;
	while (value[length] != '\0')
		++length;
	++length; // +1 to account for null terminator
 
	// Allocate memory to hold the value string
	m_val = new char[length];
 
	// Copy the actual value string into the m_value memory we just allocated
	for (int count = 0; count < length; ++count)
		m_val[count] = value[count];
}
// Full specialization of destructor for type char*
template<>
Storage<char*>::~Storage()
{
	delete[] m_val;
}
template<> 
void Storage<char*>::prt()
{
    int i = 0;
    while(m_val[i] != '\0')
         std::cout << m_val[i++];
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

void test08()
{
    // Declare a non-pointer Storage to show it works
	Storage<int> myint(5);
	myint.prt();
 
	// Declare a pointer Storage to show it works
	int x = 7;
	Storage<int*> myintptr(&x);
 
	// If myintptr did a pointer assignment on x,
	// then changing x will change myintptr too
	x = 9;
	myintptr.prt();
 
	// Dynamically allocate a temporary string
	//char *name = new char[40]{ "Alex" }; // requires C++14
 
	// If your compiler isn't C++14 compatible, comment out the above line and uncomment these
	char *name = new char[40];
	strcpy(name, "Alex");
 
	// Store the name
	Storage< char*> myname(name);
 
	// Delete the temporary string
	delete[] name;
 
	// Print out our name
	myname.prt();
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

template<>
class Storarray<bool,int(8)>
{
    private:
    unsigned char m_data;

    public:
    Storarray():m_data(0)
    {}

     void set(int index, bool value)

    {
        // Figure out which bit we're setting/unsetting
        // This will put a 1 in the bit we're interested in turning on/off
        unsigned char mask = 1 << index;//00000001 << index
        if (value)  // If we're setting a bit
            m_data |= mask;  // Use bitwise-or to turn that bit on
            //01010101 |= 00001000 --- 01011101
        else  // if we're turning a bit off
            m_data &= ~mask;  // bitwise-and the inverse mask to turn that bit off
            //01010101 &= ~00000100 --- 01010001
    }

    bool get(int index)
    {
        // Figure out which bit we're getting
        unsigned char mask = 1 << index;
        // bitwise-and to get the value of the bit we're interested in
        // Then implicit cast to boolean
        return (m_data & mask);// 01010101 & 00001000 = 00000000
    }
    
};
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
    for (int count=7; count>-1; --count)
        boolStorage.set(count, count & 3);
 
    for (int count=7; count>-1; --count)
        std::cout << (boolStorage.get(count) ? "true" : "false") << '\n';
}

// 7

#endif
