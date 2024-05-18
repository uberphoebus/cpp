#include <iostream>
using namespace std;

class Point {
private:
  int xpos, ypos;

public:
  Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
  void ShowPosition() const {
    cout << '[' << xpos << ", " << ypos << ']' << endl;
  }
};

template <typename T> void SwapData(T &data1, T &data2) {
  T temp = data1;
  data1 = data2;
  data2 = temp;
}

template <typename T> T SumArray(T arr[], int len) {
  T sum = 0;
  for (int i = 0; i < len; i++) {
    sum += arr[i];
  }
  return sum;
}

int main() {
  Point pos1(3, 4);
  Point pos2(10, 20);

  SwapData(pos1, pos2);
  pos1.ShowPosition();
  pos2.ShowPosition();

  int arr1[] = {10, 20, 30};
  float arr2[] = {10.3f, 20.1f, 30.2f};

  cout << SumArray(arr1, sizeof(arr1) / sizeof(int)) << endl;
  cout << SumArray(arr2, sizeof(arr2) / sizeof(float)) << endl;

  return 0;
}