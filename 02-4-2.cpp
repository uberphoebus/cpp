#include <iostream>
using namespace std;

// do not return local function var in return ref function
int &RefReturn1(int &ref) {
  ref++;
  return ref; // int &num2 = ref;
}

int RefReturn2(int &ref) {
  ref++;
  return ref; // int num4 = ref;
}

int main(void) {
  int num1 = 1;
  int &num2 = RefReturn1(num1); // int &ref = num1;

  num1++;
  num2++;
  cout << "num1 : " << num1 << endl;
  cout << "num2 : " << num2 << endl;

  int num3 = 1;
  int num4 = RefReturn2(num3); // int &ref = num3;
  num3 += 1;
  num4 += 100;
  cout << "num3 : " << num3 << endl; // 1+1+1 = 3
  cout << "num4 : " << num4 << endl; // 1+1+100 = 102

  return 0;
}
