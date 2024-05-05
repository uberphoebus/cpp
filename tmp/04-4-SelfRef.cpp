#include <iostream>
using namespace std;

class SelfRef {
private:
  int num;

public:
  SelfRef(int n) : num(n) {}
  SelfRef &Adder(int n) {
    num += n;
    return *this; // 객체 자신을 가리키는 포인터 반환
  }
  SelfRef &ShowTwoNumber() {
    cout << num << endl;
    return *this; // 객체 자신을 가리키는 포인터 반환
  }
};

int main(void) {
  SelfRef obj(3);
  SelfRef &ref = obj.Adder(2); // ref는 obj의 별명
  obj.ShowTwoNumber()          // obj의 멤버 변수 5 출력
      .Adder(1)                // obj의 멤버 변수 6으로 증가
      .ShowTwoNumber();        // obj의 멤버 변수 6 출력

  ref.ShowTwoNumber() // ref는 obj의 별명이므로 obj의 멤버 변수 6 출력
      .Adder(2)       // obj의 멤버 변수 8로 증가
      .ShowTwoNumber(); // obj의 멤버 변수 8 출력

  return 0;
}