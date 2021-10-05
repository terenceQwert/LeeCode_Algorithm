#include <Windows.h>

#include <stdio.h>

#include "hamming.h"

int testHammingAlgorithm()
{
  int number_1 = 1;
  int number_2 = 4;

  // convert them to bits string
  // preparing two string arra with 32 bytes length, and initialize them with '0x30' ("0")
  char buf_1[32];
  char buf_2[32];
  memset(buf_1, 0x30, sizeof(buf_1) / sizeof(char));
  memset(buf_2, 0x30, sizeof(buf_2) / sizeof(char));
  int index = 0;
  while (number_1 != 0)
  {
    char ch = 0x30;
    ch += number_1 % 2;
    number_1 = number_1 / 2;
    buf_1[index] = ch;
  }
  index = 0;
  while (number_2 != 0)
  {
    char ch = 0x30;
    ch += number_2 % 2;
    number_2 = number_2 / 2;
    buf_2[index] = ch;
    index++;
  }

  int diff = 0;
  for (int i = 0; i < 32; i++) {
    if (buf_1[i] != buf_2[i])
    {
      diff+=1;
    }
  }
  return diff;
}
