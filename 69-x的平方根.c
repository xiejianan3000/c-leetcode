#include <stdio.h>

int mySqrt(int x)
{
  if (x == 0 || x == 1)
  {
    return x;
  }
  // 1 | 2 3 4 5 6
  // 1 2 3 4
  long i = 1, j = x - 1;
  long ans;
  while (i <= j)
  {
    long mid = (i + j) / 2;
    long long mm = mid * mid;
    if (mm == (long long)x)
    {
      ans = mid;
      break;
    }
    else if (mid * mid < x)
    {
      i = mid + 1;
    }
    else
    {
      j = mid - 1;
    }
  }
  if (i > j)
  {
    ans = j;
  }

  return ans;
}