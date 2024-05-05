#include <cstring>
#include <iostream>

class Printer {
private:
  char string[50];

public:
  void SetString(const char *str) { strcpy(string, str); }
  void ShowString() { std::cout << string << std::endl; }
};

int main(void) {
  Printer pnt;
  pnt.SetString("Hello world!");
  pnt.ShowString();

  pnt.SetString("I love C++");
  pnt.ShowString();

  return 0;
}