#include<Windows.h>
#include <stdio.h>
#include "ReversedPolishNotation.h"
#include <iostream>
using namespace std;


#define MATH_STRNIG "9+(3-1)*3+10/2"

#define _SIZE 256

#define LEFT_BRACKET    '('
#define RIGHT_BRACKET   ')'

#define MULTIPLE_SYMBOL '*'
#define DIVIDE_SYMBOL   '/'
#define PLUS_SYMBOL     '+'
#define MINUS_SYMBOL    '-'
#define SPACE_SYMBOL    ' '

const char delimiteres[7] = { LEFT_BRACKET,RIGHT_BRACKET, MULTIPLE_SYMBOL, DIVIDE_SYMBOL, PLUS_SYMBOL, MINUS_SYMBOL };

char* pMathSampleString = NULL;


void SymbolPush(int* dest, int ch);

void findArithmaticSymobol(char * pSymbols, int* destArray)
{
  bool bResult = true;
  int loc = 0;
  for (loc;; loc++)
  {
    if( (pSymbols[loc] == LEFT_BRACKET) ||
      (pSymbols[loc] == RIGHT_BRACKET) ||
      (pSymbols[loc] == MULTIPLE_SYMBOL) ||
      (pSymbols[loc] == DIVIDE_SYMBOL) ||
      (pSymbols[loc] == PLUS_SYMBOL) ||
      (pSymbols[loc] == MINUS_SYMBOL) ||
      (pSymbols[loc] == SPACE_SYMBOL) ){
      SymbolPush(destArray, pSymbols[loc]);
    }
    else
    {
      break;
    }

  }
}

void testStrStr()
{
  // example                  : 9 + ( 3 - 1 ) * 3 + 10 /  2
  // location in array          0 1 2 3 4 5 6 7 8 9 10 11 12

  pMathSampleString = new char[_SIZE]{ 0 };
  char buf[4] = { 0 };
  int len = 0;
  int symIndex = 0;
  int numIndex = 0;
  int nums[_SIZE] = { 0 };
  int syms[_SIZE] = { 0 };
  memcpy(pMathSampleString, MATH_STRNIG, strlen(MATH_STRNIG));
  char *pstr = strtok(pMathSampleString, delimiteres);
  nums[0] = *pstr;
//  pstr = strtok()

}

char* _GetElement()
{
  char* ptr = NULL;
  for (int i = 0; i < sizeof(delimiteres) / sizeof(char); i++)
  {
    if (NULL != ptr)
    {
      return ptr;
    }
  }
  return NULL;
}

int gStackIndex = 0;
void DataPush(int* pStack, int data)
{
  pStack[gStackIndex] = data;
  gStackIndex++;
}

int DataPop(int* pStack)
{
  if (gStackIndex == 0)
  {
    printf("stack is empty\n");
    return NULL;
  } 

  gStackIndex -= 1;
  return pStack[gStackIndex];
}


int gSymbolIndexLocation = 0;
void SymbolPush(int* pStack, int data)
{
  pStack[gSymbolIndexLocation] = data;
  gSymbolIndexLocation++;
}

void SymbolPop(int* pStack)
{
  pStack[gSymbolIndexLocation] = 0;
  gSymbolIndexLocation--;
}


void HandleBeforeRPN()
{
  ///
  /// convert MATCH_STRING to 931-3*+10 2/+
  /// 
  int len = strlen(MATH_STRNIG);
  int* pStack = (int*)malloc(len);
  int i = 0;
  while (i != len)
  {
//    if( )
    DataPush(pStack, MATH_STRNIG[i]);
    i++;
  }
}

void HandleRPN()

{

}