#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;


int testItem(char pArray[4])
{
  printf("pArray = 0x%x\n", pArray[0]);
  return 0;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int i = 0;
  int* pData = NULL;
  for (i; i < numsSize; i++)
  {
    int j = i + 1;
    for (j; j < numsSize; j++)
    {
      int data = nums[i] | nums[j];
      if (data == target)
      {
        pData = (int*)malloc(sizeof(int) * 2);
        pData[0] = i;
        pData[1] = j;
        *returnSize = 2;
        break;
      }
    }
  }
  return pData;
}
int longestArithSeqLength(vector<int>& nums)
{
  int n = nums.size();
  if (n <= 2)
    return n;

  vector<map<int, int>> dp(n);
  int max_len = 2;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int diff = nums[j] - nums[i];
      if (dp[i].find(diff) != dp[i].end())
      {
        dp[j][diff] = dp[i][diff] + 1;
      }
      else
      {
        dp[j][diff] = 2;
      }
      max_len = max(max_len, dp[j][diff]);
    }
  }
  return max_len;
}

#define MAX_SIZE 1024
struct ListNode {
  int val;
  struct ListNode* next;
};

void ListConvert(struct ListNode* list, int length)
{
  int SizetoCopy = sizeof(ListNode) * length;
  ListNode* plist = list;
//  struct ListNode* tmp = (ListNode*)malloc(sizeof(ListNode) * length);
  int* tmp = (int*)malloc(sizeof(int) * length);
  int j = 0;
  do
  {
    tmp[j] = plist->val;
    j++;
    plist = plist->next;
  } while (plist != NULL);
  // revert 
  for (int i = length - 1; i >= 0; i--)
  {
    list->val = tmp[i];
    list = list->next;
  }
}

/// <summary>
/// pick up num from element of an array, then do 10 power n arithmatic.
/// </summary>
/// <param name="list"></param>
/// <returns></returns>

unsigned long GetArithmaticNumber(ListNode* list)
{
  int count=0;
  unsigned long ReturnValue = 0;
  ListNode* pTemp = list;
  while (pTemp != NULL)
  {
    ReturnValue += pTemp->val * pow(10, count);
    count++;
    pTemp = pTemp->next;

  }

  return ReturnValue;
}

void CreateTestCase(ListNode* plist)
{
  plist->val = 2;
  plist->next = (ListNode*)malloc(sizeof(ListNode));
  plist->next->val = 4;
  plist->next->next = (ListNode*)malloc(sizeof(ListNode));
  plist->next->next->val = 3;
  plist->next->next->next = NULL;
}


void CreateTestCase2(ListNode* pNode2)
{
  pNode2->val = 5;
  pNode2->next = (ListNode*)malloc(sizeof(ListNode));
  pNode2->next->val = 6;
  pNode2->next->next = (ListNode*)malloc(sizeof(ListNode));
  pNode2->next->next->val = 4;
  pNode2->next->next->next = NULL;
}

void CreateTestCase3(ListNode* pNode2)
{
  pNode2->val = 9;
  pNode2->next = NULL;
}
void CreateTestCase4(ListNode* pNode2)
{
#define MAX_NUM 8
  ListNode* pInitializeIndex = pNode2;
  pNode2->val = 1;
  pNode2->next = (ListNode*)malloc(sizeof(ListNode));
  pNode2 = pNode2->next;
  int i = 0;
//  for (i; i < 9; i++)
  for( i;i< MAX_NUM;i++)
  {
    pNode2->val = 9;
//    if (8 == i)
//    if( (MAX_NUM-1) ==i )
//    {
//      pNode2->next = NULL;
//    } else
//    {
      pNode2->next = (ListNode*)malloc(sizeof(ListNode));
      pNode2 = pNode2->next;
      pNode2->val = 0;
      pNode2->next = NULL;
//    }
  }
  
}

void ComparePower()
{
//  ULONG64 TenOfPower = 9 * pow(10, 10);
}


void TestMulitipleList()
{
  int pArray[] = { 3,3,1,4,4,7,7 };
  int Result = 0;
  for (int i = 0; i < ((sizeof(pArray) / sizeof(int))-1); i++)
  {
    Result += (pArray[i] ^ pArray[i + 1]);
  }

}


int addDigital()
{
  unsigned int sum = 0;
  scanf("%d", &sum);

  do 
  {
    sum = sum / 10 + sum % 10;
  } while (sum >= 10);
  printf("sum = %d\n", sum);
  return sum;
}

int addDigital_2()
{
  unsigned int sum = 0;
  scanf("%d", &sum);

  if (sum == 0)
    return 0;
  else if (sum % 9 == 0)
    return 9;
  return sum % 9;
  /*
  * 9*1 = 9   <-- (0) 1: 1, 2:2
  * 9*2 = 18  <-- (1) 10: 1, 11 :2
  * 9*3 = 27  <-- (2) 19: --> 10 --> 1, 20: 2
  * ...           (3) 28: --> 10 --> 1 
  * ...
  */
}

int main()
{
  return addDigital();
#if 0
  TestMulitipleList();
  //
  // first
  //
  ListNode* pData = (ListNode*)malloc(sizeof(ListNode));
  CreateTestCase3(pData);
  unsigned long Value1 = GetArithmaticNumber(pData);

  //
  // second
  //
  ListNode* pNode2 = (ListNode*)malloc(sizeof(ListNode));
  CreateTestCase4(pNode2);
//  ListConvert(pNode2,10);
  unsigned long Value2 = GetArithmaticNumber(pNode2);
  
  char strBuf[1024] = { 0 };
  sprintf(strBuf, "%d", Value1 + Value2);
//  sprintf(strBuf, "%d", total);
//  itoa(total, strBuf, 10);
  int length = strlen(strBuf);
  ListNode* pCalculatelist = NULL;
  ListNode* finalList = (ListNode*)malloc(sizeof(ListNode));
  pCalculatelist = finalList;
  for (int index = length-1; index >=0; index--)
  {
    char val[1] = { 0 };
    val[0] = strBuf[index];
    finalList->val = atol(val);
    if (index == 0)
      finalList->next = NULL;
    else
    {
      finalList->next = (ListNode*)malloc(sizeof(ListNode));
      finalList = finalList->next;
    }
  }
#endif

}

