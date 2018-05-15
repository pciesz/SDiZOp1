#include "../h/heap.h"
#include "../h/randomizer.h"
#include "../h/read_file.h"

void heap::menu() {
  bool work = true;
  while (work) {
	print();
	data_structure::menu();
	cout << "1. Wczytaj z pliku" << endl;
	cout << "2. Generuj dane" << endl;
	cout << "3. Dodaj element" << endl;
	cout << "4. Usun element ze szczytu" << endl;
	cout << "5. Wyszukaj" << endl;
	cout << "6. Wyczysc" << endl;
	cout << "0. Wyjdz" << endl;
	char x;
	cin >> x;
	switch (x) {
	case '1':
	  try {
		string name;
		cout << "Podaj nazwe pliku: ";
		cin >> name;
		read_from_file(name);
		cout << "\nWczytano!" << endl;
	  } catch (const std::exception &e) {
		std::cerr << " Blad wczytywania: " << e.what() << '\n';
	  }
	  break;
	case '2':
	  try {
		cout << "Podaj, ile rekordow wygenerowac: ";
		long i;
		cin_number(i);
		generate(i);
	  }
	  catch (const std::exception &e) {
		std::cerr << " Blad: " << e.what() << '\n';
	  }
	  break;
	case '3':
	  try {
		cout << "Podaj, co chcesz dodac: ";
		long key;
		cin_number(key);
		add(key);
	  } catch (const std::exception &e) {
		std::cerr << " Blad: " << e.what() << '\n';
	  }
	  break;
	case '4':
	  try {
		cout << "Usunieto: " << remove_top() << endl;
	  } catch (const std::exception &e) {
		std::cerr << " Blad: " << e.what() << '\n';
	  }
	  break;
	case '5':
	  try {
		cout << "Podaj szukana: ";
		long find;
		cin_number(find);
		cout << (search(find) ? "Znaleziono" : "Nie znaleziono") << endl;
	  } catch (const std::exception &e) {
		std::cerr << " Blad: " << e.what() << '\n';
	  }
	  break;
	case '6': clear();
	  break;
	case '0': work = false;
	  break;
	default: cout << "Nieznana opcja" << endl;
	}
  }
}

void heap::print(long position, string prefix, int depth) {
  if (position < data.size()) {
	depth++;
	print(left(position), string("L: "), depth);
	for (int i = 0; i < depth - 1; ++i)
	  cout << "     . ";
	cout << prefix << data[position] << endl;
	print(right(position), string("R: "), depth);
  }
}

void heap::print() {
  cout << name << ": ";
  if (data.size()==0)
	cout << "Kopiec pusty" << endl;
  else {
	cout << '\n';
	print(0, string(""), 0);
  }
  cout << endl;
}

void heap::generate(const long number) {
  if (number < 0)
	throw std::range_error("Liczba ponizej zera");
  clear();
  for (long i = 0; i < number; ++i) {
	add(randomizer::random(-1000, 1000));
  }
}

void heap::read_from_file(const string &name) {
  read_file file(name);
  raw_data raw = file.read();
  clear();
  for (auto x : raw.data)
	add(x);
}

key_type heap::size() {
  return data.size();
}

void heap::clear() {
  data.clear();
}

void heap::fix_up(long i) {
  long largest;
  long l = left(i);
  long r = right(i);
  if (l < size() && data[l] > data[i])
	largest = l;
  else
	largest = i;

  if (r < size() && data[largest] < data[r])
	largest = r;

  if (largest!=i) {
	std::swap(data[i], data[largest]);
    fix_up(largest);
  }
}

void heap::add(const key_type key) {
  data.add_end(key);
  for (int i = size() - 1; i >= 0; i--)
    fix_up(i);
}

key_type heap::remove_top() {
  if (data.size() < 1)
	throw range_error("Kopiec jest pusty");
  key_type max = data[0];
  swap(data[0], data[data.size() - 1]);
  data.remove_end();

  for (int i = size() - 1; i >= 0; i--)
    fix_up(i);
  return max;
}

bool heap::search(const key_type value) {
  for (int i = 0; i < data.size(); ++i)
	if (data[i]==value)
	  return true;
  return false;
}

void heap::build_max_heap(long n) {
  for (long i = parent(n); i >= 0; i--)
	fix_up(i);
}

key_type heap::get(long index) {
  if (index < 0 || index >= data.size())
	throw std::range_error("Zly zakres danych");
  return data[index];
}
