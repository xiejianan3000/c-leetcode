#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void dps(struct TreeNode *node, int *arr, int *n) {
  if (node == NULL) {
    return;
  }

  dps(node->left, arr, n);
  arr[*n] = node->val;
  (*n)++;
  dps(node->right, arr, n);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
  int *arr = malloc(sizeof(int) * 100);
  int n = 0;
  dps(root, arr, &n);
  *returnSize = n;
  return arr;
}

void po_dps(struct TreeNode *node, int *arr, int *n) {
  if (node == NULL) {
    return;
  }

  po_dps(node->left, arr, n);
  po_dps(node->right, arr, n);
  arr[*n] = node->val;
  (*n)++;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *postorderTraversal(struct TreeNode *root, int *returnSize) {
  int *arr = malloc(sizeof(int) * 100);
  int n = 0;
  po_dps(root, arr, &n);
  *returnSize = n;
  return arr;
}