#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <chrono>
#include <array>
#include <algorithm>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cassert> // for assert()

using namespace std;

const int g_arrayElements = 10000;

class Timer
{
	private:
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1>>;

	chrono::time_point<clock_t> m_beg;

	public:
	Timer():m_beg(clock_t::now())
	{}

	~Timer()
	{
		delete this;
	}
	void reset()
	{
		m_beg = clock_t::now();

	}

	double elapsed() const
	{
		return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();

	}
};


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

#endif