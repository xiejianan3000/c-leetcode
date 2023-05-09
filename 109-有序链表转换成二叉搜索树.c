
#include "common.h"

struct ListNode {
  int val;
  struct ListNode *next;
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *dps(int *nums, int i, int j) {
  if (i > j) {
    return NULL;
  }

  int mid = (i + j) / 2;
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = nums[mid];
  node->left = dps(nums, i, mid - 1);
  node->right = dps(nums, mid + 1, j);
  return node;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
  int arr_sz = 1024;
  int narr = 0;
  int *arr = (int *)malloc(sizeof(int) * arr_sz);

  while (head) {
    if (narr == arr_sz) {
      arr_sz *= 2;
      int *buf = (int *)malloc(sizeof(int) * arr_sz);
      assert(buf);
      memcpy(buf, arr, sizeof(int) * narr);
      free(arr);
      arr = buf;
    }
    arr[narr++] = head->val;
    head = head->next;
  }

  int i = 0, j = narr - 1;
  return dps(arr, i, j);
}