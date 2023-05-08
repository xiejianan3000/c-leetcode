#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <vadefs.h>

/*
 * 实现双向循环链表
 */
struct list_head
{
  struct list_head *prev, *next;
};
#define CONTAINER_OF(ptr, type, member)                                        \
  ((type *)((size_t)((char *)(ptr)) - offsetof(type, member)))
#define list_head_init(h) ((h)->prev = (h), (h)->next = (h))
#define list_add_head(e, h)                                                    \
  ((e)->prev = (h), (e)->next = (h)->next, (h)->next->prev = (e),              \
   (h)->next = (e))
#define list_del(e) ((e)->prev->next = (e)->next, (e)->next->prev = (e)->prev)
#define list_entry(ptr, type, member) CONTAINER_OF(ptr, type, member)

/*
 * 实现简易哈希表
 */
struct hashtable
{
  struct list_head heads[1000];
};

struct hash_entry
{
  struct list_head head;
  int key;
  int val;
};

void hashtable_init(struct hashtable *ht)
{
  for (int i = 0; i < 1000; i++)
  {
    list_head_init(&ht->heads[i]);
  }
}

struct hash_entry *ht_find(struct hashtable *h, int key)
{
  struct list_head *head = &h->heads[(key + 30000) % 1000000];

  struct list_head *p = head->next;
  while (p != head)
  {
    struct hash_entry *e = list_entry(p, struct hash_entry, head);
    if (e->key == key)
    {
      return e;
    }
    p = p->next;
  }
  return NULL;
}

void ht_add(struct hashtable *h, int key, int val)
{
  struct hash_entry *hashe = malloc(sizeof(struct hash_entry));
  hashe->key = key;
  hashe->val = val;
  list_head_init(&hashe->head);

  struct list_head *head = &h->heads[(key + 30000) % 1000000];
  list_add_head(&hashe->head, head);
}

void ht_del(struct hashtable *h, int key)
{
  struct list_head *head = &h->heads[(key + 30000) % 1000000];

  struct list_head *p = head->next;
  while (p != head)
  {
    struct hash_entry *e = list_entry(p, struct hash_entry, head);
    if (e->key == key)
    {
      list_del(&e->head);
      free(e);
      break;
    }
    p = p->next;
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
               int *returnSize)
{
  int *ans = malloc(sizeof(int) * 1001);
  int n = 0;

  struct hashtable ht;
  hashtable_init(&ht);
  for (int i = 0; i < nums1Size; i++)
  {
    struct hash_entry *e = ht_find(&ht, nums1[i]);
    if (e == NULL)
    {
      ht_add(&ht, nums1[i], 0);
    }
    else
    {
      e->val++;
    }
  }

  for (int i = 0; i < nums2Size; i++)
  {
    struct hash_entry *e = ht_find(&ht, nums2[i]);
    if (e != NULL)
    {
      ans[n++] = e->key;
      e->val--;
      if (e->val == 0)
      {
        ht_del(&ht, nums2[i]);
      }
    }
  }

  *returnSize = n;
  return ans;
}
