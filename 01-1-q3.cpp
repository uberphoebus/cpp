#include <iostream>

int main(void) {
  uint8_t quitFlag = 0;
  while (!quitFlag) {
    float sales;
    std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
    std::cin >> sales;

    if (sales == -1) {
      quitFlag = 1;
      std::cout << "프로그램을 종료합니다." << std::endl;
      continue;
    }

    float commission = 50 + sales * 0.12;
    std::cout << "이번 달 급여: " << commission << "만원" << std::endl;
  }
}