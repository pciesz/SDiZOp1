#ifndef SDIZOP1_MAIN_H
#define SDIZOP1_MAIN_H

#include <memory>
#include <sys/types.h>
#include <limits>
#include <algorithm>

typedef int32_t key_type;

#include <iostream>

using namespace std;

#include "data_structure.h"

template<typename T>
void cin_number(T &x) {
  std::cin >> x;
  while (std::cin.fail()) {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Zla wartosc, wpisz liczbe: ";
	std::cin >> x;
  }
}

class app {
public:
  static void menu();
  static void run_table();
  static void run_list();
  static void run_heap();
  static void run_BST();
};
#endif //SDIZOP1_MAIN_H
