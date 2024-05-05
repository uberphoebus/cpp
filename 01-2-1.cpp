#include <iostream>

void MyFunc(void) { std::cout << "[call] MyFunc(void)" << std::endl; }

void MyFunc(char c) { std::cout << "[call] MyFunc(char c)" << std::endl; }

void MyFunc(int a, int b) {
  std::cout << "[call] MyFunc(int a, int b)" << std::endl;
}

int main(void) {

  // function overloading : function name + declare of param
  
  MyFunc();
  MyFunc('A');
  MyFunc(12, 13);

  return 0;
}
