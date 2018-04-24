#include "../h/BST.h"
#include "../h/randomizer.h"
#include "../h/read_file.h"

void BST::menu() {
  bool work = true;
  while (work) {
	print();
	data_structure::menu();
	cout << "1. Wczytaj z pliku" << endl;
	cout << "2. Generuj dane" << endl;
	cout << "3. Dodaj element" << endl;
	cout << "4. Usun element" << endl;
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
	  }
	  catch (const std::exception &e) {
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
	  }
	  catch (const std::exception &e) {
		std::cerr << " Blad: " << e.what() << '\n';
	  }
	  break;
	case '4':
	  try {
		cout << "Podaj, co chcesz usunac: ";
		long key;
		cin_number(key);
		remove(key);
	  }
	  catch (const std::exception &e) {
		std::cerr << " Blad: " << e.what() << '\n';
	  }
	  break;
	case '5':
	  try {
		cout << "Podaj szukana: ";
		long find;
		cin_number(find);
		cout << (search(find) ? "Znaleziono" : "Nie znaleziono") << endl;
	  }
	  catch (const std::exception &e) {
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
void BST::print() {
  cout << name << ": ";
  if(root ==nullptr)
    cout << "Drzewo puste" << endl;
  else
    print(root);
  cout << endl;
}
void BST::print(BST::node *n) {
  if (n!=nullptr) {
	print(n->left);
	cout << n->key << " ";
	print(n->right);
  }
}

void BST::generate(const long number) {
  if (number < 0)
	throw std::range_error("Liczba ponizej zera");
  clear();
  for (long i = 0; i < number; ++i) {
	add(randomizer::random(-1000, 1000));
  }
}
void BST::read_from_file(const string &name) {
  read_file file(name);
  raw_data raw = file.read();
  clear();
  for (auto x : raw.data)
	add(x);
}
void BST::clear_node(node *n) {
  if (n==nullptr)
	return;
  if (n->left) {
	clear_node(n->left);
	delete n->left;
	n->left = nullptr;
  }
  if (n->right) {
	clear_node(n->right);
	delete n->right;
	n->right = nullptr;
  }
}
void BST::add(const key_type key) {
  node *n = root;
  node *prev = nullptr;
  while (n!=nullptr) {
	prev = n;
	if (n->key < key)
	  n = n->right;
	else
	  n = n->left;
  }
  if (root==nullptr)
	root = new node(key, nullptr, nullptr);
  else if (prev->key < key)
	prev->right = new node(key, nullptr, nullptr);
  else
	prev->left = new node(key, nullptr, nullptr);
  BST_size++;
}
void BST::remove(const key_type key) {
  // wyszukuje, usuwanie przez złączanie
  node *n = root;
  node *prev = nullptr;
  while (n!=0) {
	if (n->key==key)
	  break;
	prev = n;
	if (n->key < key)
	  n = n->right;
	else
	  n = n->left;
  }
  if (n!=nullptr && n->key==key) {
	if (n==root)
	  delete_by_merging(root);
	else if (prev->left==n)
	  delete_by_merging(prev->left);
	else
	  delete_by_merging(prev->right);
  } else if (root!=nullptr)
	throw std::range_error("Nie znaleziono klucza w drzewie");
  else
	throw std::range_error("Drzewo jest puste");
  BST_size--;
}
void BST::delete_by_merging(node *&n) {
  node *tmp = n;
  if (n!=nullptr) {
	if (!(n->right))
	  n = n->left;
	else if (n->left==nullptr)
	  n = n->right;
	else {
	  tmp = n->right;
	  while (tmp->right!=nullptr)
		tmp = tmp->right;
	  tmp->right = n->right;
	  tmp = n;
	  n = n->left;
	}
	delete tmp;
  }
}

bool BST::search(const key_type value) {
  node *n = root;
  while (n!=nullptr) {
	if (n->key==value)
	  return true;
	else if (value < n->key)
	  n = n->left;
	else
	  n = n->right;
  }
  return false;
}


