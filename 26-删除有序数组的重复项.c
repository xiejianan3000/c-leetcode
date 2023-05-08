#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize)
{
  if (numsSize == 0)
  {
    return 0;
  }

  int slow = 1, fast = 1;
  while (fast < numsSize)
  {
    if (nums[fast] != nums[slow - 1])
    {
      nums[slow++] = nums[fast];
    }
    fast++;
  }
  return slow;
}