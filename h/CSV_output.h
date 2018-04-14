#ifndef SDIZOP1_CSV_OUTPUT_H
#define SDIZOP1_CSV_OUTPUT_H

#include "main.h"
#include <fstream>
#include <cmath>

class CSV_output
{
	// wyjątki TODO
	// wyjątki w innych klasach i main!!!! (spr dokumentację funkcji oraz cout
	std::ofstream out;
public:
	CSV_output(string name)
	{
		out.open(name, out.out | out.trunc);
		if (!out.is_open())
		{
			cout << "failed to open " << name << endl;
		} else
		{
			cout << "File was opened" << endl;
		}
	}

	~CSV_output()
	{
		out.close();
		// TODO wyjątki
	}

	void add_to_line(string data)
	{
		out << data << "\t";
	}

	void new_line()
	{
		out << '\n';
	}
};

#endif //SDIZOP1_CSV_OUTPUT_H
