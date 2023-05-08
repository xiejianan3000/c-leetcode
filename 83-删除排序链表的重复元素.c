#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
  if (head == NULL)
  {
    return NULL;
  }

  struct ListNode *slow = head, *fast = head->next;

  while (fast)
  {
    if (slow->val != fast->val)
    {
      slow->next = fast;
      slow = slow->next;
      fast = fast->next;
    }
    else
    {
      fast = fast->next;
    }
  }
  slow->next = NULL;
  return head;
}