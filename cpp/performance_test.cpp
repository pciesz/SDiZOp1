#include "../h/performance_test.h"

void performance_test::run()
{
	CSV_output out("performance_tests_result.csv");
	run_table(out);
	run_list(out);
	run_heap(out);
}

template<typename T>
void performance_test::tab_list_mod_one_value(one_value function_type, string name, CSV_output &out,
                                              vector<long> &number_of_elements, bool is_list)
{
	switch (function_type)
	{
		case one_value::add_end:
			out.add_to_line(name + ": add_end");
			break;
		case one_value::add_begin:
			out.add_to_line(name + ": add_begin");
			break;
		case one_value::remove_begin:
			out.add_to_line(name + ": remove_begin");
			break;
		case one_value::remove_end:
			out.add_to_line(name + ": remove_end");
			break;
		case one_value::add:
			out.add_to_line(name + ": add");
			break;
		case one_value::remove:
			out.add_to_line(name + ": remove");
			break;
		case one_value::search:
			out.add_to_line(name + ": search");
			break;
		default:
			out.add_to_line("BRAK NAZWY FUNKCJI !!!!!!!!!!!!!!!");
	}
	out.new_line();
	out.add_to_line("Ilosc_elementow");
	out.add_to_line("czas_(ns)");
	out.new_line();
	for (auto currently_nuber_of_elements : number_of_elements)
	{
		out.add_to_line(to_string(currently_nuber_of_elements));
		T testing_container;
		key_type data_to_insertion = randomizer::random(std::numeric_limits<key_type>::min(),
		                                                std::numeric_limits<key_type>::max());
		testing_container.generate(currently_nuber_of_elements);
		long position = randomizer::random(0, currently_nuber_of_elements - 1);// TODO
		key_type for_search = testing_container.get(position);
		t.start();
		if (function_type == one_value::add_end)
			testing_container.add_end(data_to_insertion);
		else if (function_type == one_value::add_begin)
			testing_container.add_begin(data_to_insertion);
		else if (function_type == one_value::remove_begin)
			testing_container.remove_begin();
		else if (function_type == one_value::remove_end)
			testing_container.remove_end();
		else if (function_type == one_value::add)
			testing_container.add(data_to_insertion, position);
		else if (function_type == one_value::remove)
			testing_container.remove(position);
		else if (function_type == one_value::search)
			testing_container.search(for_search);
		t.stop();
		out.add_to_line(to_string(t.return_last_in_ns()));
		out.new_line();
	}
}

void performance_test::run_table(CSV_output &out)
{
	out.add_to_line("TABLICA:");
	out.new_line();
	vector<long> number_of_elements{100, 500, 1000, 2500}; //, 5000, 7500, 10000, 18000, 25000, 50000};
	tab_list_mod_one_value<table>(one_value::add_begin, string("Tablica"), out, number_of_elements);
	tab_list_mod_one_value<table>(one_value::add_end, string("Tablica"), out, number_of_elements);
	tab_list_mod_one_value<table>(one_value::remove_begin, string("Tablica"), out, number_of_elements);
	tab_list_mod_one_value<table>(one_value::remove_end, string("Tablica"), out, number_of_elements);
	tab_list_mod_one_value<table>(one_value::add, string("Tablica"), out, number_of_elements);
	tab_list_mod_one_value<table>(one_value::remove, string("Tablica"), out, number_of_elements);
	tab_list_mod_one_value<table>(one_value::search, string("Tablica"), out, number_of_elements);
}

void performance_test::run_list(CSV_output &out)
{
}

void performance_test::run_heap(CSV_output &out)
{
}
