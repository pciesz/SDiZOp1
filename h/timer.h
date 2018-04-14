
#ifndef SDIZOP1_TIMER_H
#define SDIZOP1_TIMER_H

#include <chrono>

using namespace std::chrono;


class timer
{
public:
	static std::chrono::high_resolution_clock::time_point start_time;
	static std::chrono::high_resolution_clock::time_point stop_time;
	static std::chrono::high_resolution_clock::time_point counter;

public:
	static void start()
	{
		start_time = high_resolution_clock::now();
	}

	static void stop()
	{
		stop_time = high_resolution_clock::now();
	}

	static void count()
	{
		counter += (stop_time - start_time);
	}

	static void clear()
	{
		counter = high_resolution_clock::from_time_t(0);
	}

	static long return_last_in_ms()
	{
		return duration_cast<milliseconds>(stop_time - start_time).count();
	}

	static long return_last_in_ns()
	{
		return duration_cast<nanoseconds>(stop_time - start_time).count();
	}

	static long return_all_in_ms()
	{
		return duration_cast<milliseconds>(counter.time_since_epoch()).count();
	}

	static long return_all_in_ns()
	{
		return duration_cast<nanoseconds>(counter.time_since_epoch()).count();
	}
};

std::chrono::high_resolution_clock::time_point timer::start_time = high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point timer::stop_time = high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point timer::counter = high_resolution_clock::from_time_t(0);


// TODO
/*
 *
#include <windows.h>
#include <iomanip>

class Time
{
	long long int read_QPC()
	{
		LARGE_INTEGER count;
		QueryPerformanceCounter(&count);
		return((long long int)count.QuadPart);
	}


public:
	long long int frequency, start_time, elapsed;
	Time()
	{
		QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	}

	void start()
	{
		start_time = read_QPC();
	}

	double stop() // zwraca czas w ms
	{
		elapsed = read_QPC() - start_time;
		return  (1000.0 * elapsed) / frequency;
	}
	void tests();
};

#endif
 */
#endif //SDIZOP1_TIMER_H
