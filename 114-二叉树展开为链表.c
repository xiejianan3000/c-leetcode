
#include "common.h"
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void flatten(struct TreeNode *root)
{
  int arr_sz = 1024;
  int narr = 0;
  struct TreeNode **arr =
      (struct TreeNode **)malloc(sizeof(struct TreeNode *) * arr_sz);

  int nstack = 0;
  struct TreeNode *stack[512];

  struct TreeNode *ptr = root;
  while (1)
  {
    while (ptr)
    {
      if (narr == arr_sz)
      {
        arr_sz *= 2;
        struct TreeNode **tmp =
            (struct TreeNode **)malloc(sizeof(struct TreeNode *) * arr_sz);
        memcpy(tmp, arr, sizeof(int) * arr_sz);
        free(arr);
        arr = tmp;
      }
      arr[narr++] = ptr;
      stack[nstack++] = ptr;
      ptr = ptr->left;
    }

    if (nstack == 0)
    {
      break;
    }
    ptr = stack[--nstack]->right;
  }

  struct TreeNode head;
  struct TreeNode *p = &head;
  for (int i = 0; i < narr; i++)
  {
    arr[i]->left = arr[i]->right = NULL;
    p->right = arr[i];
    p = p->right;
  }
}