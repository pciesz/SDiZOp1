#include "../h/table.h"

table::table() : data_structure()
{
	table_size = 0;
	name = "Tablica";
	container = nullptr;
	// TODO
}

table::~table()
{
	// TODO
}

void table::menu()
{
	// TODO
}

void table::print()
{
	cout << name << " - zawartosc: ";
	if (table_size == 0)
	{
		cout << "Pusta tablica" << endl;
		return;
	}
	for (int i = 0; i < table_size; ++i)
		cout << endl << i << ": " << container[i] << "    ";
	cout << endl;
}

void table::generate(const long number)
{
	// TODO
}

void table::read_from_file(const string &name)
{
	// TODO
}

void table::add_end(const key_type data)
{
	++table_size;
	unique_ptr<key_type[]> tmp{new key_type[table_size]};
	for (int i = 0; i < table_size - 1; ++i)
		tmp[i] = container[i];
	tmp[table_size - 1] = data;
	container = std::move(tmp);
}

void table::add_begin(const key_type data)
{
	++table_size;
	unique_ptr<key_type[]> tmp{new key_type[table_size]};
	tmp[0] = data;
	for (int i = 1; i < table_size; ++i)
		tmp[i] = container[i - 1];
	container = std::move(tmp);
}

void table::add(const key_type data, const long position)
{
	++table_size;
	unique_ptr<key_type[]> tmp{new key_type[table_size]};
	for (int i = 0; i < position; ++i)
		tmp[i] = container[i];
	tmp[position] = data;
	for (int i = position + 1; i < table_size; ++i)
		tmp[i] = container[i - 1];
	container = std::move(tmp);
}

void table::remove_begin()
{
	--table_size;
	unique_ptr<key_type[]> tmp{new key_type[table_size]};
	for (int i = 0; i < table_size; ++i)
		tmp[i] = container[i + 1];
	container = std::move(tmp);
}

void table::remove_end()
{
	--table_size;
	unique_ptr<key_type[]> tmp{new key_type[table_size]};
	for (int i = 0; i < table_size; ++i)
		tmp[i] = container[i];
	container = std::move(tmp);
}

void table::remove(const long position)
{
	--table_size;
	unique_ptr<key_type[]> tmp{new key_type[table_size]};
	for (int i = 0; i < position; ++i)
		tmp[i] = container[i];
	for (int i = position + 1; i < table_size + 1; ++i)
		tmp[i - 1] = container[i];
	container = std::move(tmp);
}

long table::search(const key_type value)
{
	for (int i = 0; i < table_size; ++i)
		if (container[i] == value)
			return i;
	// TODO wyjatek zamiast wartosci
	return -1;
}