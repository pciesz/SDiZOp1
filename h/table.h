#ifndef SDIZOP1_TABLE_H
#define SDIZOP1_TABLE_H

#include "main.h"

class table : public data_structure
{
	// smart pointery
public:
	table();

	~table();

	void menu();

	void print();

	void generate(long number);

	void read_from_file(string name);
};

#endif //SDIZOP1_TABLE_H
