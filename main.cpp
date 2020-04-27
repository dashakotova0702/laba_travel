#include <iostream>
#include <fstream>
#include "base.h"
using namespace std;

int menu();
int searchmenu();

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    cout << "Неверное количество параметров" << endl;
    return 1;
  }
  string namefile = argv[1];
  int choice;
  for(;;) {
    fstream file;
    file.open(namefile, ios::binary | ios::app | ios::in);
    if (!(file.is_open())){
      cout << "Ошибка открытия файла" << endl;
      return 1;
    }
    tours* t = new tours;
    choice = menu();
    switch(choice) {
      case 1:
        t->setTours(file);
        file.close();
        delete t;
        break;
      case 2:
        t->read(file);
        file.close();
        delete t;
        break;
      case 3:
        t->search(file);
        file.close();
        delete t;
			  break;
			case 4:
        t->del(file, namefile);
        file.close();
        delete t;
				break;
			case 5:
        t->reserv(file, namefile);
        file.close();
        delete t;
				break;
			case 6:
        exit (0);
			default:
        cout << "Неправильно введено значение" << endl;
				break;
    }
  }
  return 0;
}

void tours::search(fstream& file){
  if (file.eof()) {
    cout << "Файл пуст" << endl;
    return;
  }
  tours t;
  int choice;
  for(;;) {
    file.clear();
    file.seekg(0);
    choice = searchmenu();
    switch(choice) {
      case 1:
        t.s1(file);
        break;
      case 2:
        t.s2(file);
        break;
      case 3:
        t.s3(file);
        break;
      case 4:
        t.s4(file);
        break;
      case 5:
        t.s5(file);
        break;
      case 6:
        t.s6(file);
        break;
      case 7:
        return;
    }
  }
}
