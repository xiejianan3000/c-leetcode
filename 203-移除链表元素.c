#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
  if (head == NULL)
  {
    return NULL;
  }

  while (head && head->val == val)
  {
    head = head->next;
  }
  if (head == NULL)
  {
    return NULL;
  }

  struct ListNode *prev = head, *next = head->next;
  while (next)
  {
    if (next->val == val)
    {
      prev->next = next->next;
      next = next->next;
    }
    else
    {
      prev = prev->next;
      next = next->next;
    }
  }
  return head;
}