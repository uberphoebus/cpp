#include <cstring>
#include <iostream>

class Person {
private:
  char *name;
  int age;

public:
  Person(char *myname, int myage) {
    int len = strlen(myname) + 1;
    name = new char[len];
    strcpy(name, myname);
    age = myage;
  }
  void Show() const {
    std::cout << "name : " << name << std::endl;
    std::cout << "age  : " << age << std::endl;
  }
  ~Person() {
    delete[] name;
    std::cout << "called destructor" << age << std::endl;
  }
};

int main(void) {
  Person man1("lee", 29);
  Person man2("jang", 41);

  man1.Show();
  man2.Show();
  return 0;
}