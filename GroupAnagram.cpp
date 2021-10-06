#include <Windows.h>
#include <stdio.h>
#include "HashTable.h"

extern char** g_Table;
int
compPair(const void* array1, const void* array2)
{
  PAIR* pa = (PAIR*)array1;
  PAIR* pb = (PAIR*)array2;
  return strcmp(pa->sorted, pb->sorted);
  //  return strcmp((const char*)array1->sorted, (const char*)array2);

}

char***
groupAnagrams(
  char** strs,
  int strSize,
  int* returnSize,
  int** returnColumnSizes)
{
  // strs: ["ate","eat,"tan,"tea","nat","bat"], strSize: 6
  // return
  // [
  //  ["ate","eat","tea"],
  //  ["nat","tan"],
  //  ["bat"]
  // ]
  // *returnSize: 3
  // *returnColumnSizes: { 3,2,1}
  PAIR* pairs = (PAIR*)malloc(sizeof(PAIR) * strSize);
  for (int i = 0; i < strSize; i++)
  {
    char* sorted_str = (char*)malloc(strlen(strs[i]) + 1);
    strcpy_s(sorted_str, 4, strs[i]);

    qsort(sorted_str, strlen(strs[i]), sizeof(char), compCh);
    //printf("%s: %s\n", strs[i], sorted_str);
    pairs[i].original = strs[i];
    pairs[i].sorted = sorted_str;
    printf(" %s: %s\n", pairs[i].original, pairs[i].sorted);

  }
  printf("after doign pair sort\n");
  qsort(pairs, strSize, sizeof(PAIR), compPair);
  for (int i = 0; i < strSize; i++)
  {
    printf(" %s: %s\n", pairs[i].original, pairs[i].sorted);
  }

  char*** returnResult = NULL;
#if 1
#else
  returnResult = (char***)malloc(sizeof(char***) * 4);
  memset(returnResult, 0, sizeof(char***) * 4);
  returnResult[0] = (char**)malloc(sizeof(char**) * 4);
  memset(returnResult[0], 0, sizeof(char***) * 4);
  returnResult[1] = (char**)malloc(sizeof(char**) * 4);
  memset(returnResult[1], 0, sizeof(char***) * 4);
  returnResult[2] = (char**)malloc(sizeof(char**) * 4);
  memset(returnResult[2], 0, sizeof(char***) * 4);
  returnResult[3] = (char**)malloc(sizeof(char**) * 4);
  memset(returnResult[3], 0, sizeof(char***) * 4);
#endif
  int CountSize = 0;
  int Tableindex = 0;
  int origIndx = 0;
  printf("start to build a 3-dimention array\n");

  for (int i = 0; i < strSize; i++) {

    if ((i == 0) || 0 != strcmp(pairs[i].sorted, pairs[i - 1].sorted))
    {
      /// <summary>
      /// Keep current indexer, and used for same element.
      /// </summary>
      origIndx = Tableindex;
      //
      // moving to next new entry.
      //
      Tableindex += 1;

      ///
      /// update 3rd dimension array size
      /// 
      *returnSize += 1;
      if (0 == i)
        returnResult = (char***)malloc(sizeof(char***));
      else
        returnResult = (char***)realloc(returnResult, sizeof(char***) * *returnSize);

      returnResult[origIndx] = (char**)malloc(sizeof(char**));
      //
      // due to new, adding element at start '0' position.
      //
      returnResult[origIndx][0] = pairs[i].original;
      // reset 2nd indexer, reutrns to original point.....
      CountSize = 0;

    }
    else
    {
      CountSize += 1;
      /// <summary>
      /// create a local variable to help storage necessary size for memory allocation.
      /// </summary>
      int assginedSize = CountSize + 1;
      returnResult[origIndx] = (char**)realloc(returnResult[origIndx], assginedSize);
      returnResult[origIndx][CountSize] = pairs[i].original;
    }
  }
  printf("=======================\n");
#if 0
  for (int i = 0; i < 4; i++)
  {
    printf("{ ");
    for (int j = 0; j < 4; j++) {
      if (NULL != returnResult[i][j]) {
        printf("%s, ", returnResult[i][j]);
      }
    }
    printf("}\n");

  }
#endif
  return NULL;
}


