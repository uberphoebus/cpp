#include <stdio.h>

int main() {
  // // make file
  // FILE *fp; // file stream pointer
  // fp = fopen("a.txt", "w");

  // if (fp == NULL) {
  //   printf("Failed to open file\n");
  //   return 0;
  // }

  // fputs("Hello, World!\n", fp);
  // fclose(fp);

  // read file
  FILE *fp;
  fp = fopen("a.txt", "r");
  char buf[100];

  if (fp == NULL) {
    printf("Failed to open file\n");
    return 0;
  }

  fgets(buf, sizeof(buf), fp);
  printf("%s", buf);
  fclose(fp);

  return 0;
}