#include <Windows.h>
#include <stdio.h>
#include "bi-dimention_array.h"
int garray[5][5] = {
  {1,4,7,11,15},
  {2,5,8,12,19},
  {3,6,0,16,22},
  {10,13,14,17,24},
  {18,21,23,26,30}
};



BiArraySearchData * testBi_Dimention_Array(const int target)
{
  int col = 0;
  int row = 0;
  int max_row = sizeof(garray) / sizeof(garray[0])-1;
  int max_element = sizeof(garray[0]) / sizeof(int)-1;

  for (int i = max_row; i >= 0; i--)
  {
    if (target == garray[i][max_element])
    {
      return new BiArraySearchData(i,max_element);
    }
    else if (target < garray[i][max_element])
    {
      // check.
      for (int j = max_element - 1; j >= 0; j--)
      {
        if (target == garray[i][j])
        {
          return new BiArraySearchData(i,j);
        }
        else if (target > garray[i][j])
          break;
      }
    }
    else
    {
      // do not care, it means, the target is not in this array.
    }

  }
  return NULL;
}
