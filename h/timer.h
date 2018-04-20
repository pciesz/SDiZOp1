
#ifndef SDIZOP1_TIMER_H
#define SDIZOP1_TIMER_H

#include <chrono>

class timer
{
public:
	static std::chrono::high_resolution_clock::time_point start_time;
	static std::chrono::high_resolution_clock::time_point stop_time;
	static std::chrono::high_resolution_clock::time_point time_sum;
public:
	static void start();
	static void stop();
	static void count();
	static void clear();
	static long return_last_in_ms();
	static long return_last_in_ns();
	static long return_all_in_ms();
	static long return_all_in_ns();
};


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
