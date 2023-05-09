
#include "common.h"

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *insertIntoBST(struct TreeNode *root, int val) {
  struct TreeNode *curr = root, *prev = NULL;
  while (curr) {
    prev = curr;
    if (val < curr->val) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }

  curr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  curr->val = val;
  curr->left = NULL;
  curr->right = NULL;

  if (prev == NULL) {
    root = curr;
  } else if (curr->val > prev->val) {
    prev->right = curr;
  } else {
    prev->left = curr;
  }

  return root;
}