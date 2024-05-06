#include <cstring>
#include <iostream>
using namespace std;

class Person {
private:
  char *name;
  int age;

public:
  Person(const char *myname, int myage) {
    int len = strlen(myname) + 1;
    name = new char[len];
    strcpy(name, myname);
    age = myage;
  }

  Person(const Person &copy) : age(copy.age) {
    name = new char[strlen(copy.name) + 1];
    strcpy(name, copy.name); // make deep copy
  }

  void ShowPersonInfo() const {
    cout << "Name : " << name << endl;
    cout << "Age  : " << age << endl;
  }

  ~Person() {
    delete[] name;
    cout << "Called destructor!" << endl;
  }
};

int main(void) {
  Person man1("Lee dong woo", 29);
  Person man2 = man1; // default copy constructor is called -> shallow copy

  man1.ShowPersonInfo();
  man2.ShowPersonInfo();
  return 0;
}