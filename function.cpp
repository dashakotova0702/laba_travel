#include <iostream>
#include <fstream>
#include <vector>
#include "base.h"
using namespace std;

void tours::setTours(fstream& file) {
  tours t;
  cin >> t;
  file.write((char*)&t, sizeof (tours));
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
  cout << parameter;
  while (file.read((char*)&t, sizeof (tours))) {
    if (parameter == t.country)  {
      cout << t;
    }
  }
}

void tours::s2(fstream& file){
  tours t;
  string parameter, town;
  town = t.town;
  cout << "Туры в какой город вывести?" << endl;
  cin >> parameter;
  while (file.read((char*)&t, sizeof (tours))) {
    if (parameter == town) {
      cout << t;
    }
  }
}

void tours::s3(fstream& file){
  tours t;
  string parameter, hotel;
  hotel = t.hotel;
  cout << "Туры в какой отель вывести?" << endl;
  cin >> parameter;
  while (file.read((char*)&t, sizeof (tours))) {
    if (parameter == hotel) {
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
  file.close();
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
  fstream f;
  f.open("f.bin", ios::binary | ios::out);
  tours t;
  string parameter, hotel;
  int i;
  int count1 = 0;
  int count2 = 0;
  cout << "В какой отель тур удалить?: " << endl;
  cin >> parameter;
  while (file.read((char*)&t, sizeof (tours))) {
    hotel = t.hotel;
    if (parameter != hotel) {
      f.write((char*)&t, sizeof (t));
      count2++;
      }
  }
  if (f.eof()){
    return;
  }
  i = 0;
  for (i = 0; i < count2-1; i++){
    file.close();
    fstream file;
    file.open(namefile, ios::binary | ios::out);
    f.read((char*)&t, sizeof (t));
    file.write((char*)&t, sizeof (t));
  }
  f.close();
  remove("f.bin");
}
