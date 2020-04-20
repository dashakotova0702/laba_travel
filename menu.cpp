#include <iostream>
#include <fstream>
#include "base.h"
using namespace std;

int menu() {
  int c;
  cout << "1. Ввести тур" << endl << "2. Посмотреть все туры" << endl << "3. Поиск туров" << endl << "4. Удаление тура" << endl << "5. Бронирование тура" << endl << "6. Выход" << endl;
  do {
    cout << "Введите номер нужного пункта: ";
    cin >> c;
  } while (c<0 || c>7);
  return c;
}

int searchmenu() {
  int c;
  cout << "1. Страна" << endl << "2. Город" << endl << "3. Отель" << endl << "4. Звезды" << endl << "5. Общее количество мест" << endl << "6. Свободные места" << endl << "7. Выйти" << endl;
  do {
    cout << endl << "Введите номер параметра для поиска: ";
    cin >> c;
  } while (c<0 || c>8);
  return c;
}
