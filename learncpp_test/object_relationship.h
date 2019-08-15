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

class IntArray //container
{
private:
    int m_length;
    int *m_data;
 
public:
    IntArray():
        m_length(0), m_data(nullptr)
    {
    }
 
    IntArray(int length):
        m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    
    IntArray(const initializer_list<int> &list):IntArray(static_cast<int>(list.size()))
    {
            int count = 0;
            for(auto &e : list)
            {
                m_data[count] = e;
                count++;
            }
    }

    ~IntArray()
    {
        delete[] m_data;
        // we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
    }
 
    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to nullptr here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }
 
    IntArray(const IntArray&) = delete; // to avoid shallow copies
	IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    
    IntArray& operator=(const initializer_list<int> &list)
    {
        int length = static_cast<int>(list.size());

        if(length != m_length)
        {
            erase();
            m_length = length;
            m_data = new int[length];
        }

        int count = 0;
        for(auto &e : list)
        {
            m_data[count] = e;
            count++;
        }
        
        return *this;
    }

    // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
    void reallocate(int newLength)
    {
        // First we delete any existing elements
        erase();
 
        // If our array is going to be empty now, return here
        if (newLength <= 0)
            return;
 
        // Then we have to allocate new elements
        m_data = new int[newLength];
        m_length = newLength;
    }
 
    // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    void resize(int newLength)
    {
        // if the array is already the right length, we're done
        if (newLength == m_length)
            return;
 
        // If we are resizing to an empty array, do that and return
        if (newLength <= 0)
        {
            erase();
            return;
        }
 
        // Now we can assume newLength is at least 1 element.  This algorithm
        // works as follows: First we are going to allocate a new array.  Then we
        // are going to copy elements from the existing array to the new array.
        // Once that is done, we can destroy the old array, and make m_data
        // point to the new array.
 
        // First we have to allocate a new array
        int *data = new int[newLength];
 
        // Then we have to figure out how many elements to copy from the existing
        // array to the new array.  We want to copy as many elements as there are
        // in the smaller of the two arrays.
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
 
            // Now copy the elements one by one
            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }
 
        // Now we can delete the old array because we don't need it any more
        delete[] m_data;
 
        // And use the new array instead!  Note that this simply makes m_data point
        // to the same address as the new array we dynamically allocated.  Because
        // data was dynamically allocated, it won't be destroyed when it goes out of scope.
        m_data = data;
        m_length = newLength;
    }
 
    void insertBefore(int value, int index)
    {
        // Sanity check our index value
        assert(index >= 0 && index <= m_length);
 
        // First create a new array one element larger than the old array
        int *data = new int[m_length+1];
 
        // Copy all of the elements up to the index
        for (int before=0; before < index; ++before)
            data [before] = m_data[before];
 
        // Insert our new element into the new array
        data [index] = value;
 
        // Copy all of the values after the inserted element
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];
 
        // Finally, delete the old array, and use the new array instead
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
 
    void remove(int index)
    {
        // Sanity check our index value
        assert(index >= 0 && index < m_length);
 
        // If we're removing the last element in the array, we can just erase the array and return early
        if (m_length == 1)
        {
            erase();
            return;
        }
 
        // First create a new array one element smaller than the old array
        int *data = new int[m_length-1];
 
        // Copy all of the elements up to the index
        for (int before=0; before  < index; ++before)
            data[before] = m_data[before];
 
        // Copy all of the values after the removed element
        for (int after=index+1; after < m_length; ++after )
            data[after-1] = m_data[after];
 
        // Finally, delete the old array, and use the new array instead
        delete[] m_data;
        m_data = data;
        --m_length;
    }
 
    // A couple of additional functions just for convenience
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }
 
    int getLength() { return m_length; }
};

#endif