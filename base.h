#include <string>
using namespace std;

class tours {
public:
  void setTours();
  void read();
  void reserv();
  void del();
  void search();
  int menu();
private:
  string country;
  string town;
  string hotel;
  int stars;
  int places;
  int freeplaces;
};
