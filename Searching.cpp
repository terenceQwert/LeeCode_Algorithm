#include <windows.h>
#include <stdio.h>
#include "Searching.h"
int gSearchingNums[] = { 3,5,7,23,1,24,32,71,86,231,342,456,678,3423,8564,45654,234324,342456,345236,426376 };

int improveSearching(int *nums, int numSize, int target)
{
  ///
  /// standard searching...
  /// 
  /*
  for( int i=0;i<numSzie;i++)
  {
    if( nums[i] == target)
      return i;
  }
  return (-1);
  */

  nums[0] = target;
  int n = numSize;
  while (nums[n] != target)
  {
    n--;
  }
  return n;
}


int numSort(const void* pa, const void* pb)
{
  if (*(int*)pa > *(int*)pb)
    return 1;
  else
    return -1;
}

/// <summary>
/// new algorithm to improve searching
/// </summary>
int envolution_1( int len, int target)
{
  int low = 1;
  int high = len;
  int loc = low;
  // mid = low + (high-low)*(key-a[low])/a[high] - a[low]
  while (target != gSearchingNums[loc])
  {
//    loc = loc + (((target - gSearchingNums[0]) / (gSearchingNums[len - 1] - gSearchingNums[0])));
    loc = low + ((target - gSearchingNums[low]) / (gSearchingNums[high - 1] - gSearchingNums[low])) * (high-1 - low);
    low = loc;
  }
  printf("loc = %d\n", loc);
  return loc;
}

void testSearching()
{
  int target = 7;
  qsort(gSearchingNums, sizeof(gSearchingNums) / sizeof(int),4, numSort);
  int loc = 0;
//  int loc = improveSearching(gSearchingNums, sizeof(gSearchingNums)/sizeof(int), target);

  /// <summary>
  /// use new algorithm to do searching.
  /// </summary>

  target = 231;
  loc = envolution_1(sizeof(gSearchingNums) / sizeof(int), target);
  printf(" find %d at location gSearchingNums[%d]\n", target, loc);

  target = 86;
  loc = envolution_1(sizeof(gSearchingNums) / sizeof(int), target);
  printf(" find %d at location gSearchingNums[%d]\n", target, loc);

  target = 23;
  loc = envolution_1(sizeof(gSearchingNums) / sizeof(int), target);
  printf(" find %d at location gSearchingNums[%d]\n", target, loc);

}
