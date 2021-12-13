#pragma once

#include <iostream>
#include <chrono>

using namespace std;

class Time
{
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, std::ratio<1> >;

	chrono::time_point<clock_t> startTime;

public:
	Time(): startTime(clock_t::now()) {}
	~Time() = default;
	void resetTime();
	double getTime() const;
};
