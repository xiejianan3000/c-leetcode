
#include "common.h"
#include <stdlib.h>

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct
{
  int *arr;
  int n;
  int sz;
  int next;
} BSTIterator;

BSTIterator *bSTIteratorCreate(struct TreeNode *root)
{
  BSTIterator *obj = (BSTIterator *)malloc(sizeof(BSTIterator));
  obj->arr = (int *)malloc(sizeof(int) * 1024);
  obj->n = 0;
  obj->sz = 1024;
  obj->next = 0;

  struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(void *) * 1024);
  int nstack = 0;
  int stack_sz = 1024;

  struct TreeNode *p = root;

  while (1)
  {
    while (p)
    {
      if (nstack == stack_sz)
      {
        stack_sz *= 2;
        struct TreeNode **tmp =
            (struct TreeNode **)malloc(sizeof(void *) * stack_sz);
        memcpy(tmp, stack, nstack * sizeof(void *));
        free(stack);
        stack = tmp;
      }

      stack[nstack++] = p;
      p = p->left;
    }
    if (nstack == 0)
    {
      break;
    }
    struct TreeNode *tmp = stack[--nstack];
    if (obj->sz == obj->n)
    {
      obj->sz *= 2;
      int *tmp = (int *)malloc(sizeof(int) * obj->sz);
      memcpy(tmp, obj->arr, sizeof(int) * obj->n);
      free(obj->arr);
      obj->arr = tmp;
    }
    obj->arr[obj->n++] = tmp->val;
    p = tmp->right;
  }
  free(stack);
  return obj;
}

int bSTIteratorNext(BSTIterator *obj) { return obj->arr[obj->next++]; }

bool bSTIteratorHasNext(BSTIterator *obj) { return obj->next < obj->n; }

void bSTIteratorFree(BSTIterator *obj)
{
  free(obj->arr);
  free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/