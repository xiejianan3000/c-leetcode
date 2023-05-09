

#include "common.h"

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int kthSmallest(struct TreeNode *root, int k) {
  struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(void *) * 1024);
  int nstack = 0, stack_sz = 1024;

  struct TreeNode *p = root;

  while (1) {
    while (p) {
      if (nstack == stack_sz) {
        stack_sz *= 2;
        struct TreeNode **tmp =
            (struct TreeNode **)malloc(sizeof(void *) * stack_sz);
        memcpy(tmp, stack, sizeof(void *) * nstack);
        free(stack);
        stack = tmp;
      }
      stack[nstack++] = p;
      p = p->left;
    }

    if (nstack == 0) {
      break;
    }

    p = stack[--nstack];
    k--;

    if (k == 0) {
      break;
    }

    p = p->right;
  }
  return p->val;
}