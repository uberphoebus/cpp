#include <iostream>

bool IsPos(int num) {
  if (num <= 0)
    return false;
  else
    return true;
}

int main(void) {

  // size of bool
  std::cout << "true  : " << true << std::endl;
  std::cout << "false : " << false << std::endl;
  std::cout << "sizeof(1)     : " << sizeof(1) << std::endl;
  std::cout << "sizeof(0)     : " << sizeof(0) << std::endl;
  std::cout << "sizeof(true)  : " << sizeof(true) << std::endl;
  std::cout << "sizeof(false) : " << sizeof(false) << std::endl;

  // return bool
  int num = 10;
  if (IsPos(num)) {
    std::cout << "positive" << std::endl;
  } else {
    std::cout << "negative" << std::endl;
  }

  return 0;
}