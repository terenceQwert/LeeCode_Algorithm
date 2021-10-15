#include <Windows.h>
#include <stdio.h>

#include "Empty.h"

int numSort(const void* s1, const void* s2)
{
  int* p1 = (int*)s1;
  int* p2 = (int*)s2;
  if (*p1 == *p2)
    return 0;
  else if (*p1 > *p2)
    return 1;
  else
    return -1;
}

/// <summary>
///  provide an array, there are only a number showing one time, but, others shows 3 times, find out the number that only one time.
/// </summary>
void testMultipletimesNumbers()
{
  int nums[] = { 1,1,1,2,2,2,3,3,3,5,4,4,4,7,7,7 ,5,5,6};
  int i = 0;
  qsort(nums, sizeof(nums) / sizeof(int), 4, numSort);
  for (i = 0; i < sizeof(nums) / sizeof(int) - 2; i+=3)
  {
    if (nums[i] != nums[i + 1])
      break;
  }
  printf("the single number is %d\n", nums[i]);
}
