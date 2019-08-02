#ifndef MESS_H
#define MESS_H

class Pnt2d
{
    private:
    double m_x;
    double m_y;

    public:
    //Pnt2d(double x = 0.0, double y = 0.0):m_x(x),m_y(y){}
    Pnt2d(double x = 0.0, double y = 0.0):m_x(x),m_y(y){}
	~Pnt2d()
	{
		delete this;
	}
    void prt() const
    {
        cout << "Point2d(" << this->m_x <<", "<<this->m_y<<")\n";

    }

    //double dist2(Pnt2d &other)
    //{   return sqrt(pow((this->m_x - other.m_x),2)+pow((this->m_y - other.m_y),2));    }
    friend double dist2(Pnt2d &p1,Pnt2d &p2);
};

void sortArr(array<int,g_arrayElements> &arr)
{
	for(int si = 0;si < g_arrayElements-1;si++)
	{
		int min = si;

		for(int ci = si+1;ci < g_arrayElements; ci++ )
		{
			if(arr[ci] < arr[si])
				min = ci;
		}
	

	swap(arr[si], arr[min]);
	}
}


double dist2(Pnt2d &p1,Pnt2d &p2)
{   return sqrt(pow((p1.m_x - p2.m_x),2)+pow((p1.m_y - p2.m_y),2));    }

class Cents
{
	private:
	int m_cents;

	public:
	Cents(int cents) { m_cents = cents; }

	// add Cents + Cents using a friend function
	friend Cents operator+(const Cents &c1, const Cents &c2);
	friend Cents operator-(const Cents &c1, const Cents &c2);
	int getCents() const { return m_cents; }

};

// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents &c2)
{
	return Cents(c1.m_cents + c2.m_cents);
}

Cents operator-(const Cents &c1, const Cents &c2)
{
	return Cents(c1.m_cents - c2.m_cents);
}

class MinMax
{
private:
	int m_min; // The min value seen so far
	int m_max; // The max value seen so far
public:
	MinMax(int min, int max)
	{
	m_min = min;
	m_max = max;
	}
	int getMin() { return m_min; }
	int getMax() { return m_max; }
	friend MinMax operator+(const MinMax &m1, const MinMax &m2);
	friend MinMax operator+(const MinMax &m, int value);
	friend MinMax operator+(int value, const MinMax &m);
};

MinMax operator+(const MinMax &m1, const MinMax &m2)
{
	// Get the minimum value seen in m1 and m2
	int min = m1.m_min < m2.m_min ? m1.m_min : m2.m_min;
	// Get the maximum value seen in m1 and m2
	int max = m1.m_max > m2.m_max ? m1.m_max : m2.m_max;
	return MinMax(min, max);
}

MinMax operator+(const MinMax &m, int value)
{
	// Get the minimum value seen in m and value
	int min = m.m_min < value ? m.m_min : value;
	// Get the maximum value seen in m and value
	int max = m.m_max > value ? m.m_max : value;
	return MinMax(min, max);
}

MinMax operator+(int value, const MinMax &m)
{
	// call operator+(MinMax, int)
	return m + value;
}

#endif