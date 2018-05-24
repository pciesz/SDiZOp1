#ifndef SDIZOP1_HEAP_H
#define SDIZOP1_HEAP_H

#include "main.h"
#include "table.h"

class heap : public data_structure {
  long parent(long i) { return floor((i - 1)/2); }
  long left(long i) { return (2*i + 1); }
  long right(long i) { return (2*i + 2); }
  void max_heapify(unsigned long i);
  void build_max_heap(long n);
  void print(long position, string prefix, int depth);
  void fix_down(long index);
  void fix_up(long index);

public:
  table data;
  heap() : data_structure() {
	name = "Kopiec";
  }

  heap(vector<key_type> &v) : data_structure() {
	name = "Kopiec";
	data = v;
	build_max_heap(data.size() - 1);
  }

  void menu() override;
  void print() override;
  void generate(const long number) override;
  void read_from_file(const string &name) override;
  void add(const key_type key);
  key_type remove_top();
  bool search(const key_type value);
  key_type size();
  void clear();
  key_type get(long index); // performance tests
};
#endif //SDIZOP1_HEAP_H
