#include <iostream>

typedef struct __Point {
  int xpos;
  int ypos;
} Point;

Point &PntAdder(const Point &p1, const Point &p2) {
  Point *pptr = new Point;
  pptr->xpos = p1.xpos + p2.xpos;
  pptr->ypos = p1.ypos + p2.ypos;

  return *pptr;
}

int main(void) {
  Point *p1 = new Point;
  Point *p2 = new Point;
  p1->xpos = 2;
  p1->ypos = 3;
  p2->xpos = 4;
  p2->ypos = 1;

  Point &p3 = PntAdder(*p1, *p2);
  std::cout << "p3 = (" << p3.xpos << ", " << p3.ypos << ")" << std::endl;

  delete p1;
  delete p2;
  delete &p3;

  return 0;
}
