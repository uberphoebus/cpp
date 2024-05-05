#include <iostream>

namespace BestComImpl {
void SimpleFunc(void);
void PrettyFunc(void);
} // namespace BestComImpl

namespace ProgComImpl {
void SimpleFunc(void);
} // namespace ProgComImpl

int main(void) {
  BestComImpl::SimpleFunc();
  ProgComImpl::SimpleFunc();

  return 0;
}

void BestComImpl::SimpleFunc(void) {
  std::cout << "BestCom declare" << std::endl;
  PrettyFunc();
  ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc(void) {
  std::cout << "PrettyFunc declare" << std::endl;
}

void ProgComImpl::SimpleFunc(void) {
  std::cout << "ProgCom declare" << std::endl;
}