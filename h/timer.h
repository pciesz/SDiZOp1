
#ifndef SDIZOP1_TIMER_H
#define SDIZOP1_TIMER_H

#include <chrono>

class timer {
public:
  typedef std::chrono::high_resolution_clock Clock;
  static Clock::time_point start_time;
  static Clock::time_point stop_time;
  static Clock::time_point time_sum;
  static void start();
  static void stop();
  static void count();
  static void clear();
  static long return_last_in_mics();
  static long return_last_in_ns();
  static long return_all_in_mics();
  static long return_all_in_ns();
};
class timer_seconds {
public:
  std::clock_t start_time;
  clock_t stop_time;
  void start();
  void stop();
  double return_time();
};

#endif //SDIZOP1_TIMER_H


