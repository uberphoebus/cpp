#include <iostream>

using namespace std;

int main(void) {

  // reference(alias)
  // 1. only variable
  // 2. declare with init
  // 3. null (x)

  int num1 = 1020;
  int &num2 = num1;

  num2 = 3047;
  cout << "val : " << num1 << endl;
  cout << "ref : " << num2 << endl;

  cout << "val : " << &num1 << endl;
  cout << "ref : " << &num2 << endl;

  // pointer ref
  int num = 12;
  int *ptr = &num;
  int **pptr = &ptr;

  int &ref = num;
  int *(&pref) = ptr; // referenc of pointer var
  int **(&ppref) = pptr;

  cout << ref << endl;
  cout << *pref << endl;
  cout << **ppref << endl;

  return 0;
}