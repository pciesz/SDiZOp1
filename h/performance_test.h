#ifndef SDIZOP1_PERFORMANCE_TEST_H
#define SDIZOP1_PERFORMANCE_TEST_H

#include "main.h"
#include "headers.h"

class performance_test
{
public:
	timer t;
	enum class one_value { add_end, add_begin, remove_end, remove_begin, add, remove, search };
	template<typename T> void tab_list_mod_one_value(one_value function_type, string name, CSV_output &out, vector<long> &number_of_elements,
	                            bool is_list = false);
public:
	void run();
	void run_table(CSV_output &out);
	void run_list(CSV_output &out);
	void run_heap(CSV_output &out);
};
#endif //SDIZOP1_PERFORMANCE_TEST_H
