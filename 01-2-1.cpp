#include <iostream>

void MyFunc(void) { std::cout << "MyFunc(void) called" << std::endl; }
void MyFunc(char c) { std::cout << "MyFunc(char c) called" << std::endl; }
void MyFunc(int a, int b) {
  std::cout << "MyFunc(int a, int b) called" << std::endl;
}

void swap(int *ptr1, int *ptr2) {
  int *tmp = ptr1;
  ptr1 = ptr2;
  ptr2 = tmp;
}
void swap(char *ptr1, char *ptr2) {
  char *tmp = ptr1;
  ptr1 = ptr2;
  ptr2 = tmp;
}
void swap(double *ptr1, double *ptr2) {
  double *tmp = ptr1;
  ptr1 = ptr2;
  ptr2 = tmp;
}

int main(void) {
  MyFunc();
  MyFunc('A');
  MyFunc(12, 13);

  int num1 = 20, num2 = 30;
  swap(&num1, &num2);
  std::cout << "num1: " << num1 << ' ' << "num2: " << num2 << std::endl;

  char ch1 = 'A', ch2 = 'Z';
  swap(&ch1, &ch2);
  std::cout << "ch1: " << ch1 << ' ' << "ch2: " << ch2 << std::endl;

  double dbl1 = 1.111, dbl2 = 5.555;
  swap(&dbl1, &dbl2);
  std::cout << "dbl1: " << dbl1 << ' ' << "dbl2: " << dbl2 << std::endl;

  return 0;
}