#ifndef SDIZOP1_BST_H
#define SDIZOP1_BST_H

#include "main.h"

class BST : public data_structure {
  class node {
  public:
	node *left;
	node *right;
	key_type key;
	node() : left(nullptr), right(nullptr) {}
	node(const key_type &k, node *l, node *r) : key(k) {
	  left = l;
	  right = r;
	}
  };
  long BST_size = 0;
  void clear_node(node *n);
  void delete_by_merging(node *&n);
  void print(node *n, string prefix, int depth);
  // TODO
 /* void rotate_left(const node * n);
  void rotate_right(const node * n);
  node* search_node(const key_type value);*/
public:
  node *root = nullptr;
  BST() : data_structure() { name = "Drzewo BST"; }
  ~BST() { clear(); }
  BST(vector<key_type> &v) : data_structure() {
	name = "Drzewo BST";
	for (auto x : v)
	  add(x);
  }
  void menu() override;
  void print() override;
  void generate(const long number) override;
  void read_from_file(const string &name) override;
  void add(const key_type key);
  void remove(const key_type key);
  bool search(const key_type value);
  long size() { return BST_size; }
  void clear() {
	clear_node(root);
	delete root;
	root = nullptr;
	BST_size = 0;
  }
  // TODO
  /*void rotate_left(const key_type key);
  void rotate_right(const key_type key);*/
};

#endif //SDIZOP1_BST_H
