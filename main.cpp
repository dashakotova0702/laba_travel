#include <iostream>
#include "base.h"
using namespace std;

int main(int argc, char const *argv[]) {
  if (argc != 1) {
    cout << "Неверное количество параметров" << endl;
    return 1;
  }
  int choice;
  tours* t = new tours;
  for(;;) {
    choice = t->menu();
    switch(choice) {
      case 1:
        t->setTours();
        break;
      case 2:
        t->read();
        break;
/*      case 3:
        t->search();
			  break;
			case 4:
        t->del();
				break;
			case 5:
        t->reserv();
				break;*/
			case 6:
        exit(0);
			default:
        cout << "Неправильно введено значение" << endl;
				break;
    }
  }
  return 0;
}
