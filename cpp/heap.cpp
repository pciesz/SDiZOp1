#include "../h/heap.h"
#include "../h/randomizer.h"
#include "../h/read_file.h"

void heap::menu()
{
	bool work = true;
	while (work)
	{
		print();

		data_structure::menu();
		cout << "1. Wczytaj z pliku" << endl;
		cout << "2. Generuj dane" << endl;
		cout << "3. Dodaj element" << endl;
		cout << "4. Usun element ze szczytu" << endl;
		cout << "5. Wyszukaj" << endl;
		cout << "6. Wyczysc liste" << endl;
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
					cin >> i;

					generate(i);
				}
				catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '3':
				try
				{
					cout << "Podaj, co chcesz dodac: ";
					key_type key;
					cin >> key;
					add(key);
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '4':
				try
				{
					cout << "Usunieto: " << remove_top() << endl;
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '5':
				try
				{
					cout << "Podaj szukana: ";
					key_type find;
					cin >> find;
					cout << (search(find) ? "Znaleziono" : "Nie znaleziono") << endl;
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '6':
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

void heap::print()
{
	cout << name << " - zawartosc: ";
	// TODO wyswietlanie kopca
}

void heap::generate(const long number)
{
	if (number < 0)
		throw std::range_error("");
	clear();
	for (long i = 0; i < number; ++i)
	{
		add(randomizer::random(-1000, 1000));
	}
}

void heap::read_from_file(const string &name)
{
	read_file file(name);
	raw_data raw = file.read();
	clear();
	for (auto x : raw.data)
		add(x);
}

void heap::add(const key_type key)
{
// TODO
}

key_type heap::remove_top()
{
	// TODO
	return 0;
}

bool heap::search(const key_type value)
{
	// TODO
	return false;
}

long heap::size()
{
	return size_heap;
}

void heap::clear()
{
	while (size_heap > 0)
		remove_top();
}
