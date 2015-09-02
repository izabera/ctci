/* Given two strings, write a method to decide if one is a permutation of the
 * other. */
#include <stddef.h>
#include <stdbool.h>

bool is_perm(char *a, char *b) {
  if (a == NULL || b == NULL) return false;
  unsigned int array[2][256] = { { 0 } }, i;
  while (*a) array[0][(int)*(a++)]++;
  while (*b) array[1][(int)*(b++)]++;
  for (i = 0; i < 256; i++) if (array[0][i] != array[1][i]) return false;
  return true;
}

int main(int argc, char *argv[]) {
  if (argc < 3) return 1;
  return !is_perm(argv[1], argv[2]);
}
