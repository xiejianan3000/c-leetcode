

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct entry {
  struct TreeNode *ptr;
  bool is_print;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *postorderTraversal(struct TreeNode *root, int *returnSize) {
  int sz = 1024;
  int nans = 0;
  int *ans = (int *)malloc(sizeof(int) * sz);

  int nstack = 0;
  struct entry stack[1024];

  struct TreeNode *ptr = root;
  while (1) {
    while (ptr) {
      stack[nstack].ptr = ptr;
      stack[nstack].is_print = false;
      nstack++;
      ptr = ptr->left;
    }
    if (nstack == 0) {
      break;
    }
    if (stack[nstack - 1].is_print == false) {
      stack[nstack - 1].is_print = true;
      ptr = stack[nstack - 1].ptr->right;
    } else {
      ans[nans++] = stack[--nstack].ptr->val;
    }
  }

  *returnSize = nans;
  return ans;
}