#include <Windows.h>

#include <stdio.h>

void hammnigDistance(int x, int y)
{
  int diff = 0;
  int sx = x ^ y;
  while (sx>0)
  {
    if (sx % 2 != 0)
      diff += 1;
    sx /= 2;
  }
  printf("diff=%d\n", diff);
}

void HammingDistanceTestCase()
{
  int x, y;
  while(1) {
    printf("please type input Data:");
    scanf_s("%d", &x);
    scanf_s("%d", &y);
    hammnigDistance(x, y);
  }
}
