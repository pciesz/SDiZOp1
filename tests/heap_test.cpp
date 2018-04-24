#include <gtest/gtest.h>
#include <fstream>
#include "../h/heap.h"

TEST(heap_tests, create_heap_without_records) {
  heap x;
  ASSERT_EQ(x.name, "Kopiec");
}

TEST(heap_tests, create_heap_with_records) {
  vector<key_type> data = {55, 34, 354, 34, 23, -3434, 23, 435, 534, 32, 435, -32432, 0, 34};
  heap x(data);
  ASSERT_EQ(x.size(), data.size());
  ASSERT_EQ(x.remove_top(), 534);
}

TEST(heap_tests, add_element) {
  heap x;
  x.add(1);
  ASSERT_TRUE(x.search(1));
  x.add(1);
  x.add(5);
  x.add(-6);
  x.add(0);
  ASSERT_TRUE(x.search(1));
  ASSERT_TRUE(x.search(0));
  ASSERT_FALSE(x.search(23));
}

TEST(heap_tests, delete_from_top) {
  heap x;
  x.add(1);
  ASSERT_EQ(x.remove_top(), 1);
  x.add(1);
  x.add(5);
  x.add(-6);
  x.add(0);
  ASSERT_EQ(x.remove_top(), 5);
  ASSERT_EQ(x.remove_top(), 1);
  ASSERT_EQ(x.remove_top(), 0);
  ASSERT_EQ(x.remove_top(), -6);
  ASSERT_THROW(x.remove_top(), std::range_error);
  ASSERT_THROW(x.remove_top(), std::range_error);
}

TEST(heap_tests, delete_last_element) {
  heap x;
  x.add(1);
  x.add(1);
  x.add(5);
  ASSERT_EQ(x.remove_top(), 5);
  ASSERT_EQ(x.remove_top(), 1);
  ASSERT_EQ(x.remove_top(), 1);
  ASSERT_THROW(x.remove_top(), std::range_error);
  ASSERT_THROW(x.remove_top(), std::range_error);
}

TEST(heap_tests, delete_in_void_heap) {
  heap x;
  ASSERT_THROW(x.remove_top(), std::range_error);
  ASSERT_THROW(x.remove_top(), std::range_error);
}

TEST(heap_tests, search) {
  heap x;
  x.add(1);
  ASSERT_TRUE(x.search(1));
  ASSERT_FALSE(x.search(0));
  x.add(5);
  x.add(5);
  x.add(-1324);
  x.add(0);
  x.add(4356);
  ASSERT_TRUE(x.search(1));
  ASSERT_TRUE(x.search(5));
  ASSERT_TRUE(x.search(0));
  ASSERT_TRUE(x.search(-1324));
  ASSERT_TRUE(x.search(4356));
  ASSERT_FALSE(x.search(23));
}

TEST(heap_tests, print) {
  heap x;
  x.print();
  // test wyniku
  x.add(1);
  x.add(-1);
  x.add(0);
  x.add(12343);
  x.add(123214);
  x.add(1342);
  x.add(1324);
  x.add(1324);
  x.add(123345);
  x.print();
  x.clear();
  x.generate(20);
  x.print();
}

TEST(heap_tests, read_data_from_file) {
  std::ofstream out("tmp");
  out << "10 3    5 234    12354 -21334 21312 2345 2314 2345 345";
  out.close();
  heap x;
  x.read_from_file("tmp");
  ASSERT_TRUE(x.search(3));
  ASSERT_TRUE(x.search(5));
  ASSERT_TRUE(x.search(234));
  ASSERT_TRUE(x.search(12354));
  ASSERT_TRUE(x.search(-21334));
  ASSERT_TRUE(x.search(21312));
  ASSERT_TRUE(x.search(2345));
  ASSERT_TRUE(x.search(2314));
  ASSERT_TRUE(x.search(2345));
  ASSERT_TRUE(x.search(345));
  std::ofstream out2("tmp");
  out2 << "5 1 2 3";
  out2.close();
  ASSERT_THROW(x.read_from_file("tmp");, std::logic_error);
  std::ofstream out3("tmp");
  out3 << "0";
  out3.close();
  x.read_from_file("tmp");
  ASSERT_THROW(x.read_from_file("sdfsdgfgre"), std::logic_error);
}

TEST(heap_tests, generate_random_data) {
  heap x;
  x.generate(0);
  ASSERT_EQ(x.size(), 0);
  x.generate(10);
  ASSERT_EQ(x.size(), 10);
  x.generate(1);
  ASSERT_EQ(x.size(), 1);
}

TEST(heap_tests, bad_data_range_TODO) {
  heap x;
  ASSERT_THROW(x.remove_top(), std::range_error);
  ASSERT_THROW(x.remove_top(), std::range_error);
  ASSERT_THROW(x.generate(-5), std::range_error);
}

TEST(heap_tests, clear) {
  heap x;
  x.generate(0);
  ASSERT_EQ(x.size(), 0);
  x.clear();
  ASSERT_EQ(x.size(), 0);
  x.generate(10);
  ASSERT_EQ(x.size(), 10);
  x.clear();
  ASSERT_EQ(x.size(), 0);
  x.generate(1);
  ASSERT_EQ(x.size(), 1);
  x.clear();
  ASSERT_EQ(x.size(), 0);
}

TEST(heap_tests, get) {
  heap x;
  x.add(1);
  x.add(3);
  x.add(2);
  ASSERT_EQ(x.get(0), 3);
  ASSERT_EQ(x.get(1), 1);
  ASSERT_EQ(x.get(2), 2);
  ASSERT_THROW(x.get(-1), std::range_error);
  ASSERT_THROW(x.get(3), std::range_error);
  ASSERT_THROW(x.get(4), std::range_error);
}