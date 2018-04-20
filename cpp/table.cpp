#include "../h/table.h"

void table::menu()
{
	bool work = true;
	while (work)
	{
		print();
		data_structure::menu();
		cout << "1. Wczytaj z pliku" << endl;
		cout << "2. Generuj dane" << endl;
		cout << "3. Dodaj element na poczatku tablicy" << endl;
		cout << "4. Dodaj element na koncu tablicy" << endl;
		cout << "5. Dodaj element w wybranym miejcu" << endl;
		cout << "6. Usun element na poczatku" << endl;
		cout << "7. Usun element na koncu" << endl;
		cout << "8. Usun wybrany element" << endl;
		cout << "9. Wyszukaj" << endl;
		cout << "c. Wyczysc tablice" << endl;
		cout << "0. Wyjdz" << endl;
		char x;
		cin >> x;
		switch (x)
		{
			case '1':
				try
				{
					string name;
					cout << "Podaj nazwe pliku: ";
					cin >> name;
					read_from_file(name);
					cout << "\nWczytano!" << endl;
				} catch (const std::exception &e) { std::cerr << " Blad wczytywania: " << e.what() << '\n'; }
				break;
			case '2':
				try
				{
					cout << "Podaj, ile rekordow wygenerowac: ";
					long i;
					cin_number(i);
					generate(i);
				}
				catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '3':
				try
				{
					cout << "Podaj, co chcesz dodac: ";
					key_type key;
					cin_number(key);
					add_begin(key);
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '4':
				try
				{
					cout << "Podaj, co chcesz dodac: ";
					key_type key;
					cin_number(key);
					add_end(key);
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '5':
				try
				{
					cout << "Podaj, co chcesz dodac: ";
					key_type key;
					cin_number(key);
					cout << "Podaj miejsce w tablicy: ";
					key_type pos;
					cin_number(pos);
					add(key, pos);
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '6':
				try
				{
					remove_begin();
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '7':
				try
				{
					remove_end();
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '8':
				try
				{
					cout << "Podaj miejsce w tablicy: ";
					key_type pos;
					cin_number(pos);
					remove(pos);
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '9':
				try
				{
					cout << "Podaj szukana: ";
					key_type find;
					cin_number(find);
					search(find);
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case 'c':
				clear();
				break;
			case '0':
				work = false;
				break;
			default:
				cout << "Nieznana opcja" << endl;
		}
	}
}

void table::print()
{
	cout << name << ": ";
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
		throw std::range_error("Liczba ponizej zera");
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
		throw std::range_error("Zle miejsce w tablicy");
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
		throw std::range_error("Tablica pusta");
	--table_size;
	unique_ptr<key_type[]> tmp{new key_type[table_size]};
	for (int i = 0; i < table_size; ++i)
		tmp[i] = container[i + 1];
	container = std::move(tmp);
}

void table::remove_end()
{
	if (table_size == 0)
		throw std::range_error("Tablica pusta");
	--table_size;
	unique_ptr<key_type[]> tmp{new key_type[table_size]};
	for (int i = 0; i < table_size; ++i)
		tmp[i] = container[i];
	container = std::move(tmp);
}

void table::remove(const long position)
{
	if (position >= table_size || position < 0)
		throw std::range_error("Niepoprawne miejsce w tablicy");
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
