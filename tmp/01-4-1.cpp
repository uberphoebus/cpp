#include <iostream>

#define SQUARE(x) ((x) * (x))

// inline function -> preprocessor
inline int SQUAREFUNC(int x) { return x * x; }

int main(void) {
  std::cout << SQUARE(5) << std::endl;
  std::cout << SQUARE(10) << std::endl;
  std::cout << SQUAREFUNC(5) << std::endl;
  std::cout << SQUAREFUNC(10) << std::endl;

  return 0;
}