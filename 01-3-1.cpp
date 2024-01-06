#include <iostream>

// set default value in declare
int BoxVolume(int length, int width = 1, int height = 1);

int main(void) {
  // fills from front param
  std::cout << BoxVolume(7) << std::endl;
  std::cout << BoxVolume(5, 5) << std::endl;
  std::cout << BoxVolume(3, 3, 3) << std::endl;

  return 0;
}

int BoxVolume(int length, int width, int height) {
  return length * width * height;
}
