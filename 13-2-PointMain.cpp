#include "13-2-PointTemplate.cpp"
#include "13-2-PointTemplate.h"
#include <iostream>
using namespace std;

int main(void) {
  Point<int> pos1(3, 4);

  pos1.ShowPosition();

  Point<double> pos2(2.4, 3.6);
  pos2.ShowPosition();

  Point<char> pos3('P', 'F');
  pos3.ShowPosition();

  Point<char> pos5('P', 'F');
  pos5.ShowPosition();

  return 0;
}