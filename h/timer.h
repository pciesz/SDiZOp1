
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
#endif //SDIZOP1_TIMER_H
