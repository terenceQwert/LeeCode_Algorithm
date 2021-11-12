#include<Windows.h>
#include <stdio.h>
#include "ReversedPolishNotation.h"
#include <iostream>
#include <vector>
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

typedef struct _NumHashTable
{
  char i;
  char ch;
} NumHashTable, *PNumHashTable;

// #define MATH_STRNIG "9+(3-1)*3+10/2"
NumHashTable* pNumHashTable = NULL;
int hIndex=0;

bool IsNumber(char ch)
{
  if( (ch=='0') || (ch == '1') || (ch == '2') || (ch == '3') || (ch == '4') || (ch == '5' )|| (ch == '6') || (ch == '7') || (ch == '8') || (ch == '9'))
    return true;
  else
    return false;
}

void HandleRPN()
{
  char* pstr = new char[strlen(MATH_STRNIG)];
  int i = 0;
  int nums[100] = { 0 };
  strcpy(pstr, MATH_STRNIG);
  pNumHashTable = new NumHashTable[strlen(pstr)]{ 0 };
  memset(pNumHashTable, 0xff, sizeof(NumHashTable) * strlen(pstr));
  for (i = 0; i < strlen(pstr); i++)
  {
    if (IsNumber(pstr[i]) == false)
    {
      pNumHashTable[hIndex].i = i;
      pNumHashTable[hIndex].ch = pstr[i];
      hIndex += 1;
    }
  }
  int pos_start = 0;
  int pos_end = 0;
  i = 0;
  pos_end = pNumHashTable[0].i - 0;

}

