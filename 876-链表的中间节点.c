

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head) {
  struct ListNode *arr[200];
  int n = 0;

  if (head == NULL) {
    return NULL;
  }

  for (; head; head = head->next) {
    arr[n++] = head;
  }

  return arr[n / 2];
}