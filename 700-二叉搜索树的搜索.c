

#include "common.h"

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *searchBST(struct TreeNode *root, int val) {
  struct TreeNode *p = root;

  while (p) {
    if (p->val == val) {
      return p;
    } else if (val < p->val) {
      p = p->left;
    } else {
      p = p->right;
    }
  }
  return NULL;
}