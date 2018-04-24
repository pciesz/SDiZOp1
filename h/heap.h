#ifndef SDIZOP1_HEAP_H
#define SDIZOP1_HEAP_H

#include "main.h"

class heap : public data_structure {
  long parent(long i) { return floor((i - 1)/2); }
  long left(long i) { return (2*i + 1); }
  long right(long i) { return (2*i + 2); }
  void max_heapify(unsigned long i);
  void build_max_heap(long n);
  void heap_increase_key(long i, key_type key);
  void print(long position, string prefix, int depth);
public:
  vector<key_type> data;
  heap() : data_structure() {
	name = "Kopiec";
	data = vector<key_type>();
  }

  heap(vector<key_type> &v) : data_structure() {
	name = "Kopiec";
	data = v;
	build_max_heap(data.size() - 1);
  }

  void menu()
  override;
  void print()
  override;
  void generate(const long number)
  override;
  void read_from_file(const string &name)
  override;
  void add(const key_type key);
  key_type remove_top();
  bool search(const key_type value, long node = 0);
  key_type size();
  void clear();
  key_type get(long index); // performance tests
};
#endif //SDIZOP1_HEAP_H
