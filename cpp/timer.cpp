#include "../h/timer.h"

void timer::start()
{
	start_time = std::chrono::high_resolution_clock::now();
}

void timer::stop()
{
	stop_time = std::chrono::high_resolution_clock::now();
}

void timer::count()
{
	time_sum += (stop_time - start_time);
}

void timer::clear()
{
	time_sum = std::chrono::high_resolution_clock::from_time_t(0);
}

long timer::return_last_in_ms()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(stop_time - start_time).count();
}

long timer::return_last_in_ns()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time).count();
}

long timer::return_all_in_ms()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(time_sum.time_since_epoch()).count();
}

long timer::return_all_in_ns()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(time_sum.time_since_epoch()).count();
}

std::chrono::high_resolution_clock::time_point timer::start_time = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point timer::stop_time = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point timer::time_sum = std::chrono::high_resolution_clock::from_time_t(0);