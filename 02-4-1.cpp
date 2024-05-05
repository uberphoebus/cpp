// call-by-valure : delivers value to function param
// call-by-reference : delivers address to function param

#include <iostream>

using namespace std;

void SwapRef(int &ref1, int &ref2) {
  int temp = ref1;
  ref1 = ref2;
  ref2 = temp;
}

void AddOne(int &num) { num++; }

void Reverse(int &num) { num *= -1; }

void SwapPtr(int *(&pref1), int *(&pref2)) {
  int *tmp = pref1;
  pref1 = pref2;
  pref2 = tmp;
}

int main(void) {
  int val1 = 10;
  int val2 = 20;

  SwapRef(val1, val2);
  cout << "val1 : " << val1 << endl;
  cout << "val2 : " << val2 << endl;

  int num = 0;
  AddOne(num);
  cout << "num : " << num << endl;
  AddOne(num);
  cout << "num : " << num << endl;
  Reverse(num);
  cout << "num : " << num << endl;
  Reverse(num);
  cout << "num : " << num << endl;

  int num1 = 5, num2 = 10;
  int *ptr1 = &num1;
  int *ptr2 = &num2;
  SwapPtr(ptr1, ptr2);
  cout << "*ptr1 : " << *ptr1 << endl;
  cout << "*ptr2 : " << *ptr2 << endl;

  return 0;
}