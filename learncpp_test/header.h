#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <chrono>
#include <array>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cassert> // for assert()
#include <cstring> // for strlen()
#include <initializer_list> // for std::initializer_list

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
class Random
{
private:
	int m_min;
	int m_max;
public:
	Random(int min,int max):m_min(min),m_max(max)
	{
		srand(static_cast<unsigned int>(time(0)));
		rand();
	}
	int getRandomNumber()
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
		// static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (m_max - m_min + 1) + m_min);
	}
};

#endif