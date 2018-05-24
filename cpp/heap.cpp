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

void heap::fix_down(long index) {
  if (left(index) >= data.size()) //index is a leaf
	return;
  long maximum = index;
  if (data[index] < data[left(index)])
	maximum = left(index);
  if ((right(index) > data.size()) && (data[maximum] > right(index)))
	maximum = right(index);
  if (maximum!=index) {
	std::swap(data[index], data[maximum]);
	fix_down(maximum);
  }
}

void heap::fix_up(long index) {
  if (index==0)
	return;
  if (data[parent(index)] < data[index]) {
	std::swap(data[parent(index)], data[index]);
	fix_up(parent(index));
  }
}

void heap::add(const key_type key) {
  data.add_end(key);
  fix_up(data.size() - 1);
}

key_type heap::remove_top() {
  if (data.size() < 1)
	throw range_error("Kopiec jest pusty");
  key_type max = data[0];
  swap(data[0], data[data.size() - 1]);
  data.remove_end();

  fix_down(0);
  return max;
}

bool heap::search(const key_type value) {
  for (int i = 0; i < data.size(); ++i)
	if (data[i]==value)
	  return true;
  return false;
}

void heap::build_max_heap(long n) {
  for (long i = n; i >= 0; i--)
	fix_up(i);
}

key_type heap::get(long index) {
  if (index < 0 || index >= data.size())
	throw std::range_error("Zly zakres danych");
  return data[index];
}