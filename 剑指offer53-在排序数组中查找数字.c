

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int search(int *nums, int numsSize, int target) {
  int sums = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != target) {
      continue;
    }
    int j = i + 1;
    sums++;
    while (j < numsSize && nums[j] == target) {
      sums++;
      j++;
    }
    break;
  }
  return sums;
}