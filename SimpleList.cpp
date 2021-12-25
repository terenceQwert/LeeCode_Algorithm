#include <Windows.h>
#include <stdio.h>
#include <string>
#include <list>
#include <stack>
using namespace std;
struct ListNode {

  int m_value;
  ListNode *m_pNext;
};
void PrintListReversingly_Iteratively(ListNode * pHead);



void Build_Test_ListNodeForCPlusPlus()
{
  ListNode * start = new ListNode();
  ListNode * org = start;
  start->m_value = 0;
  ListNode * next = NULL;
  for (int i = 0; i < 100; i++)
  {
    next = new ListNode();
    next->m_value = 100+i;
    start->m_pNext = next;
    start = next;
  }
  ///
  /// let the last item back to 'start' item, then this list could be circular list
  ///
  start->m_pNext = org;
  PrintListReversingly_Iteratively(org);
}

void PrintListReversingly_Iteratively(ListNode * pHead)
{
  stack<ListNode *> nodes;
  ListNode * pNode = pHead;
  while (pNode != nullptr)
  {
    nodes.push(pNode);
    printf("%d\t", pNode->m_value);
    pNode = pNode->m_pNext;
  } 
  while (!nodes.empty())
  {
    pNode = nodes.top();
    printf("%d\t", pNode->m_value);
    nodes.pop();
  }
}





