#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * 实现双向循环链表
 */
struct list_head {
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
struct hashtable {
  struct list_head heads[1000];
};

struct hash_entry {
  struct list_head head;
  int key;
  int val;
};

void hashtable_init(struct hashtable *ht) {
  for (int i = 0; i < 1000; i++) {
    list_head_init(&ht->heads[i]);
  }
}

struct hash_entry *ht_find(struct hashtable *h, int key) {
  struct list_head *head = &h->heads[key % 1000];

  struct list_head *p = head->next;
  while (p != head) {
    struct hash_entry *e = list_entry(p, struct hash_entry, head);
    if (e->key == key) {
      return e;
    }
    p = p->next;
  }
  return NULL;
}

void ht_add(struct hashtable *h, int key, int val) {
  struct hash_entry *hashe = malloc(sizeof(struct hash_entry));
  hashe->key = key;
  hashe->val = val;
  list_head_init(&hashe->head);

  struct list_head *head = &h->heads[key % 1000];
  list_add_head(&hashe->head, head);
}

void ht_del(struct hashtable *h, int key) {
  struct list_head *head = &h->heads[key % 1000];

  struct list_head *p = head->next;
  while (p != head) {
    struct hash_entry *e = list_entry(p, struct hash_entry, head);
    if (e->key == key) {
      list_del(&e->head);
      free(e);
      break;
    }
    p = p->next;
  }
}

struct ListNode {
  int val;
  struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
  struct hashtable ht;
  hashtable_init(&ht);

  while (head) {
    head = head->next;
    unsigned int n = (unsigned int)head;
    struct hash_entry *e = ht_find(&ht, n);
    if (e == NULL) {
      ht_add(&ht, n, 0);
    } else {
      return true;
    }
  }

  return false;
}