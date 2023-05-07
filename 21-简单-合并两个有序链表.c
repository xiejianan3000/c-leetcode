struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode head;
  head.next = NULL;
  struct ListNode *p = &head;

  while (list1 || list2) {
    if ((list1 && list2 && list1->val < list2->val) || (list1 && !list2)) {
      p->next = list1;
      p = p->next;
      list1 = list1->next;
    } else {
      p->next = list2;
      p = p->next;
      list2 = list2->next;
    }
  }
  return head.next;
}