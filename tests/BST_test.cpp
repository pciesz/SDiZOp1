#include <gtest/gtest.h>
#include <fstream>
#include "../h/BST.h"

TEST(BST_tests, create_BST_without_records) {
  BST x;
  ASSERT_EQ(x.name, "Drzewo BST");
}

TEST(BST_tests, create_BST_with_records) {
  vector<key_type> data = {55, 34, 354, 34, 23, -3434, 23, 435, 534, 32, 435, -32432, 0, 34};
  BST x(data);
  ASSERT_EQ(x.size(), data.size());
}

TEST(BST_tests, add) {
  BST x;
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

TEST(BST_tests, remove) {
  BST x;
  x.add(1);
  x.remove(1);
  ASSERT_EQ(x.size(), 0);
  x.add(1);
  x.add(5);
  x.add(-6);
  x.add(0);
  x.remove(5);
  ASSERT_EQ(x.size(), 3);
  x.remove(1);
  ASSERT_EQ(x.size(), 2);
  x.remove(0);
  ASSERT_EQ(x.size(), 1);
  x.remove(-6);
  ASSERT_EQ(x.size(), 0);
  ASSERT_THROW(x.remove(-6);, std::range_error);
  ASSERT_THROW(x.remove(345);, std::range_error);
}

TEST(BST_tests, delete_in_void_BST) {
  BST x;
  ASSERT_THROW(x.remove(-23), std::range_error);
  ASSERT_THROW(x.remove(0), std::range_error);
}

TEST(BST_tests, search) {
  BST x;
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

TEST(BST_tests, print) {
  BST x;
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
}

TEST(BST_tests, read_data_from_file) {
  std::ofstream out("tmp");
  out << "10 3    5 234    12354 -21334 21312 2345 2314 2345 345";
  out.close();
  BST x;
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

TEST(BST_tests, generate_random_data) {
  BST x;
  x.generate(0);
  ASSERT_EQ(x.size(), 0);
  x.generate(10);
  ASSERT_EQ(x.size(), 10);
  x.generate(1);
  ASSERT_EQ(x.size(), 1);
}

TEST(BST_tests, bad_data_range) {
  BST x;
  ASSERT_THROW(x.generate(-5), std::range_error);

}

TEST(BST_tests, clear) {
  BST x;
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