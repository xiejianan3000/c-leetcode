

#include <stdlib.h>

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *dps(int *nums, int i, int j)
{
  if (i > j)
  {
    return NULL;
  }

  int mid = (i + j) / 2;
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = nums[mid];
  node->left = dps(nums, i, mid - 1);
  node->right = dps(nums, mid + 1, j);
  return node;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
  return dps(nums, 0, numsSize - 1);
}
