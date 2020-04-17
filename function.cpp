#include <iostream>
#include <fstream>
#include "base.h"
using namespace std;

int tours::menu() {
  int c;
  cout << "1. Ввести тур" << endl << "2. Посмотреть все туры" << endl << "3. Поиск туров" << endl << "4. Удаление тура" << endl << "5. Бронирование тура" << endl << "6. Выход" << endl;
  do {
    cout << "Введите номер нужного пункта: ";
    cin >> c;
  } while (c<0 || c>7);
  return c;
}

void tours::setTours(fstream& namefile) {
  tours t;
  cin >> t;
  namefile.write((char*)&t, sizeof (t));
}

void tours::read(fstream& namefile) {
  if (namefile.is_open() == NULL) {
    cout << "Файл пуст" << endl;
    exit(0);
  }
  tours t;
  while(!namefile.eof()) {
    namefile.read((char*)&t, sizeof (t));
    cout << t;
  }
}
