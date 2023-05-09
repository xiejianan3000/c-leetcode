
#include "common.h"
#include <stdlib.h>

typedef struct
{
  int *arr;
  int n;
  int sz;
  int head;
  int tail;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
  MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
  obj->arr = (int *)malloc(sizeof(int) * k);
  obj->sz = k;
  obj->n = 0;
  obj->head = 0;
  obj->tail = 0;
  return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
  if (obj->n == obj->sz)
  {
    return false;
  }

  obj->arr[obj->tail++] = value;
  obj->n++;

  if (obj->tail == obj->sz)
  {
    obj->tail = 0;
  }

  return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
  if (obj->n == 0)
  {
    return false;
  }

  obj->head++;
  obj->n--;

  if (obj->head == obj->sz)
  {
    obj->head = 0;
  }

  return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
  if (obj->n == 0)
  {
    return -1;
  }
  return obj->arr[obj->head];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
  if (obj->n == 0)
  {
    return -1;
  }

  int i = obj->tail - 1;

  if (i < 0)
  {
    i = obj->sz - 1;
  }

  return obj->arr[i];
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj) { return obj->n == 0; }

bool myCircularQueueIsFull(MyCircularQueue *obj) { return obj->n == obj->sz; }

void myCircularQueueFree(MyCircularQueue *obj)
{
  free(obj->arr);
  free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/