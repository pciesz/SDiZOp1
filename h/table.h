#ifndef SDIZOP1_TABLE_H
#define SDIZOP1_TABLE_H

#include "main.h"

class table : public data_structure {
  long table_size;
  unique_ptr<key_type[]> container;
public:
  table() : data_structure() {
	table_size = 0;
	name = "Tablica";
	container = nullptr;
  }

  void menu();
  void print();
  void generate(const long number);
  void read_from_file(const string &name);
  long size() { return table_size; };
  key_type get(const long index) {
	if (index > table_size || index < 0)
	  throw std::range_error("");
	return container[index];
  };
  void add_begin(const key_type data);
  void add_end(const key_type data);
  void add(const key_type data, const long position);
  void remove_begin();
  void remove_end();
  void remove(const long position);
  long search(const key_type value);
  void clear();
};

#endif //SDIZOP1_TABLE_H
