#include <iostream>
using namespace std;

class Calculator {
private:
  int add_cnt;
  int mul_cnt;
  int min_cnt;
  int div_cnt;

public:
  void Init();
  float Add(float a, float b);
  float Mul(float a, float b);
  float Min(float a, float b);
  float Div(float a, float b);
  void ShowOpCount();
};

int main(void) {

  Calculator cal;
  cal.Init();
  cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
  cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
  cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
  cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;

  cal.ShowOpCount();

  return 0;
}

void Calculator::Init() {
  add_cnt = 0;
  mul_cnt = 0;
  min_cnt = 0;
  div_cnt = 0;
}
float Calculator::Add(float a, float b) {
  add_cnt++;
  return a + b;
}
float Calculator::Mul(float a, float b) {
  mul_cnt++;
  return a * b;
}
float Calculator::Min(float a, float b) {
  min_cnt++;
  return a - b;
}
float Calculator::Div(float a, float b) {
  div_cnt++;
  return a / b;
}
void Calculator::ShowOpCount() {
  cout << "add : " << add_cnt << ", min : " << min_cnt << ", mul : " << mul_cnt
       << ", div : " << div_cnt << endl;
}