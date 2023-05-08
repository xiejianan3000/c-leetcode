

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
  int sz = 1024, nans = 0;
  int *ans = (int *)malloc(sizeof(int) * sz);

  int nstack = 0;
  struct TreeNode *stack[512];

  struct TreeNode *ptr = root;
  while (1)
  {
    while (ptr)
    {
      stack[nstack++] = ptr;
      ptr = ptr->left;
    }
    if (nstack == 0)
    {
      break;
    }
    ptr = stack[--nstack];
    ans[nans++] = ptr->val;
    ptr = ptr->right;
  }

  *returnSize = nans;
  return ans;
}