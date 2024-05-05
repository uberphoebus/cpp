#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

int main(void) {
  char str1[50] = "loooong string";
  char str2[50] = "long adddddddddd";

  std::cout << "strlen : " << strlen(str1) << std::endl;
  std::cout << "strcat : " << strcat(str1, str2) << std::endl;
  std::cout << "strcpy : " << strcpy(str1, str2) << std::endl;
  std::cout << "strcmp : " << strcmp(str1, str2) << std::endl;

  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    std::cout << rand() % 100 + 1 << " ";
  }
  std::cout << std::endl;

  return 0;
}
