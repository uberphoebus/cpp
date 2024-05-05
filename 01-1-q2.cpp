#include <iostream>

int main() {
  int num;
  std::cout << "숫자를 입력하세요: ";
  std::cin >> num;

  for (int i = 1; i < 10; i++) {
    std::cout << num << " * " << i << " = " << num * i << std::endl;
  }
}