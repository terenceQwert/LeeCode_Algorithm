#include <Windows.h>
#include <Windows.h>
#include <string.h>
#include <stdio.h>

void testRevservedBit(int num)
{
  char buf0[16] = { 0 };
  int index = 0;
  memset(buf0, 0x30, sizeof(buf0) / sizeof(char) - 1);
  while (num != 0)
  {
    buf0[index] = (num % 2) + 0x30;
    num /= 2;
    index++;
  }
  printf("original str=%s\n", buf0);
  char* buf1 = _strrev(buf0);
  printf("reversed str=%s\n", buf1);
}