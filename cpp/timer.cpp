#include "../h/timer.h"

void timer::start() {
  start_time = Clock::now();
}

void timer::stop() {
  stop_time = Clock::now();
}

void timer::count() {
  time_sum += (stop_time - start_time);
}

void timer::clear() {
  time_sum = Clock::from_time_t(0);
}

long timer::return_last_in_mics() {
  return std::chrono::duration_cast<std::chrono::microseconds>(stop_time - start_time).count();
}

long timer::return_last_in_ns() {
  return std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time).count();
}

long timer::return_all_in_mics() {
  return std::chrono::duration_cast<std::chrono::microseconds>(time_sum.time_since_epoch()).count();
}

long timer::return_all_in_ns() {
  return std::chrono::duration_cast<std::chrono::nanoseconds>(time_sum.time_since_epoch()).count();
}

timer::Clock::time_point timer::start_time = Clock::now();
timer::Clock::time_point timer::stop_time = Clock::now();
timer::Clock::time_point timer::time_sum = Clock::from_time_t(0);

void timer_seconds::start() {
  start_time = std::clock();
}
void timer_seconds::stop() {
  stop_time = std::clock();
}
double timer_seconds::return_time() {
  return (stop_time - start_time)/(double) CLOCKS_PER_SEC;
}
