#include <iostream> // 입력과 출력을 위한 헤더 파일 선언

int main() {
  int num = 20;
  std::cout << "Hello World!" << std::endl; // 문자열 출력
  std::cout << "Hello "
            << "World!" << std::endl;
  std::cout << num << ' ' << 'A';
  std::cout << ' ' << 3.14 << std::endl;
  return 0;
}