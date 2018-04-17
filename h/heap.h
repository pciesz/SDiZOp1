#ifndef SDIZOP1_HEAP_H
#define SDIZOP1_HEAP_H
#include "main.h"

class heap : public data_structure
{
	long size_heap;
// TODO destruktor
public:
	heap() : data_structure(), size_heap(0)
	{
		name = "Kopiec";
	}

	void menu() override;

	void print() override;

	void generate(const long number) override;

	void read_from_file(const string &name) override;

	void add(const key_type key);

	key_type remove_top();

	bool search(const key_type value);

	long size();

	void clear();
};

#endif //SDIZOP1_HEAP_H
