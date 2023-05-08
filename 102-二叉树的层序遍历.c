
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct myque
{
  struct myque *next;
  struct TreeNode *val;
};

struct myque_head
{
  struct myque *first;
  struct myque *last;
};

void myque_push(struct myque_head *head, struct TreeNode *node)
{
  struct myque *entry = (struct myque *)malloc(sizeof(struct myque));
  entry->val = node;
  entry->next = NULL;

  if (head->last == NULL)
  {
    head->first = entry;
    head->last = entry;
  }
  else
  {
    head->last->next = entry;
    head->last = entry;
  }
}

struct TreeNode *myque_top(struct myque_head *head)
{
  if (head->first == NULL)
  {
    return NULL;
  }
  return head->first->val;
}

void myque_pop(struct myque_head *head)
{
  if (head->first == NULL)
  {
    return;
  }
  struct myque *tmp = head->first;
  head->first = head->first->next;
  if (head->first == NULL)
  {
    head->last = NULL;
  }
  free(tmp);
}

bool myque_empty(struct myque_head *head) { return head->first == NULL; }

int myque_size(struct myque_head *head)
{
  if (head->first == NULL)
  {
    return 0;
  }
  int i = 0;
  for (struct myque *f = head->first; f; f = f->next)
  {
    i++;
  }
  return i;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **levelOrder(struct TreeNode *root, int *returnSize,
                 int **returnColumnSizes)
{
  int level_sz = 1000;
  int level_n = 0;

  int **ans = (int **)malloc(sizeof(int *) * level_sz);
  int *columns = (int *)malloc(sizeof(int) * level_sz);

  if (root == NULL)
  {
    *returnSize = level_n;
    *returnColumnSizes = columns;
    return ans;
  }

  struct myque_head head;
  head.first = head.last = NULL;
  myque_push(&head, root);

  while (!myque_empty(&head))
  {
    int sz = myque_size(&head);
    int *tmp = malloc(sizeof(int) * 500);
    int n = 0;
    for (; sz > 0; --sz)
    {
      struct TreeNode *top = myque_top(&head);
      assert(top);
      myque_pop(&head);
      if (top->left)
      {
        myque_push(&head, top->left);
      }
      if (top->right)
      {
        myque_push(&head, top->right);
      }
      tmp[n++] = top->val;
    }
    ans[level_n] = tmp;
    columns[level_n] = n;
    level_n++;
  }

  *returnSize = level_n;
  *returnColumnSizes = columns;

  return ans;
}