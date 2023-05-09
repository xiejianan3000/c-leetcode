

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

int *reversePrint(struct ListNode *head, int *returnSize) {
  int *arr = (int *)malloc(sizeof(int) * 10000);
  int n = 0;

  for (; head; head = head->next) {
    arr[n++] = head->val;
  }

  *returnSize = n;

  int i = 0, j = n - 1;

  while (i < j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    i++, j--;
  }
  return arr;
}