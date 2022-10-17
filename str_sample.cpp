#include <Windows.h>
#include <string.h>
#include <stdio.h>

void ShiftStr(char* str, int** shiftCole, int ShiftSize);
void Test_str_function()
{
  char buf[20] = { 0 };
  strcpy_s( buf,20, "abcd");
  int* shift[2] = { 0 };
  shift[0] = new int[2]{ 0,1 };
  shift[1] = new int[2]{ 1,5 };
  int shiftSize = 2;
  ShiftStr( buf, shift, shiftSize);

}

void ShiftStr(char* str, int** shiftCole, int ShiftSize)
{
  int len = strlen(str);
  char temp;

  
  for (int index = 0; index < ShiftSize; index++) {
    int direction = shiftCole[index][0];
    int amount = shiftCole[index][1];
    // 0: toward left direction
    // 1: toward right direction

    // e.g. str is 'abcd', len = 4
    // left orientation 1 times, ==> bcda

    // right orientation 1st times, ==> dabc
    // right orientation 2nd times, ==> cdab
    // right orientation 3rd times, ==> bcda  <-- it's same as left orientaion 1 times.
    // therefore, we'd use only left orientation to instead of all 'right orientation', amount = len - amount;

    // but, we should take care if amount > len, 
    /// get remainder thru % marks

    amount = amount % len;
    if (1 == direction) {
      amount = len - amount;
    }

    for (int i = 0; i < amount; i++) {
      temp = str[0];
      for (int j = 0; j < len - 1; j++)
      {
        str[j] = str[j + 1];
      }
      str[len - 1] = temp;
    }
  }
  printf("%s\n", str);
}

