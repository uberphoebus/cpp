#include <iostream>
using namespace std;

// function template
template <typename T> T Add(T a, T b) { return a + b; }

int main() {
  cout << Add<int>(15, 20) << endl;        // change T to int
  cout << Add<double>(2.9, 3.7) << endl;   // change T to double
  cout << Add<int>(3.2, 3.2) << endl;      // change T to int
  cout << Add<double>(3.14, 2.75) << endl; // change T to double

  return 0;
}