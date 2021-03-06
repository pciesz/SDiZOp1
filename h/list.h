#ifndef SDIZOP1_LIST_H
#define SDIZOP1_LIST_H

#include "main.h"

class list : public data_structure {
  class node {
  public:
	node *next;
	node *prev;
	key_type key;

	node() : next(nullptr), prev(nullptr) {}

	node(const key_type &k, node *n, node *p) : key(k) {
	  next = n;
	  prev = p;
	}
  };
  node *head;
  node *tail;
  long size_data;
  node *search_node(const key_type value);
public:
  list() : data_structure(), head(nullptr), tail(nullptr), size_data(0) {
	name = "Lista";
  }
  ~list() {
	clear();
  }

  void menu() override;
  void print() override;
  void generate(const long number) override;
  void read_from_file(const string &name) override;
  void add_begin(const key_type data);
  void add_end(const key_type data);
  void add(const key_type add, const key_type to_find);
  void remove_begin();
  void remove_end();
  void remove(const key_type key);
  bool search(const key_type value);
  void clear();
  long size();
  key_type get(long position); // performance tests
  bool empty() {
	if (head!=nullptr || tail!=nullptr)
	  return false;
	return true;
  }
};
#endif //SDIZOP1_LIST_H
