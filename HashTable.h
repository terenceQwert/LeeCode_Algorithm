#pragma once

typedef struct _hasTable
{
  int key;
  int value;
} HashTable, * PHashTable;


typedef struct _PAIR
{
  char* original;
  char* sorted;
} PAIR, * PPAIR;

int sum(int N);
void StackData();

/// <summary>
/// define these function is for comparison of character 1 and character 2, and used for qsort standard C API
/// </summary>
/// <param name="src"></param>
/// <param name="dest"></param>
/// <returns>0: if same, otherwise, it is not same </returns>
int
compCh(const void* src, const void* dest);

/// <summary>
/// define this function is for comparison of two string, and invoke strcmp().
/// </summary>
/// <param name="array1"></param>
/// <param name="array2"></param>
/// <returns>0 is same, other value is not same </returns>
int
compPair(const void* array1, const void* array2);
