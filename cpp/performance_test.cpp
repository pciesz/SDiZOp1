#include "../h/performance_test.h"

constexpr unsigned int repertition = 10;
constexpr unsigned int precision = 10;

void performance_test::run() {
  timer_seconds ts;
  cout.precision(precision);
  ts.start();

  timer_seconds ts_tmp;
  vector <double> times;
  CSV_output out("performance_tests_result.csv");
  ts_tmp.start();
  run_table(out);
  ts_tmp.stop();
  times.push_back(ts_tmp.return_time());

  ts_tmp.start();
  run_list(out);
  ts_tmp.stop();
  times.push_back(ts_tmp.return_time());

  ts_tmp.start();
  run_heap(out);
  ts_tmp.stop();
  times.push_back(ts_tmp.return_time());

  ts_tmp.start();
  run_BST(out);
  ts_tmp.stop();
  times.push_back(ts_tmp.return_time());

  ts.stop();
  cout << "############### REAL TIME: "<< ts.return_time() << endl;
	for(auto x : times)
	  cout << x << endl;
}

template<typename T>
void performance_test::tab_list_mod_one_value(one_value function_type, string name, CSV_output &out,
                                              vector<long> &number_of_elements, bool is_list) {
  switch (function_type) {
  case one_value::add_end:out.add_to_line(name + ": add_end");
	break;
  case one_value::add_begin: out.add_to_line(name + ": add_begin");
	break;
  case one_value::remove_begin: out.add_to_line(name + ": remove_begin");
	break;
  case one_value::remove_end: out.add_to_line(name + ": remove_end");
	break;
  case one_value::add: out.add_to_line(name + ": add");
	break;
  case one_value::remove: out.add_to_line(name + ": remove");
	break;
  case one_value::search: out.add_to_line(name + ": search");
	break;
  default: out.add_to_line("BRAK NAZWY FUNKCJI !!!!!!!!!!!!!!!");
  }
  out.new_line();
  out.add_to_line("Ilosc_elementow");
  out.add_to_line("czas_(ns)");
  vector<double> result_time(number_of_elements.size());
  out.new_line();
  for (unsigned int j = 0; j < repertition; ++j) {
	T testing_container;
	key_type data_to_insertion = randomizer::random(std::numeric_limits<key_type>::min(),
	                                                std::numeric_limits<key_type>::max());
	testing_container.generate(number_of_elements[0]);
	for (unsigned int k = 0; k < number_of_elements.size(); ++k) {
	  for (int i = testing_container.size(); i <= number_of_elements[k]; ++i)
		testing_container.add_end(randomizer::random(std::numeric_limits<key_type>::min(),
		                                             std::numeric_limits<key_type>::max()));
	  long position = randomizer::random(0, number_of_elements[k] - 1);
	  key_type for_search = testing_container.get(position);
	  t.start();
	  if (function_type==one_value::add_end)
		testing_container.add_end(data_to_insertion);
	  else if (function_type==one_value::add_begin)
		testing_container.add_begin(data_to_insertion);
	  else if (function_type==one_value::remove_begin)
		testing_container.remove_begin();
	  else if (function_type==one_value::remove_end)
		testing_container.remove_end();
	  else if (function_type==one_value::add)
		if (is_list)
		  testing_container.add(data_to_insertion, for_search);
		else
		  testing_container.add(data_to_insertion, position);
	  else if (function_type==one_value::remove)
		if (is_list)
		  testing_container.remove(for_search);
		else
		  testing_container.remove(position);
	  else if (function_type==one_value::search)
		testing_container.search(for_search);
	  t.stop();
	  result_time[k] += t.return_last_in_ns();
	}
  }
  for (unsigned int l = 0; l < number_of_elements.size(); ++l) {
	out.add_to_line(to_string(number_of_elements[l]));
	out.add_to_line(to_string(result_time[l]/repertition));
	out.new_line();
  }
}

void performance_test::run_table(CSV_output &out) {
  out.add_to_line("TABLICA:");
  out.new_line();
  vector<long> number_of_elements;
  for (long i = 500; i <= 5000; i += 500)
	number_of_elements.push_back(i);
  tab_list_mod_one_value<table>(one_value::add_begin, string("Tablica"), out, number_of_elements);
  tab_list_mod_one_value<table>(one_value::add_end, string("Tablica"), out, number_of_elements);
  tab_list_mod_one_value<table>(one_value::remove_begin, string("Tablica"), out, number_of_elements);
  tab_list_mod_one_value<table>(one_value::remove_end, string("Tablica"), out, number_of_elements);
  tab_list_mod_one_value<table>(one_value::add, string("Tablica"), out, number_of_elements);
  tab_list_mod_one_value<table>(one_value::remove, string("Tablica"), out, number_of_elements);
  tab_list_mod_one_value<table>(one_value::search, string("Tablica"), out, number_of_elements);
}

void performance_test::run_list(CSV_output &out) {
  out.add_to_line("LISTA:");
  out.new_line();
  vector<long> number_of_elements;
  for (long i = 500; i <= 50000; i += 500)
	number_of_elements.push_back(i);
  tab_list_mod_one_value<list>(one_value::add_begin, string("Lista"), out, number_of_elements, true);
  tab_list_mod_one_value<list>(one_value::add_end, string("Lista"), out, number_of_elements, true);
  tab_list_mod_one_value<list>(one_value::remove_begin, string("Lista"), out, number_of_elements, true);
  tab_list_mod_one_value<list>(one_value::remove_end, string("Lista"), out, number_of_elements, true);
  tab_list_mod_one_value<list>(one_value::add, string("Lista"), out, number_of_elements, true);
  tab_list_mod_one_value<list>(one_value::remove, string("Lista"), out, number_of_elements, true);
  tab_list_mod_one_value<list>(one_value::search, string("Lista"), out, number_of_elements, true);
}

void performance_test::heap_mod_one_value(one_value function_type, CSV_output &out, vector<long> &number_of_elements) {
  switch (function_type) {
  case one_value::add: out.add_to_line("Kopiec: add");
	break;
  case one_value::remove: out.add_to_line("Kopiec: remove_top");
	break;
  case one_value::search: out.add_to_line("Kopiec: search");
	break;
  default: out.add_to_line("BRAK NAZWY FUNKCJI !!!!!!!!!!!!!!!");
  }
  out.new_line();
  out.add_to_line("Ilosc_elementow");
  out.add_to_line("czas_(ns)");
  vector<double> result_time(number_of_elements.size());
  out.new_line();
  for (unsigned int j = 0; j < repertition; ++j) {
	heap testing_container;
	key_type data_to_insertion = randomizer::random(std::numeric_limits<key_type>::min(),
	                                                std::numeric_limits<key_type>::max());
	testing_container.generate(number_of_elements[0]);
	for (unsigned int k = 0; k < number_of_elements.size(); ++k) {
	  for (int i = testing_container.size(); i <= number_of_elements[k]; ++i)
		testing_container.add(randomizer::random(std::numeric_limits<key_type>::min(),
		                                         std::numeric_limits<key_type>::max()));
	  long position = randomizer::random(0, number_of_elements[k] - 1);
	  key_type for_search = testing_container.get(position);
	  t.start();
	  if (function_type==one_value::add)
		testing_container.add(data_to_insertion);
	  else if (function_type==one_value::remove)
		testing_container.remove_top();
	  else if (function_type==one_value::search)
		testing_container.search(for_search);
	  t.stop();
	  result_time[k] += t.return_last_in_ns();
	}
  }
  for (unsigned int l = 0; l < number_of_elements.size(); ++l) {
	out.add_to_line(to_string(number_of_elements[l]));
	out.add_to_line(to_string(result_time[l]/repertition));
	out.new_line();
  }
}

void performance_test::run_heap(CSV_output &out) {
  out.add_to_line("KOPIEC:");
  out.new_line();
  vector<long> number_of_elements;
  for (long i = 50; i <= 50000; i += 50)
	number_of_elements.push_back(i);
  heap_mod_one_value(one_value::add, out, number_of_elements);
  heap_mod_one_value(one_value::remove, out, number_of_elements);
  heap_mod_one_value(one_value::search, out, number_of_elements);
}

void performance_test::BST_mod_one_value(one_value function_type, CSV_output &out, vector<long> &number_of_elements) {
  switch (function_type) {
  case one_value::add: out.add_to_line("BST: add");
	break;
  case one_value::remove: out.add_to_line("BST: remove");
	break;
  case one_value::search: out.add_to_line("BST: search");
	break;
  default: out.add_to_line("BRAK NAZWY FUNKCJI !!!!!!!!!!!!!!!");
  }
  out.new_line();
  out.add_to_line("Ilosc_elementow");
  out.add_to_line("czas_(ns)");
  vector<double> result_time(number_of_elements.size());
  out.new_line();
  for (unsigned int j = 0; j < repertition; ++j) {
	BST testing_container;
	key_type data_to_insertion = randomizer::random(std::numeric_limits<key_type>::min(),
	                                                std::numeric_limits<key_type>::max());
	testing_container.generate(number_of_elements[0]);
	for (unsigned int k = 0; k < number_of_elements.size(); ++k) {
	  for (int i = testing_container.size(); i < number_of_elements[k]; ++i)
		testing_container.add(randomizer::random(std::numeric_limits<key_type>::min(),
		                                         std::numeric_limits<key_type>::max()));

	  key_type for_search = randomizer::random(std::numeric_limits<key_type>::min(), std::numeric_limits<key_type>::max());
	  testing_container.add(for_search);
	  t.start();
	  if (function_type==one_value::add)
		testing_container.add(data_to_insertion);
	  else if (function_type==one_value::remove)
		testing_container.remove(for_search);
	  else if (function_type==one_value::search)
		testing_container.search(for_search);
	  t.stop();
	  result_time[k] += t.return_last_in_ns();
	}
  }
  for (unsigned int l = 0; l < number_of_elements.size(); ++l) {
	out.add_to_line(to_string(number_of_elements[l]));
	out.add_to_line(to_string(result_time[l]/repertition));
	out.new_line();
  }
}

void performance_test::run_BST(CSV_output &out) {
  out.add_to_line("BST:");
  out.new_line();
  vector<long> number_of_elements;
  for (long i = 50; i <= 50000; i += 50)
	number_of_elements.push_back(i);
  BST_mod_one_value(one_value::add, out, number_of_elements);
  BST_mod_one_value(one_value::remove, out, number_of_elements);
  BST_mod_one_value(one_value::search, out, number_of_elements);
}
