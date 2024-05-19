#include <iostream>
using namespace std;

int main(void) {
  int num1, num2;
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  try {
    if (num2 == 0) {
      throw num2;
    }
    cout << "Division result: " << num1 / num2 << endl;
  } catch (int expn) {
    cout << "Exception handling: " << expn << " is not valid." << endl;
    cout << "Please enter a non-zero number." << endl;
  }
}