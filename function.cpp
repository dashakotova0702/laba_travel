#include <iostream>
#include <fstream>
#include <string.h>
#include "base.h"
using namespace std;

void tours::setTours(fstream& file) {
  tours t;
  cin >> t;
  file.write((char*)&t, sizeof (tours));
  cout << "Вы успешно записали тур" << endl;
}

void tours::read(fstream& file) {
  if (file.eof()) {
    cout << "Файл пуст" << endl;
    return;
  }
  tours t;
  while (file.read((char*)&t, sizeof (tours))) {
    cout << t;
  }
}

void tours::s1(fstream& file){
  tours t;
  char parameter[20];
  cout << "Туры в какую страну вывести? " << endl;
  cin >> parameter;
  while (file.read((char*)&t, sizeof (tours))) {
    if (strcmp(parameter, t.country) == 0)  {
      cout << t;
    }
  }
}

void tours::s2(fstream& file){
  tours t;
  char parameter[20];
  cout << "Туры в какой город вывести?" << endl;
  cin >> parameter;
  while (file.read((char*)&t, sizeof (tours))) {
    if (strcmp(parameter, t.town) == 0) {
      cout << t;
    }
  }
}

void tours::s3(fstream& file){
  tours t;
  char parameter[20];
  cout << "Туры в какой отель вывести?" << endl;
  cin >> parameter;
  while (file.read((char*)&t, sizeof (tours))) {
    if (strcmp(parameter, t.hotel) == 0) {
      cout << t;
    }
  }
}

void tours::s4(fstream& file){
  tours t;
  int parameter;
  cout << "С каким количеством звезд отели вывести?: ";
  cin >> parameter;
  while (file.read((char*)&t, sizeof (tours))) {
    if (parameter == t.stars) {
      cout << t;
    }
  }
}

void tours::s5(fstream& file){
  tours t;
  int parameter;
  cout << "С каким количеством мест отели вывести?" << endl;
  cin >> parameter;
  while (file.read((char*)&t, sizeof (tours))) {
    if (parameter == t.places){
      cout << t;
    }
  }
}

void tours::s6(fstream& file){
  tours t;
  int parameter;
  cout << "С каким количеством свободных мест отели вывести?" << endl;
  cin >> parameter;
  while (file.read((char*)&t, sizeof (tours))) {
    if (parameter == t.freeplaces){
      cout << t;
    }
  }
}

void tours::del(fstream& file, string namefile) {
  if (file.eof()) {
    cout << "Файл пуст" << endl;
    return;
  }
  int i = 0, size = 0;
  char parameter[20];
  file.clear();
  file.seekg(0);
  tours count;
  while (file.read((char*)&count, sizeof (count))) {
    size++;
  }
  tours* t = new tours[size];
  file.clear();
  file.seekg(0);
  cout << "Тур в какой отель удалить?: " << endl;
  cin >> parameter;
  for (i = 0; i < size; i++) {
    file.read((char*)&t[i], sizeof (t[i]));
  }
  file.close();
  file.open(namefile, ios_base::binary | ios_base::out | ios_base::trunc);
  for (i = 0; i < size; i++) {
    if (strcmp(parameter, t[i].hotel) != 0) {
      file.write((char*)&t[i], sizeof (t[i]));
    }
  }
  cout << "Вы успешно удалили тур" << endl;
  delete []t;
}

void tours::reserv(fstream& file, string namefile) {
  if (file.eof()) {
    cout << "Файл пуст" << endl;
    return;
  }
  int i = 0, size = 0, reserv_places;
  char parameter[20];
  tours count;
  file.clear();
  file.seekg(0);
  while (file.read((char*)&count, sizeof (count))) {
    size++;
  }
  tours* t = new tours[size];
  file.clear();
  file.seekg(0);
  for (i = 0; i < size; i++) {
    file.read((char*)&t[i], sizeof (t[i]));
  }
  file.close();
  file.open(namefile, ios_base::binary | ios_base::out | ios_base::trunc);
  cout << "Какой отель хотите забронировать?: " << endl;
  cin >> parameter;
  cout << "Сколько мест забронировать?: " << endl;
  cin >> reserv_places;
  for (i = 0; i < size; i++) {
    if (strcmp(parameter, t[i].hotel) == 0) {
      if (t[i].freeplaces < reserv_places) {
        cout << "В отеле нет столько мест. Ошибка" << endl;
        file.write((char*)&t[i], sizeof (t[i]));
      }
      else {
        cout << "Вы успешно забронировали отель" << endl;
        t[i].freeplaces -= reserv_places;
        file.write((char*)&t[i], sizeof (t[i]));
      }
    }
    else {
      file.write((char*)&t[i], sizeof (t[i]));
    }
  }
  delete []t;
}
