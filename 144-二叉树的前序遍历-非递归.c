
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorderTraversal(struct TreeNode *root, int *returnSize) {
  int sz = 1024;
  int *ans = (int *)malloc(sizeof(int) * sz);
  int nans = 0;

  struct TreeNode *stack[512];
  int nstack = 0;

  struct TreeNode *ptr = root;
  while (1) {
    while (ptr) {
      ans[nans++] = ptr->val;
      stack[nstack++] = ptr;
      ptr = ptr->left;
    }
    if (nstack == 0) {
      break;
    }
    ptr = stack[--nstack]->right;
  }

  *returnSize = nans;
  return ans;
}