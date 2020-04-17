#include <iostream>
#include <fstream>
#include "base.h"
using namespace std;

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    cout << "Неверное количество параметров" << endl;
    return 1;
  }
  fstream file;
  file.open(argv[1], ios_base::binary | ios_base::app | ios_base::in);
  if (!(file.is_open())){
    cout << "Ошибка открытия файла" << endl;
    return 1;
  }
  int choice;
  tours* t = new tours;
  for(;;) {
    choice = t->menu();
    switch(choice) {
      case 1:
        t->setTours(file);
        break;
      case 2:
        file.seekg(0);
        t->read(file);
        break;
/*      case 3:
        t->search(file);
			  break;
			case 4:
        t->del(file);
				break;
			case 5:
        t->reserv(file);
				break;*/
			case 6:
        file.close();
        delete t;
        exit(0);
			default:
        cout << "Неправильно введено значение" << endl;
				break;
    }
  }
  return 0;
}
