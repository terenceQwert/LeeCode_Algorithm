#include <Windows.h>
#include <stdio.h>

int numsort(const void * c1, const void * c2)
{
  int * s1 = (int*)c1;
  int * s2 = (int*)c2;
  if (*s1 == *s2)
    return 0;
  else if (*s1 < *s2)
    return -1;
  else
    return 1;
}

void testDuplicatedNums()
{

  int nums[] = { 3,5,1,31,600,4,2,115,600 };
  int len = sizeof(nums) / sizeof(int);
  qsort(nums, len, sizeof(int), numsort);
  for (int i = 0; i < len-1; i++) {
    if (nums[i] == nums[i + 1]) {
      printf(" duplicated nums is %d", nums[i]);
    }
  }
}