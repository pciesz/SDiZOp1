#ifndef SDIZOP1_READ_FILE_H
#define SDIZOP1_READ_FILE_H

#include "main.h"
#include <fstream>
#include <cmath>
#include <vector>
#include <array>

struct raw_data
{
	long size;
	vector<key_type> data;
};
class read_file
{
	ifstream in;
public:
	read_file(const string &name)
	{
		in.open(name);
		if (!in.is_open())
		{
			cout << "failed to open " << name << endl;
			return;
		}
			return;
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
			throw std::logic_error("Unable to open file");
		string tmp;
		in >> tmp;
		raw.size = stol(tmp);
		if (raw.size < 0)
			throw std::logic_error("Size below 0");
		for (long i = 0; i < raw.size; i++)
		{
			if (in.eof())
				throw std::logic_error("File too short!");
			in >> tmp;
			raw.data.push_back(stol(tmp));
		}
		return raw;
	}
};
#endif //SDIZOP1_READ_FILE_H
