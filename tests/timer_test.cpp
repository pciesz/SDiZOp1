#include <gtest/gtest.h>
#include "../h/timer.h"

TEST(timer_tests, timer_return_correct_value) {
  timer x;
  x.start();
  x.stop();
  ASSERT_TRUE(x.return_last_in_ns()!=0);
}
/*
TEST(timer_tests, wait_1ms) {
  timer x;
  x.start();
  usleep(1000);
  x.stop();
  ASSERT_EQ(x.return_last_in_mics(), 1);
}

TEST(timer_tests, wait_10ms) {
  timer x;
  x.start();
  usleep(10000);
  x.stop();
  ASSERT_EQ(x.return_last_in_mics(), 10);
}

TEST(timer_tests, start_pause_stop_complex_test) {
  timer x;
  x.start();
  usleep(1000);
  x.stop();
  x.count();
  x.start();
  usleep(10000);
  x.stop();
  x.count();
  ASSERT_EQ(x.return_all_in_mics(), 11);
}
 */