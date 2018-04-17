#include <gtest/gtest.h>
#include <fstream>
#include "../h/list.h"

TEST(list_tests, create_list_without_records)
{
	list x;
	ASSERT_EQ(x.name, "Lista");
}

TEST(list_tests, add_begin)
{
	list x;
	x.add_begin(1);
	ASSERT_TRUE(x.search(1));
	x.add_begin(1);
	x.add_begin(5);
	x.add_begin(-6);
	x.add_begin(0);
	ASSERT_TRUE(x.search(1));
	ASSERT_TRUE(x.search(0));
	ASSERT_FALSE(x.search(23));
}

TEST(list_tests, add_end)
{
	list x;
	x.add_end(1);
	ASSERT_TRUE(x.search(1));
	x.add_end(1);
	x.add_end(5);
	x.add_end(-6);
	x.add_end(0);
	ASSERT_TRUE(x.search(1));
	ASSERT_TRUE(x.search(0));
	ASSERT_FALSE(x.search(23));
}

TEST(list_tests, add_in_the_middle)
{
	list x;
	ASSERT_THROW(x.add(1, 1), std::range_error);
	ASSERT_FALSE(x.search(1));
	x.add_end(1);
	x.add(0, 1);
	ASSERT_TRUE(x.search(0));
	ASSERT_THROW(x.add(-1, 45), std::range_error);
	x.add(5, 0);
	ASSERT_TRUE(x.search(5));
}

TEST(list_tests, delete_begin)
{
	list x;
	x.add_end(1);
	x.remove_begin();
	x.add_end(1);
	x.add_end(5);
	x.add_end(-6);
	x.add_end(0);
	x.remove_begin();
	x.remove_begin();
	x.remove_begin();
	x.remove_begin();
	ASSERT_THROW(x.remove_begin(), std::range_error);
	ASSERT_THROW(x.remove_begin(), std::range_error);
}

TEST(list_tests, delete_end)
{
	list x;
	x.add_end(1);
	x.remove_end();
	x.add_end(1);
	x.add_end(5);
	x.add_end(-6);
	x.add_end(0);
	x.remove_end();
	x.remove_end();
	x.remove_end();
	x.remove_end();
	ASSERT_THROW(x.remove_end(), std::range_error);
	ASSERT_THROW(x.remove_end(), std::range_error);
}

TEST(list_tests, delete_in_the_middle)
{
	list x;
	x.add_end(1);
	x.add_end(1);
	x.add_end(5);
	x.add_end(-6);
	x.add_end(0);
	x.remove(1);
	x.remove(1);
	x.remove(-6);
	ASSERT_THROW(x.remove(34), std::range_error);
	ASSERT_THROW(x.remove(1), std::range_error);
	x.remove(0);
}

TEST(list_tests, delete_last_element)
{
	list x;
	x.add_end(1);
	x.add_end(1);
	x.add_end(5);
	x.add_end(-6);
	x.add_end(0);
	x.remove_end();
	x.remove_end();
	x.remove_end();
	x.remove_end();
	x.remove_end();
	ASSERT_THROW(x.remove_end(), std::range_error);
	ASSERT_THROW(x.remove_end(), std::range_error);
}

TEST(list_tests, delete_in_void_list)
{
	list x;
	ASSERT_THROW(x.remove_end(), std::range_error);
	ASSERT_THROW(x.remove_begin(), std::range_error);
	ASSERT_THROW(x.remove(0), std::range_error);
}

TEST(list_tests, search)
{
	list x;
	x.add_end(1);
	x.add_end(1);
	x.add_end(5);
	x.add_end(-6);
	ASSERT_TRUE(x.search(1));
	ASSERT_TRUE(x.search(5));
	ASSERT_TRUE(x.search(-6));
	ASSERT_FALSE(x.search(324));
}

TEST(list_tests, print)
{
	list x;
	x.print();      // TODO przechwycenie sturnieni wyjscia by przetestowac
	// test wyniku
	x.add_end(1);
	x.add_end(-1);
	x.add_end(0);
	x.add_end(12343);
	x.add_end(123214);
	x.add_end(1342);
	x.add_end(1324);
	x.add_end(1324);
	x.add_end(123345);
	x.print();
}

TEST(list_tests, read_data_from_file)
{
	std::ofstream out("tmp");
	out << "10 3    5 234    12354 -21334 21312 2345 2314 2345 345";
	out.close();
	list x;
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

TEST(list_tests, generate_random_data)
{
	list x;
	x.generate(0);
	x.generate(10);
	x.generate(1);
}

TEST(list_tests, bad_data_range)
{
	list x;
	ASSERT_THROW(x.add(5, -2), std::range_error);
	ASSERT_THROW(x.add(5, 2), std::range_error);
	ASSERT_THROW(x.remove_begin(), std::range_error);
	ASSERT_THROW(x.remove_end(), std::range_error);
	ASSERT_THROW(x.remove(-1), std::range_error);
	ASSERT_THROW(x.remove(5), std::range_error);
	ASSERT_THROW(x.generate(-5), std::range_error);
}