/* Implement a function void reverse(char* str) in C or C++ which reverses a
 * null-terminated string. */
#include <stdio.h>
#include <string.h>

void reverse(char *str) {
  char tmp;
  size_t len = strlen(str), i;
  if (len-- == 0) return;
  for (i = 0; i < len / 2; i++) {
    tmp = str[len-i];
    str[len-i] = str[i];
    str[i] = tmp;
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) return 1;
  reverse(argv[1]);
  puts(argv[1]);
  return 0;
}
