

#include "common.h"
#include <stdlib.h>

typedef struct dlist
{
  struct dlist *prev, *next;
  int val;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
  MyLinkedList *head = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  head->prev = head;
  head->next = head;
  return head;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
  MyLinkedList *p = obj->next;

  for (; p != obj; p = p->next)
  {
    if (index-- == 0)
    {
      break;
    }
  }

  if (p == obj)
  {
    return -1;
  }

  return p->val;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
  MyLinkedList *e = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  e->val = val;
  e->prev = obj;
  e->next = obj->next;
  obj->next->prev = e;
  obj->next = e;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
  MyLinkedList *e = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  e->val = val;
  e->prev = obj->prev;
  e->next = obj;
  obj->prev->next = e;
  obj->prev = e;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
  MyLinkedList *p = obj->next;

  while (p != obj)
  {
    if (index-- == 0)
    {
      break;
    }

    p = p->next;
  }

  if (p != obj || (p == obj && index == 0))
  {
    if (index == 0)
    {
      p = obj;
    }

    MyLinkedList *e = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    e->val = val;
    e->prev = p->prev;
    e->next = p;
    p->prev->next = e;
    p->prev = e;
  }
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
  MyLinkedList *p = obj->next;

  while (p != obj)
  {
    if (index-- == 0)
    {
      break;
    }

    p = p->next;
  }

  if (p == obj)
  {
    return;
  }

  p->prev->next = p->next;
  p->next->prev = p->prev;
  p->prev = NULL;
  p->next = NULL;
}

void myLinkedListFree(MyLinkedList *obj)
{
  MyLinkedList *p = obj->next;

  while (p != obj)
  {
    MyLinkedList *n = p->next;
    free(p);
    p = n;
  }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/