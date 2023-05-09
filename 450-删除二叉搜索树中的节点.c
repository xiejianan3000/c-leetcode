
#include "common.h"

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
  struct TreeNode *p = root, *par = NULL;

  while (p)
  {
    if (p->val == key)
    {
      break;
    }
    else if (key < p->val)
    {
      par = p;
      p = p->left;
    }
    else
    {
      par = p;
      p = p->right;
    }
  }

  if (p == NULL)
  {
    return root;
  }

  struct TreeNode *left = p->left, *right = p->right;

  struct TreeNode *tmp = (left != NULL) ? left : right;

  if (par == NULL)
  {
    root = tmp;
  }
  else if (par->left == p)
  {
    par->left = tmp;
  }
  else
  {
    par->right = tmp;
  }

  if (left != NULL)
  {
    if (right != NULL)
    {
      struct TreeNode *save = left->right;
      left->right = right;

      struct TreeNode *prev = right, *curr = right->left;

      while (curr)
      {
        prev = prev->left;
        curr = curr->left;
      }
      prev->left = save;
    }
  }
  return root;
}
