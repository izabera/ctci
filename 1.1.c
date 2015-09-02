/* Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional data structures? */
#include <stddef.h>
#include <stdbool.h>

bool only_unique(char *s) {
  if (s == NULL) return true;
#if 1 /* O(n) time + array that's constant in size */
  unsigned int array[256] = { 0 };
  while (*s) if (array[(int)*(s++)]++) return 0;
#else /* O(n^2) */
  char *tmp;
  while (*s) {
    tmp = s + 1;
    while (*tmp) if (*s == *(tmp++)) return false;
    s++;
  }
#endif
  return true;
}

int main(int argc, char *argv[]) {
  if (argc < 2) return 1;
  return !only_unique(argv[1]);
}
