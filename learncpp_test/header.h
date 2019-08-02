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


#endif