#include <Windows.h>
#include <stdio.h>

int* MaxSubArray(int* nums, int numSize)
{
  int i;
  int j;
  int sum = 0;
  int max = 0;
  int* range = new int[2];
  for (i = 0; i < numSize; i++)
  {
    sum = 0;
    for (j = i; j < numSize; j++)
    {

      sum += nums[j];
      if (sum > max)
      {
        max = sum;
        range[0] = i;
        range[1] = j;
      }
    }
  }
  printf("max sub array start:%d, end:%d, total:%d\n", range[0], range[1], max);
  return range;

}


class SqList {
public:
  int r[6];
  int length;
  SqList()
  {
    r[0] = 0;
    r[1] = 5;
    r[2] = 3;
    r[3] = 4;
    r[4] = 6;
    r[5] = 2;
    length = 6;
  }
};


void 
InsertSort( SqList * L)
{
  int i, j;
  for (i = 2; i <= L->length; i++) {
    if (L->r[i] < L->r[i - 1])
    {
      L->r[0] = L->r[i];
      for (j = i - 1; L->r[j] > L->r[0]; j--) {
        L->r[j + 1] = L->r[j];
      }
      L->r[j + 1] = L->r[0];
    }
  }
}
int main()
{
  SqList sqlist;
  InsertSort(&sqlist);
  int* maxNums = new int[] {10, -1, 2, -33, 4, 5, 3, 2, 1,-5};
  int * pRange = MaxSubArray(maxNums,10);
  int nums[] = { 10,1,2,5,6,7,8,9,4 ,10,3 };
  int slow = 0;
  int fast = 0;
  while (true)
  {
    slow = nums[slow];
    fast = nums[nums[fast]];
    if (fast == slow)
      break;
  }
  printf("duplicated num is %d\n", nums[slow]);
  return 0;
}

  