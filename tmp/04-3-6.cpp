#include <cstring>
#include <iostream>

namespace COMP_POS {
enum { CLERK, SENIOR, ASSIST, MANAGER };

void ShowPos(int pos) {
  switch (pos) {
  case CLERK:
    std::cout << "CLERK" << std::endl;
    break;
  case SENIOR:
    std::cout << "SENIOR" << std::endl;
    break;
  case ASSIST:
    std::cout << "ASSIST" << std::endl;
    break;
  case MANAGER:
    std::cout << "MANAGER" << std::endl;
    break;
  }
}

} // namespace COMP_POS

class NameCard {
private:
  char *name;
  char *company;
  char *phone;
  int position;

public:
  NameCard(char *n, char *c, char *p, int pos) {
    int n_len = strlen(n) + 1;
    int c_len = strlen(c) + 1;
    int p_len = strlen(p) + 1;

    name = new char[n_len];
    company = new char[c_len];
    phone = new char[p_len];

    strcpy(name, n);
    strcpy(company, c);
    strcpy(phone, p);
    position = pos;
  }
  ~NameCard() {
    delete[] name;
    delete[] company;
    delete[] phone;
  }
  void Show() {
    std::cout << "name  : " << name << std::endl;
    std::cout << "comp  : " << company << std::endl;
    std::cout << "phone : " << phone << std::endl;
    COMP_POS::ShowPos(position);
    std::cout << std::endl;
  }
};

int main(void) {
  NameCard manClerk("lee", "abceng", "010-1111-2222", COMP_POS::CLERK);
  NameCard manSenior("hong", "orangeeng", "010-3333-4444", COMP_POS::SENIOR);
  NameCard manAssist("kim", "sogoood", "010-5555-6666", COMP_POS::ASSIST);

  manClerk.Show();
  manSenior.Show();
  manAssist.Show();
}