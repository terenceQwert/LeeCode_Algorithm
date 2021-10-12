#include <Windows.h>
#include <stdio.h>
#include <iostream>


using namespace std;




int Fabnacci(int n)
{
  if (n == 1)return 1;
  if (n == 0) return 0;
  return Fabnacci(n - 1) + Fabnacci(n - 2);
}



#if 0
int main()
{

#if 0
  int array[] = {-1,2,-10,3,-3,-4,1};
  int maxNum = maxSubArray(array, sizeof(array) / sizeof(int));
    int packet[6] = { 7,3,1,5,6,10 };
    int N;
    printf("input a value:");
    scanf_s("%d", &N);
    printf("\n");
    int* pSum = twoSum(packet, 6, N);
    if (NULL != pSum)
      printf("two sum is index [%d:%d]", pSum[0], pSum[1]);
    else
      printf(" Not found!\n");
    moveZero();
#endif

    printf("\n");
    return 0;
}
#endif
