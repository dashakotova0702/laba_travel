#include <string>
#include <iostream>
using namespace std;

class tours {
public:
  void setTours(fstream& file);
  void read(fstream& file);
  void reserv(fstream& file, string namefile);
  void del(fstream& file, string namefile);
  void search(fstream& file);
  void s1(fstream& file);
  void s2(fstream& file);
  void s3(fstream& file);
  void s4(fstream& file);
  void s5(fstream& file);
  void s6(fstream& file);
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
    t.freeplaces = t.places;
    return in;
  }
private:
  char country[20];
  char town[20];
  char hotel[20];
  int stars;
  int places;
  int freeplaces;
};
