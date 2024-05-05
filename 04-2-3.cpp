#include <iostream>
using namespace std;

class Point {
private:
  int xpos, ypos;

public:
  void Init(int x, int y) { xpos = x, ypos = y; }
  void ShowPointInfo() const {
    cout << "[" << xpos << ", " << ypos << "]" << endl;
  }
};

class Circle {
private:
  Point center;
  float radius;

public:
  void Init(int _x, int _y, int _radius) {
    center.Init(_x, _y);
    radius = _radius;
  }
  void ShowCircleInfo() const {
    cout << "circle info ..." << endl;
    cout << "radius : " << radius << endl;
    center.ShowPointInfo();
  }
};

class Ring {
private:
  Circle inner;
  Circle outter;

public:
  void Init(int inner_x, int inner_y, int inner_radius, int outter_x,
            int outter_y, int outter_radius) {
    inner.Init(inner_x, inner_y, inner_radius);
    outter.Init(outter_x, outter_y, outter_radius);
  }
  void ShowRingInfo() {
    cout << "inner ";
    inner.ShowCircleInfo();
    cout << "outter ";
    outter.ShowCircleInfo();
  }
};

int main(void) {
  Ring ring;
  ring.Init(1, 1, 4, 2, 2, 9);
  ring.ShowRingInfo();

  return 0;
}