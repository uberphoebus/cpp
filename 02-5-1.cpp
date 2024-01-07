#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

char *MakeStrAdr1(int len) {
  char *str = (char *)malloc(sizeof(char) * len); // malloc in heap
  return str;
}

char *MakeStrAdr2(int len) {
  char *str = new char[len]; // no casting, size
  return str;
}



int main(void) {
  // malloc, free
  char *str1 = MakeStrAdr1(20);
  strcpy(str1, "i am so happy");
  cout << str1 << endl;
  free(str1);

  // new, delete
  char *str2 = MakeStrAdr2(20);
  strcpy(str2, "i am so happy");
  cout << str2 << endl;
  delete[] str2;

  return 0;
}