#include <string>
#include <iostream>
using namespace std;

class tours {
public:
  void setTours(fstream& namefile);
  void read(fstream& namefile);
  void reserv(fstream& namefile);
  void del(fstream& namefile);
  void search(fstream& namefile);
  int menu();
  friend ostream& operator<< (ostream &out, const tours &t) {
    out << t.country << ' ' << t.town << ' ' << t.hotel << " Звезд: " << t.stars << " Мест в отеле: " << t.places << " Свободных мест: " << t.freeplaces << endl;
    return out;
  }
  friend istream& operator>> (istream &in, tours &t) {
    cout << "Введите страну: " << endl;
    in >> t.country;
    cout << "Введите город: " << endl;
    in >> t.town;
    cout << "Введите отель: " << endl;
    in >> t.hotel;
    cout << "Сколько звезд у отеля: " << endl;
    in >> t.stars;
    cout << "Сколько мест в отеле: " << endl;
    in >> t.places;
    cout << "Сколько свободных мест в отеле: " << endl;
    in >> t.freeplaces;
    return in;
  }
private:
  string country;
  string town;
  string hotel;
  int stars;
  int places;
  int freeplaces;
};
