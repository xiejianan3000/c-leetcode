
#include "common.h"

#define LEN 1000001

struct hlist_node
{
  int key;
  struct hlist_node **pprev, *next;
};

struct hlist_head
{
  struct hlist_node *first;
};

typedef struct
{
  struct hlist_head arr[1000];
} MyHashSet;

MyHashSet *myHashSetCreate()
{
  MyHashSet *obj = (MyHashSet *)malloc(sizeof(MyHashSet));

  for (int i = 0; i < 1000; i++)
  {
    obj->arr[i].first = NULL;
  }

  return obj;
}

bool myHashSetContains(MyHashSet *obj, int key)
{
  struct hlist_head *head = &obj->arr[key % 1000];

  for (struct hlist_node *e = head->first; e; e = e->next)
  {
    if (e->key == key)
    {
      return true;
    }
  }
  return false;
}

void myHashSetAdd(MyHashSet *obj, int key)
{
  if (myHashSetContains(obj, key) == true)
  {
    return;
  }

  struct hlist_head *head = &obj->arr[key % 1000];
  struct hlist_node *entry =
      (struct hlist_node *)malloc(sizeof(struct hlist_node));

  entry->key = key;

  entry->next = head->first;
  if (head->first)
  {
    head->first->pprev = &entry->next;
  }
  entry->pprev = &head->first;
  head->first = entry;
}

void myHashSetRemove(MyHashSet *obj, int key)
{
  struct hlist_head *head = &obj->arr[key % 1000];

  for (struct hlist_node *e = head->first; e; e = e->next)
  {
    if (e->key == key)
    {
      *e->pprev = e->next;
    }
  }
}

void myHashSetFree(MyHashSet *obj) { free(obj); }

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/