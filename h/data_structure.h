#ifndef SDIZOP1_DATA_STRUCTURE_H
#define SDIZOP1_DATA_STRUCTURE_H

#include <string>

class data_structure
{
protected:
	string name;

public:
	data_structure()
	{
		name = "nie nadano nazwy struktury!!!";
	}

	virtual void menu()
	{
		cout << name << endl;
		cout << "Operacje:" << endl;
	}

	virtual void print()
	{
		cout << name << endl;
		cout << "Zawartosc:" << endl;
	}

	virtual void generate(__int32_t number) = 0;

	virtual void read_from_file(string name) = 0;
};

#endif //SDIZOP1_DATA_STRUCTURE_H
