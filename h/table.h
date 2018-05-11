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

  key_type &operator[](const long index) const{
	if (index > table_size || index < 0)
	  throw std::range_error("");
	return container[index];
  }

  table &operator=(const table &v) {
	table_size = v.size();
	name = "Tablica";
	container.reset(new key_type[table_size]);
	for (int i = 0; i < table_size; ++i)
	  container[i] = v[i];
	return *this;
  }

  table &operator=(const vector<key_type> &v) {
	table_size = v.size();
	name = "Tablica";
	container.reset(new key_type[table_size]);
	for (int i = 0; i < table_size; ++i)
	  container[i] = v[i];
	return *this;
  }

  void menu();
  void print();
  void generate(const long number);
  void read_from_file(const string &name);
  long size() const { return table_size; };
  const key_type get(const long index) const {
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
