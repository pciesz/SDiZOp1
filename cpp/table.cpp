#include "../h/table.h"

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

#include "../h/randomizer.h"
void table::generate(const long number)
{
	if (number < 0)
		throw std::range_error("");
	clear();
	for (long i = 0; i < number; ++i)
	{
		add_end(randomizer::random(-1000, 1000));
	}
}

#include "../h/read_file.h"

void table::read_from_file(const string &name)
{
	read_file file(name);
	raw_data raw = file.read();
	clear();
	for (auto x : raw.data)
		add_end(x);
	if (table_size < raw.size)
		while (table_size < raw.size)
			add_end(0);

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
	if (position > table_size || position < 0)
		throw std::range_error("");
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
	if (table_size == 0)
		throw std::range_error("");
	--table_size;
	unique_ptr<key_type[]> tmp{new key_type[table_size]};
	for (int i = 0; i < table_size; ++i)
		tmp[i] = container[i + 1];
	container = std::move(tmp);
}

void table::remove_end()
{
	if (table_size == 0)
		throw std::range_error("");
	--table_size;
	unique_ptr<key_type[]> tmp{new key_type[table_size]};
	for (int i = 0; i < table_size; ++i)
		tmp[i] = container[i];
	container = std::move(tmp);
}

void table::remove(const long position)
{
	if (position >= table_size || position < 0)
		throw std::range_error("");
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
	throw std::logic_error("");
}

void table::clear()
{
	table_size = 0;
	container = nullptr;
}
