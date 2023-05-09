#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

int getDecimalValue(struct ListNode *head) {
  struct ListNode *arr[100];
  int n = 0;

  if (head == NULL) {
    return 0;
  }

  for (; head; head = head->next) {
    arr[n++] = head;
  }

  int sums = 0;

  int bits = 0;
  for (; n > 0; --n, ++bits) {
    int index = n - 1;
    int v = arr[index]->val;
    if (v == 1) {
      sums += pow(2, bits);
    }
  }
  return sums;
}