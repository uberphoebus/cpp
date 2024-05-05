#include <iostream>

namespace Hybrid {
void HybFunc(void) {
  std::cout << "simple func" << std::endl;
  std::cout << "in namespace" << std::endl;
}
} // namespace Hybrid

using namespace std;

namespace AAA {
namespace BBB {
namespace CCC {
int num1;
int num2;
} // namespace CCC
} // namespace BBB
} // namespace AAA

int main(void) {
  // using
  using Hybrid::HybFunc;
  HybFunc();

  // using namespace
  cout << "hello world" << endl;

  // namespace alias
  namespace ABC = AAA::BBB::CCC;
  ABC::num1 = 20;
  ABC::num2 = 30;
  cout << ABC::num1 << endl;
  cout << ABC::num2 << endl;

  return 0;
}