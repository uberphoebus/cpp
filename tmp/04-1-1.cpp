#include <iostream>
using namespace std;

class Point {
public:
  int x;
  int y;
};

class Rectangle {
public:
  Point upLeft;
  Point lowRight;

public:
  void ShowRecInfo() {
    cout << "upLeft : [" << upLeft.x << ", " << upLeft.y << "]" << endl;
    cout << "lowRight : [" << lowRight.x << ", " << lowRight.y << "]" << endl;
  }
};

int main(void) {
  Point pos1 = {-2, 4};
  Point pos2 = {5, 9};
  Rectangle rec = {pos2, pos1};
  rec.ShowRecInfo();

  return 0;
}