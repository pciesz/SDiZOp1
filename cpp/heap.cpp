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
					cin_number(i);
					generate(i);
				}
				catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '3':
				try
				{
					cout << "Podaj, co chcesz dodac: ";
					long key;
					cin_number(key);
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
					long find;
					cin_number(find);
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
	cout << name << ": ";
	// TODO wyswietlanie kopca
	printf("\n");
	for (long i = 0; i < data.size(); i++)
	{
		printf("%d\t", data[i]);
	}
	cout << "\n";
}

void heap::generate(const long number)
{
	if (number < 0)
		throw std::range_error("Liczba ponizej zera");
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

key_type heap::size()
{
	return data.size();
}

void heap::clear()
{
	data.clear();
}

void heap::add(const key_type key)
{
	data.push_back(numeric_limits<key_type>::min());
	heap_increase_key(data.size() - 1, key);
}

key_type heap::remove_top()
{
	if (data.size() < 1)
		throw range_error("Kopiec jest pusty");
	key_type max = data[0];
	swap(data[0], data[data.size() - 1]);
	data.pop_back();
	max_heapify(0);
	return max;
}

bool heap::search(const key_type value)
{
	for (auto a:data)
		if (a == value)
			return true;
	return false;
}

void heap::max_heapify(long i)
{
	long l = left(i);
	long r = right(i);
	long largest = i;
	if (l < data.size() && data[i] < data[l])
		largest = l;
	if (r < data.size() && data[largest] < data[r])
		largest = r;
	if (largest != i)
	{
		swap(data[largest], data[i]);
		max_heapify(largest);
	}
}

void heap::build_max_heap(long n)
{
	for (long i = parent(n); i >= 0; i--)
		max_heapify(i);
}

void heap::heap_increase_key(long i, key_type key)
{
	if (data[i] > key)
		throw range_error("Nowy klucz jest zbyt maly (heap_increase_key");
	data[i] = key;
	while (i > 0 && data[parent(i)] < data[i])
	{
		swap(data[parent(i)], data[i]);
		i = parent(i);
	}
}