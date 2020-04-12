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

void tours::setTours() {
  fstream file;
  file.open("tours.bin", ios_base::binary | ios_base::app); //попыталась передать аргументы из мейн, но ничего не вышло, оставила пока так
  if (!(file.is_open())){
    cout << "Ошибка открытия файла" << endl;
    exit(0);
  }
  else {
    tours t;
    cout << "Введите страну: " << endl;
    cin >> t.country;
    cout << "Введите город: " << endl;
    cin >> t.town;
    cout << "Введите отель: " << endl;
    cin >> t.hotel;
    cout << "Сколько звезд у отеля: " << endl;
    cin >> t.stars;
    cout << "Сколько мест в отеле: " << endl;
    cin >> t.places;
    cout << "Сколько свободных мест в отеле: " << endl;
    cin >> t.freeplaces;
    file.write((char*)&t, sizeof (t));
  }
  file.close();
}

void tours::read() {
  fstream file;
  file.open("tours.bin", ios_base::binary | ios_base::in);
  if (!(file.is_open())){
    cout << "Ошибка открытия файла" << endl;
    exit(0);
  }
  if (file.is_open() == NULL) {
    cout << "Файл пуст" << endl;
    exit(0);
  }
  tours t;
  while(!file.eof()) {
    file.read((char*)&t, sizeof (t));
    cout << t.country << ' ' << t.town << ' ' << t.hotel << " Звезд: " << t.stars << " Мест в отеле: " << t.places << " Свободных мест: " << t.freeplaces << endl;
  } //он снова выводит последнюю строчку два раза, как и в Си. В си функция передавала число, здесь без понятия че функция передает в итоге, поэтому хз как решить проблему
  file.close();
}
