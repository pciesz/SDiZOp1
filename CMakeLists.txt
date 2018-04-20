cmake_minimum_required(VERSION 3.10)
project(SDiZOp1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgtest -lgtest_main")
include_directories(googletest/include googletest)

add_executable(SDiZOp1 cpp/main.cpp tests/table_test.cpp tests/timer_test.cpp tests/list_test.cpp tests/heap_test.cpp tests/BST_test.cpp tests/DSW_test.cpp h/benchmark.h h/data_structure.h h/main.h h/timer.h h/CSV_output.h h/read_file.h h/randomizer.h h/headers.h h/table.h cpp/table.cpp h/list.h cpp/list.cpp cpp/heap.cpp h/heap.h cpp/timer.cpp h/performance_test.h cpp/performance_test.cpp)

target_link_libraries(SDiZOp1 gtest gtest_main)