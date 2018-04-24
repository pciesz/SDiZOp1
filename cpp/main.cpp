#include <gtest/gtest.h>
#include "../h/headers.h"
#include "../h/main.h"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  app::menu();
  return RUN_ALL_TESTS();
}

void app::menu() {
  bool work = true;
  while (work) {
	cout << "____________________\n"
	        "Piotr Cieszko 226079\n"
	        "SDiZO projekt 1\n"
	        "Prowadzacy: mgr inz Antoni Sterna\n"
	        "Menu:\n"
	        "1: Tablica\n"
	        "2: Lista\n"
	        "3: Kopiec binarny\n"
	        "p: Test wydajnosci\n"
	        "0: Koniec pracy programu\n";
	char x;
	cin >> x;
	switch (x) {
	case '1': run_table();
	  break;
	case '2': run_list();
	  break;
	case '3': run_heap();
	  break;
	case 'p': performance_test p;
	  p.run();
	  work = false;
	  break;
	case '0': work = false;
	  break;
	default: cout << "Nieznana opcja" << endl;
	}
  }
}

void app::run_table() {
  table t;
  t.menu();
}

void app::run_list() {
  list l;
  l.menu();
}

void app::run_heap() {
  heap h;
  h.menu();
}
