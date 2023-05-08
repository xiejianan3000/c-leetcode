#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
  int i = 0, j = numsSize - 1;
  int ans = 0;
  while (i <= j)
  {
    int mid = (i + j) / 2;
    if (target == nums[mid])
    {
      ans = mid;
      break;
    }
    else if (target < nums[mid])
    {
      j = mid - 1;
    }
    else
    {
      i = mid + 1;
    }
  }
  if (i > j)
  {
    ans = i;
  }

  return ans;
}