#include "Time.h"

void Time::resetTime()
{
	startTime = clock_t::now();
}

double Time::getTime() const
{
	return chrono::duration_cast<second_t>(clock_t::now() - startTime).count();
}