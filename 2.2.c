/* Implement an algorithm to find the kth to last element of a singly linked
 * list. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
  struct node *next;
  int value;
};

void print_list(struct node *node) {
  int i = 0;
  while (node) {
    printf("%3d => %d\n", i++, node->value);
    node = node->next;
  }
}

int k_th(struct node *node, int k) {
  if (node == NULL || k <= 0) return -1;
  int vals[k], i = 0;
  while (node) {
    vals[i++%k] = node->value;
    node = node->next;
  }
  return vals[i%k];
}

int main() {
  struct node *head = malloc(sizeof(struct node)), *cur = head;
  head->next = NULL;
  int i;
  srand(time(NULL));
  for (i = 0; i < 99; i++) {
    cur->value = rand() % 100;
    cur = (cur->next = malloc(sizeof(struct node)));
  }
  cur->value = random() % 100;
  cur->next = NULL;
  print_list(head);
  printf("%3d => %d\n", 100-17, k_th(head, 17));
  return 0;
}
