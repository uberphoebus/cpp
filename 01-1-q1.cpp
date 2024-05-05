#include <iostream>

int main() {
  int nums[5];
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    std::cout << i + 1 << "번째 숫자: ";
    std::cin >> nums[i];
    sum += nums[i];
  }
  std::cout << "합계: " << sum << std::endl;
}