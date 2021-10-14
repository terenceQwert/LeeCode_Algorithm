#include <Windows.h>
#include <stdio.h>

#include "Prime.h"
#include "HashTable.h"

void Prime()
{
  int N;
  printf("N = ");
  scanf_s("%d", &N);

  bool IsPrime = true;
  int number;
  for (number = 2; number < N; ++number)
  {
    if (N % number == 0)
    {
      IsPrime = false;
      break;
    }
  }

  if (true == IsPrime)
  {
    printf("Yes\n");
  }
  else
  {
    printf("No \n");
  }
}

int S(int N)
{

  if (N <= 2)
    return N;
  return S(N - 1) + S(N - 2);
}


int maxSubArray(int* array, int numSize)
{

  int maxnum = INT_MIN;
  int i = 0;
  int j = 0;
  printf("i j :sum : max\n");
  for (i = 0; i < numSize; i++)
  {
    int sum = 0;
    for (j = i; j < numSize; j++)
    {
      sum += array[j];
      if (sum > maxnum)
        maxnum = sum;
      printf("%d %d :%d : (%2d)\n", i, j, sum, maxnum);
    }
  }
  return maxnum;
}


void _switch(int* nums, int index)
{
  int temp;
  temp = nums[index + 1];
  nums[index + 1] = nums[index];
  nums[index] = temp;
}

void moveZero(int* nums, int numSize)
{
  // input: [3,0,1,12,0]
  // output:[3,1,12,0,0]
  int* newNums = new int[numSize] {0};
  int newIndex = 0;
  for (int i = 0; i < numSize; i++) {
    if (nums[i] != 0)
    {
      newNums[newIndex] = nums[i];
      newIndex++;
    }
  }
  memcpy(nums, newNums, numSize);
}

int* twoSum(int* array, int numSize, int targetNum)
{
  PHashTable phashTable = new HashTable[numSize]{ 0 };
  int sum[2] = { 0 };
  bool Match = false;
  for (int index = 0; index < numSize; index++)
  {
    phashTable[index].key = array[index];
    phashTable[index].value = index;
    sum[1] = index;
    for (int j = 0; j < index; j++)
    {
      printf("index:%d j:%d, target: %d\n", array[index], array[j], targetNum);
      if (phashTable[j].key == (targetNum - array[index]))
      {
        sum[0] = phashTable[j].value;
        Match = true;
      }
    }
  }
  if (true == Match)
    return sum;
  else
    return NULL;

}

void TestMoveZero()
{
  int nums[] = { 3,9,1,0,5,10,7,0,23,12,0 };
  moveZero(nums, sizeof(nums) / sizeof(int));
  for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
  {
    printf("%d ", nums[i]);
  }
}

#if 0
const char g_Table[10][10][10] = {
  {"tea","ate","eat"},
  {"nat","tan"},
  {"bat"},
  NULL
};
#endif

int
compCh(const void* src, const void* dest)
{
  return (int)(*(char*)src - *(char*)dest);
}



// char g_Table[10][10] = { "tea","bat","ate", "nat","eat","tan" };
char** g_Table = NULL;
void StackData()
{
  g_Table = (char**)malloc(sizeof(char*) * 10);
  g_Table[0] = (char*)malloc(10);
  strcpy_s(g_Table[0], 4, "tea");
  g_Table[1] = (char*)malloc(10);
  strcpy_s(g_Table[1], 4, "bat");
  g_Table[2] = (char*)malloc(10);
  strcpy_s(g_Table[2], 4, "ate");
  g_Table[3] = (char*)malloc(10);
  strcpy_s(g_Table[3], 4, "nat");
  g_Table[4] = (char*)malloc(10);
  strcpy_s(g_Table[4], 4, "eat");
  g_Table[5] = (char*)malloc(10);
  strcpy_s(g_Table[5], 4, "tan");
}

bool IsNumber(char ch)
{
  if ((ch == '0') ||
    (ch == '1') ||
    (ch == '2') ||
    (ch == '3') ||
    (ch == '4') ||
    (ch == '5') ||
    (ch == '6') ||
    (ch == '7') ||
    (ch == '8') ||
    (ch == '9')
    )
    return true;
  else
    return false;
}


typedef struct _HashData
{
  char loc;
  char data;
}HashData, *PHashData;

void testSplitString()
{
#define SAMPLE_MATH_ALGORITHM_STRNIG "9+(3-1)*3+ 10/2"
  HashData item[100]{ 0 };
  int hashIndex = 0;
  char * pstr = NULL;
  pstr = new char[256]{ 0 };
  strcpy(pstr, SAMPLE_MATH_ALGORITHM_STRNIG);
  for (int i = 0; i < strlen(pstr); i++)
  {
    if (IsNumber(pstr[i]) == false)
    {
      item[hashIndex].loc = i;
      item[hashIndex].data = pstr[i];
      hashIndex += 1;
    }
  }
  int _start;
  int _end;
  hashIndex = 0;
  for (;item[hashIndex].loc==0;)
  {
    
  }
}