#ifndef STDAFX_HPP
#define STDAFX_HPP

//#define __STDC_WANT_LIB_EXT1__ 1

#include <fstream>
#include <iostream>
#include <chrono>
#include <iterator>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cassert> // for assert()
#include <cstring> // for strlen() strcpy_s()
#include <initializer_list> // for std::initializer_list
#include <functional> // for std::reference_wrapper
#include <string.h>
#include <exception> // for std::exception
#include <stdexcept> // for std::runtime_error
#include <utility> // for std::move
#include <memory> //for std::unique_ptr
#include <iomanip>
#include <cctype>
#include <conio.h>

using namespace std;

const int g_arrayElements = 10000;

class Timer
{
	private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> m_beg;

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
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();

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
 class illegalParameterValue:public std::exception
 {
	private:
	std::string m_error;
	public:
	illegalParameterValue(std::string e):m_error(e)
	{

	}

	const char* what()const noexcept { 
		 return m_error.c_str();
	}
 };
#endif