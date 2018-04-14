#ifndef SDIZOP1_READ_FILE_H
#define SDIZOP1_READ_FILE_H

#include "main.h"
#include <fstream>
#include <cmath>
#include <vector>
#include <array>


struct raw_data
{
	unsigned long size;
	vector<key_type> data;
};

class read_file
{
	// wyjątki TODO
	// wyjątki w innych klasach i main!!!! (spr dokumentację funkcji oraz cin
	ifstream in;

public:
	read_file(string name)
	{
		in.open(name);
		if (!in.is_open())
		{
			cout << "failed to open " << name << endl;
			return;
		} else
		{
			cout << "File was opened" << endl;
			return;
		}
	}

	~read_file()
	{
		in.close();
		// TODO wyjątki
	}

	raw_data read()
	{
		raw_data raw;
		if (!in.is_open())
			return raw;
// TODO wyjątki, kontrola błędów
		string tmp;
		in >> tmp;
		raw.size = stol(tmp);
		// TODO test czy size > 0
		for (long i = 0; i < raw.size; i++)
		{
			if (in.eof())
				return raw; //TODO rzuć wyjątek
			in >> tmp;
			raw.data.push_back(stol(tmp));
		}
		return raw;
	}
};

#endif //SDIZOP1_READ_FILE_H
