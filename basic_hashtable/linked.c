#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
char *value;
int *head;
char *next;
} Node;


Node *create_node(char *value, char *next, int *head) {
  Node *n;
  n = malloc(sizeof(Node));
  n->value = value;
  n->head = head;
  n->next = next;
  return n;

}


int main(void)
{

  struct Node *a = create_node("hello", NULL, 1);
  printf("value: %s\n", a->value);
  printf("next: %s\n", a->next);
  printf("next: %d\n", a->head);
  struct Node *b = create_node("world", NULL, 0);
  a->next = b;
  printf("value: %s\n", a->value);
  printf("next: %s\n", *a->next);
  printf("next: %d\n", a->head);










  return 0;
}
