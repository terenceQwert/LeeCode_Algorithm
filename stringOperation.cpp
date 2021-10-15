#include <Windows.h>
#include <stdio.h>

#include "Empty.h"
#define MAX_STR_LENGTH 101

void push(char* source, int index, char value)
{
  source[index] = value;
}

void pop(char* source, int index)
{
  source[index] = '\0';
}

char* _RemoveHash(char* source)
{
  char* _str = (char*)malloc(MAX_STR_LENGTH);
  memset(_str, 0, MAX_STR_LENGTH);
  int _strIndex = 0;
  for (int i = 0; i < strlen(source); i++)
  {
    if (source[i] != '\#')
    {
      push(_str, _strIndex, source[i]);
      _strIndex+=1;
    }
    else
    {
      pop(_str, _strIndex);
      _strIndex -= 1;
    }
  }
  return _str;
}

void testEmpty()
{

  char* S = (char*)"AB#C";
  char* T = (char*)"AB#C";

  char* src_1 = _RemoveHash(S);
  char* src_2 = _RemoveHash(T);

}