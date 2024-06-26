#include <iostream>
using namespace std;

template <typename T> class Point {
private:
  T xpos, ypos;

public:
  Point(T x = 0, T y = 0);
  void ShowPosition() const;
};

template <typename T> Point<T>::Point(T x, T y) : xpos(x), ypos(y) {}

template <typename T> void Point<T>::ShowPosition() const {
  cout << '[' << xpos << ", " << ypos << ']' << endl;
}

int main(void) {
  Point<int> pos1(3, 4);
  Point<int> pos2(10, 20);

  pos1.ShowPosition();
  pos2.ShowPosition();

  Point<double> pos3(2.4, 3.6);
  Point<double> pos4(3.6, 2.4);

  pos3.ShowPosition();
  pos4.ShowPosition();

  Point<char> pos5('P', 'F');
  pos5.ShowPosition();

  return 0;
}