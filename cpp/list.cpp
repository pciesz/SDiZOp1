#include "../h/list.h"

void list::menu()
{
	bool work = true;
	while (work)
	{
		print();

		data_structure::menu();
		cout << "1. Wczytaj z pliku" << endl;
		cout << "2. Generuj dane" << endl;
		cout << "3. Dodaj element na poczatku listy" << endl;
		cout << "4. Dodaj element na koncu listy" << endl;
		cout << "5. Dodaj element w wybranym miejcu" << endl;
		cout << "6. Usun element na poczatku" << endl;
		cout << "7. Usun element na koncu" << endl;
		cout << "8. Usun wybrany element" << endl;
		cout << "9. Wyszukaj" << endl;
		cout << "c. Wyczysc liste" << endl;
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
					add_begin(key);
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '4':
				try
				{
					cout << "Podaj, co chcesz dodac: ";
					key_type key;
					cin >> key;
					add_end(key);
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '5':
				try
				{
					cout << "Podaj, co chcesz dodac: ";
					key_type key;
					cin >> key;
					cout << "Podaj element, po ktorym dodac: ";
					key_type pos;
					cin >> pos;
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
					cout << "Podaj usuwany element: ";
					key_type pos;
					cin >> pos;
					remove(pos);
				} catch (const std::exception &e) { std::cerr << " Blad: " << e.what() << '\n'; }
				break;
			case '9':
				try
				{
					cout << "Podaj szukana: ";
					key_type find;
					cin >> find;
					cout << (search(find) ? "Znaleziono" : "Nie znaleziono") << endl;
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

void list::print()
{
	cout << name << " - zawartosc: ";
	node *tmp = head;
	if (tmp == nullptr)
	{
		cout << "\nPusta " << name << endl;
		return;
	}
	while (tmp != nullptr)
	{
		cout << endl << tmp->key << "    ";
		tmp = tmp->next;
	}
	cout << endl;
}

#include "../h/randomizer.h"

void list::generate(const long number)
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

void list::read_from_file(const string &name)
{
	read_file file(name);
	raw_data raw = file.read();
	clear();
	for (auto x : raw.data)
		add_end(x);
}

void list::add_end(const key_type data)
{
	node *new_element = new node(data, nullptr, tail);
	if (tail)
		tail->next = new_element;
	tail = new_element;
	if (!head)
		head = tail;
}

void list::add_begin(const key_type data)
{
	node *new_element = new node(data, head, nullptr);
	if (head)
		head->prev = new_element;
	head = new_element;
	if (!tail) tail = head;
}

void list::add(const key_type add, const key_type to_find)
{
	node *new_element = new node(add, nullptr, nullptr);;

	node *old_element = search_node(to_find);

	new_element->prev = old_element;
	new_element->next = old_element->next;
	old_element->next = new_element;
	if (new_element->next)
		new_element->next->prev = new_element;
	else
		tail = new_element;
}

void list::remove_begin()
{
	if (head == nullptr)
		throw std::range_error("Lista pusta");
	else
		head = head->next;
	// TODO co z delete?
}

void list::remove_end()
{
	if (tail == nullptr)
		throw std::range_error("Lista pusta");
	else
	{
		if (tail->prev)
			tail->prev->next = nullptr;
		tail = tail->prev;
	}
	// TODO co z delete?
}

void list::remove(const key_type key)
{
	node *to_remove = search_node(key);
	if (to_remove->prev)
		to_remove->prev->next = to_remove->next;
	else
		head = to_remove->next;
	if (to_remove->next)
		to_remove->next->prev = to_remove->prev;
	else
		tail = to_remove->prev;

	// TODO co z delete?
}

list::node *list::search_node(const key_type value)
{
	node *tmp = head;
	if (tmp == nullptr)
		throw std::range_error("");

	while (tmp != nullptr)
	{
		if (tmp->key == value)
			return tmp;
		tmp = tmp->next;
	}
	throw std::range_error("");
}

bool list::search(const key_type value)
{
	try
	{
		search_node(value);
		return true;
	}
	catch (const std::exception &e)
	{
		return false;
	}
}

void list::clear()
{
	while (tail != nullptr)
		remove_end();
}
