
#include <stdlib.h>
#include <string.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
  int *buf = (int *)malloc(sizeof(int) * m);
  memcpy(buf, nums1, m * sizeof(int));

  int k = 0;
  int i1 = 0, n1 = m;
  int i2 = 0, n2 = n;
  while (i1 < n1 || i2 < n2)
  {
    if ((i1 < n1 && i2 < n2 && buf[i1] < nums2[i2]) || (i1 < n1 && i2 >= n2))
    {
      nums1[k++] = buf[i1++];
    }
    else
    {
      nums1[k++] = nums2[i2++];
    }
  }
}