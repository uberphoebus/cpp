#include "13-2-ArrayTemplate.h"
#include "13-2-Point.h"
#include <iostream>
using namespace std;

int main(void) {
  BoundCheckArray<int> iarr(5);
  for (int i = 0; i < 5; i++) {
    iarr[i] = (i + 1) * 11;
  }
  for (int i = 0; i < 5; i++) {
    cout << iarr[i] << endl;
  }

  BoundCheckArray<Point> oarr(3);
  oarr[0] = Point(3, 4);
  oarr[1] = Point(5, 6);
  oarr[2] = Point(7, 8);
  for (int i = 0; i < 3; i++) {
    cout << oarr[i] << endl;
  }

  typedef Point *POINT_PTR;
  BoundCheckArray<POINT_PTR> parr(3);
  parr[0] = new Point(3, 4);
  parr[1] = new Point(5, 6);
  parr[2] = new Point(7, 8);
  for (int i = 0; i < 3; i++) {
    cout << *(parr[i]) << endl;
  }

  delete parr[0];
  delete parr[1];
  delete parr[2];

  return 0;
}