#include <gtest/gtest.h>
#include "../h/table.h"

TEST(table_tests, create_table_without_records)
{
	table x;
	ASSERT_EQ(x.name, "Tablica");
}

TEST(table_tests, add_begin) // one and some elements
{
	table x;
	x.add_begin(1);
	ASSERT_EQ(x.size(), 1);
	ASSERT_EQ(x.get(0), 1);
	x.add_begin(-1);
	x.add_begin(0);
	x.add_begin(12343);
	x.add_begin(123214);
	x.add_begin(1342);
	x.add_begin(1324);
	x.add_begin(123345);
	ASSERT_EQ(x.size(), 8);
	ASSERT_EQ(x.get(7), 1);
	ASSERT_EQ(x.get(6), -1);
	ASSERT_EQ(x.get(5), 0);
	ASSERT_EQ(x.get(4), 12343);
	ASSERT_EQ(x.get(3), 123214);
	ASSERT_EQ(x.get(2), 1342);
	ASSERT_EQ(x.get(1), 1324);
	ASSERT_EQ(x.get(0), 123345);
}

TEST(table_tests, add_end) // one and some elements
{
	table x;
	x.add_end(1);
	ASSERT_EQ(x.size(), 1);
	ASSERT_EQ(x.get(0), 1);
	x.add_end(-1);
	x.add_end(0);
	x.add_end(12343);
	x.add_end(123214);
	x.add_end(1342);
	x.add_end(1324);
	x.add_end(123345);
	ASSERT_EQ(x.size(), 8);
	ASSERT_EQ(x.get(0), 1);
	ASSERT_EQ(x.get(1), -1);
	ASSERT_EQ(x.get(2), 0);
	ASSERT_EQ(x.get(3), 12343);
	ASSERT_EQ(x.get(4), 123214);
	ASSERT_EQ(x.get(5), 1342);
	ASSERT_EQ(x.get(6), 1324);
	ASSERT_EQ(x.get(7), 123345);
}

TEST(table_tests, add_in_the_middle_TODO) // one and some elements
{
	table x;
	x.add(4, 0);  // 4
	ASSERT_EQ(x.size(), 1);
	ASSERT_EQ(x.get(0), 4);
	x.add_end(-1);  // 4, -1
	x.add_begin(10); // 10, 4, -1
	x.add(11, 1);   // 10, 11, 4, -1
	x.add(44, 4);   // 10, 11, 4, -1, 44
	ASSERT_EQ(x.size(), 5);
	ASSERT_EQ(x.get(0), 10);
	ASSERT_EQ(x.get(1), 11);
	ASSERT_EQ(x.get(2), 4);
	ASSERT_EQ(x.get(3), -1);
	ASSERT_EQ(x.get(4), 44);
}

TEST(table_tests, delete_begin_TODO) // one and some elements
{
	FAIL();
}

TEST(table_tests, delete_end_TODO) // one and some elements
{
	FAIL();
}

TEST(table_tests, delete_in_the_middle_TODO) // one and some elements
{
	FAIL();
}

TEST(table_tests, delete_last_element_TODO) // one and some elements
{
	FAIL();
}

TEST(table_tests, delete_in_void_table_TODO) // one and some elements
{
	FAIL();
}

TEST(table_tests, search_TODO) // zero, one and some elements
{
	FAIL();
}

TEST(table_tests, print_TODO) // zero, one and some elements
{
	FAIL();
}

TEST(table_tests, read_data_from_file_TODO) // zero, one and some elements
{
	FAIL();
}

TEST(table_tests, generate_random_data_TODO) // zero, one and some elements
{
	FAIL();
}

TEST(table_tests, bad_index_range_TODO) // all previous functions
{
	FAIL();
} // + get()