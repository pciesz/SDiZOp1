#include <gtest/gtest.h>
#include <fstream>
#include "../h/table.h"

TEST(table_tests, create_table_without_records)
{
	table x;
	ASSERT_EQ(x.name, "Tablica");
}

TEST(table_tests, add_begin)
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

TEST(table_tests, add_end)
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

TEST(table_tests, add_in_the_middle)
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

TEST(table_tests, delete_begin)
{
	table x;
	x.add_begin(1);
	x.add_begin(-1);
	x.add_begin(0);
	x.add_begin(12343);
	x.add_begin(123214);
	x.add_begin(1342);
	x.add_begin(1324);
	x.add_begin(123345);
	x.remove_begin();
	ASSERT_EQ(x.size(), 7);
	ASSERT_EQ(x.get(6), 1);
	ASSERT_EQ(x.get(5), -1);
	ASSERT_EQ(x.get(4), 0);
	ASSERT_EQ(x.get(3), 12343);
	ASSERT_EQ(x.get(2), 123214);
	ASSERT_EQ(x.get(1), 1342);
	ASSERT_EQ(x.get(0), 1324);
	x.remove_begin();
	x.remove_begin();
	x.remove_begin();
	x.remove_begin();
	x.remove_begin();
	ASSERT_EQ(x.size(), 2);
	ASSERT_EQ(x.get(1), 1);
	ASSERT_EQ(x.get(0), -1);
}

TEST(table_tests, delete_end)
{
	table x;
	x.add_end(1);
	x.remove_end();
	ASSERT_EQ(x.size(), 0);
	x.add_end(1);
	x.add_end(-1);
	x.add_end(0);
	x.add_end(12343);
	x.add_end(123214);
	x.add_end(1342);
	x.add_end(1324);
	x.add_end(123345);
	x.remove_end();
	ASSERT_EQ(x.size(), 7);
	ASSERT_EQ(x.get(0), 1);
	ASSERT_EQ(x.get(1), -1);
	ASSERT_EQ(x.get(2), 0);
	ASSERT_EQ(x.get(3), 12343);
	ASSERT_EQ(x.get(4), 123214);
	ASSERT_EQ(x.get(5), 1342);
	ASSERT_EQ(x.get(6), 1324);
	x.remove_end();
	x.remove_end();
	x.remove_end();
	x.remove_end();
	x.remove_end();
	ASSERT_EQ(x.size(), 2);
	ASSERT_EQ(x.get(1), -1);
	ASSERT_EQ(x.get(0), 1);
}

TEST(table_tests, delete_in_the_middle)
{
	table x;
	x.add_end(1);
	x.remove(0);
	ASSERT_EQ(x.size(), 0);
	x.add_end(1);
	x.add_end(-1);
	x.add_end(0);
	x.add_end(12343);
	x.add_end(123214);
	x.add_end(1342);
	x.add_end(1324);
	x.add_end(123345);
	x.remove(7);
	ASSERT_EQ(x.size(), 7);
	ASSERT_EQ(x.get(0), 1);
	ASSERT_EQ(x.get(1), -1);
	ASSERT_EQ(x.get(2), 0);//
	ASSERT_EQ(x.get(3), 12343);
	ASSERT_EQ(x.get(4), 123214);
	ASSERT_EQ(x.get(5), 1342);
	ASSERT_EQ(x.get(6), 1324);
	x.remove(1);
	x.remove(1);
	x.remove(4);
	x.remove(3);
	x.remove(0);
	ASSERT_EQ(x.size(), 2);
	ASSERT_EQ(x.get(0), 12343);
	ASSERT_EQ(x.get(1), 123214);
}

TEST(table_tests, delete_last_element)
{
	table x;
	x.add_end(1);
	x.add_end(-1);;
	x.add_end(1324);
	x.remove_end();
	x.remove_end();
	x.remove_end();
	ASSERT_THROW(x.remove_end(), std::range_error);
	ASSERT_THROW(x.remove_end(), std::range_error);
	ASSERT_THROW(x.remove_end(), std::range_error);
	ASSERT_EQ(x.size(), 0);

	x.add_end(1);
	x.add_end(-1);
	x.add_end(1324);
	x.remove_begin();
	x.remove_begin();
	x.remove_begin();
	ASSERT_THROW(x.remove_begin(), std::range_error);
	ASSERT_THROW(x.remove_begin(), std::range_error);
	ASSERT_EQ(x.size(), 0);

	x.add_end(1);
	x.add_end(-1);;
	x.add_end(1324);
	x.remove(2);
	x.remove(0);
	x.remove(0);
	ASSERT_THROW(x.remove(0), std::range_error);
	ASSERT_THROW(x.remove(-1), std::range_error);
	ASSERT_THROW(x.remove(2), std::range_error);
	ASSERT_EQ(x.size(), 0);
}

TEST(table_tests, delete_in_void_table)
{
	table x;
	ASSERT_THROW(x.remove_end(), std::range_error);
	ASSERT_THROW(x.remove_end(), std::range_error);
	ASSERT_EQ(x.size(), 0);

	ASSERT_THROW(x.remove_begin(), std::range_error);
	ASSERT_THROW(x.remove_begin(), std::range_error);
	ASSERT_EQ(x.size(), 0);

	ASSERT_THROW(x.remove(0), std::range_error);
	ASSERT_THROW(x.remove(-1), std::range_error);
	ASSERT_THROW(x.remove(2), std::range_error);
	ASSERT_EQ(x.size(), 0);
}

TEST(table_tests, search)
{
	table x;
	x.add_end(1);
	x.add_end(-1);
	x.add_end(0);
	x.add_end(12343);
	x.add_end(123214);
	x.add_end(1342);
	x.add_end(1324);
	x.add_end(1324);
	x.add_end(123345);
	ASSERT_EQ(x.search(0), 2);
	ASSERT_EQ(x.search(-1), 1);
	ASSERT_EQ(x.search(1342), 5);
	ASSERT_THROW(x.search(-43), std::logic_error);
}

TEST(table_tests, print)
{
	table x;
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

TEST(table_tests, read_data_from_file)
{
	std::ofstream out("tmp");
	out << "10 3    5 234    12354 -21334 21312 2345 2314 2345 345";
	out.close();
	table x;
	x.read_from_file("tmp");
	ASSERT_EQ(x.size(), 10);
	ASSERT_EQ(x.get(0), 3);
	ASSERT_EQ(x.get(1), 5);
	ASSERT_EQ(x.get(2), 234);
	ASSERT_EQ(x.get(3), 12354);
	ASSERT_EQ(x.get(4), -21334);
	ASSERT_EQ(x.get(5), 21312);
	ASSERT_EQ(x.get(6), 2345);
	ASSERT_EQ(x.get(7), 2314);
	ASSERT_EQ(x.get(8), 2345);
	ASSERT_EQ(x.get(9), 345);
	std::ofstream out2("tmp");
	out2 << "5 1 2 3";
	out2.close();
	ASSERT_THROW(x.read_from_file("tmp");, std::logic_error);

	std::ofstream out3("tmp");
	out3 << "0";
	out3.close();
	x.read_from_file("tmp");
	ASSERT_EQ(x.size(), 0);
	ASSERT_THROW(x.read_from_file("sdfsdgfgre"), std::logic_error);
}

TEST(table_tests, generate_random_data)
{
	table x;
	x.generate(0);
	ASSERT_EQ(x.size(), 0);
	x.generate(10);
	ASSERT_EQ(x.size(), 10);
	x.generate(1);
	ASSERT_EQ(x.size(), 1);
}

TEST(table_tests, bad_index_range)
{
	table x;
	ASSERT_THROW(x.get(2), std::range_error);
	ASSERT_THROW(x.get(-2), std::range_error);
	ASSERT_THROW(x.add(5, -2), std::range_error);
	ASSERT_THROW(x.add(5, 2), std::range_error);
	ASSERT_THROW(x.remove_begin(), std::range_error);
	ASSERT_THROW(x.remove_end(), std::range_error);
	ASSERT_THROW(x.remove(-1), std::range_error);
	ASSERT_THROW(x.remove(5), std::range_error);
	ASSERT_THROW(x.generate(-5), std::range_error);
}