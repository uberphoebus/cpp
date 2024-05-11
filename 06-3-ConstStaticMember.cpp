#include <iostream>
using namespace std;

class CountryArea {
public:
  const static int RUSSIA = 1707540;
  const static int CANADA = 998467;
  const static int CHINA = 957290;
  const static int SOUTH_KOREA = 9922;
};

int main(void) {
  cout << "RUSSIA      : " << CountryArea::RUSSIA << " square kilometers"
       << endl;
  cout << "CANADA      : " << CountryArea::CANADA << " square kilometers"
       << endl;
  cout << "CHINA       : " << CountryArea::CHINA << " square kilometers"
       << endl;
  cout << "SOUTH_KOREA : " << CountryArea::SOUTH_KOREA << " square kilometers"
       << endl;

  return 0;
}