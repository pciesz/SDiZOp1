#ifndef SDIZOP1_CSV_OUTPUT_H
#define SDIZOP1_CSV_OUTPUT_H

#include "main.h"
#include <fstream>
#include <cmath>

class CSV_output
{
	std::ofstream out;
public:
	CSV_output(string name)
	{
		out.open(name, out.out | out.trunc);
		if (!out.is_open())
			cout << "failed to open " << name << endl;
	}

	~CSV_output()
	{
		out.close();
	}

	void add_to_line(string data)
	{
		out << data << "\t";
		cout << data << "\t";
	}

	void new_line()
	{
		out << '\n';
		cout << '\n';
	}
};
#endif //SDIZOP1_CSV_OUTPUT_H
