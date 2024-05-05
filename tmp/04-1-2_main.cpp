#include "04-1-2_point.h"
#include "04-1-2_rectangle.h"
#include <iostream>
using namespace std;

int main(void) {
  // Point pos1;
  // if (!pos1.InitMembers(-2, 4)) {
  //   cout << "init failed" << endl;
  // }
  // if (!pos1.InitMembers(2, 4)) {
  //   cout << "init failed" << endl;
  // }

  // Point pos2;
  // if (!pos2.InitMembers(5, 9)) {
  //   cout << "init failed" << endl;
  // }

  // Rectangle rec;
  // if (!rec.InitMembers(pos2, pos1)) {
  //   cout << "rec init failed" << endl;
  // }
  // if (!rec.InitMembers(pos1, pos2)) {
  //   cout << "rec init failed" << endl;
  // }

  // constructor
  Rectangle rec(1, 1, 5, 5);
  rec.ShowRecInfo();

  return 0;
}