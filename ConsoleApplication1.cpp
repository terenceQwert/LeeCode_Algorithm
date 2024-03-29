// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>

#include <iostream>
#include "TreeNode.h"
#include "hamming.h"
#include "recursive.h"
#include "BinaryTree.h"
#include "Empty.h"
#include "ReservedBit.h"
#include "Prime.h"
#include "HashTable.h"
#include "GroupAnagram.h"
#include "SimpleQueue.h"
#include "ReversedPolishNotation.h"


#define STR_1 "STRING 1"
#define STR_2 "STRING 2"
#define STR_3 "STRING 3"

#define INITIALIZE_SIZE 1
#define FINAL_SIZE      2  
#define THIRD_SIZE      3

int Fabnacci(int n);

void testMethod()
{

  char *** table = NULL;
  table = (char***)malloc(sizeof(char*) * INITIALIZE_SIZE);
  memset(table, 0, sizeof(char***));
  table[0] = (char**)malloc(sizeof(char*) * INITIALIZE_SIZE);
  memset(table[0], 0, sizeof(char**));
  table[0][0] = (char*)STR_1;
  table[0] = (char**)realloc(table[0],sizeof(char*) * FINAL_SIZE);
  table[0][1] = (char*)STR_2;

  printf("data dump\n");
  printf("table[0][0] = %s \n", table[0][0]);
  printf("table[0][1] = %s \n", table[0][1]);


  printf("data realloc again\n");
  table = (char ***)realloc(table, sizeof(char*)* THIRD_SIZE);
  table[1] = (char**)malloc(sizeof(char*)* INITIALIZE_SIZE);
  table[1][0] = (char*)STR_3;
  printf("talbe[0][0] = %s\n", table[0][0]);
  printf("table[0][1] = %s\n", table[0][1]);
  printf("table[1][0] = %s\n", table[1][0]);
}

void Push( char* s, char c)
{
  int len = strlen(s);
  s[len] = c;
}

void Pop(char*s)
{
  s[strlen(s)-1] = '\0';
}

char * _removeCharIfEncounteredHash(char*s)
{
  char * newStr = (char*)malloc(100);
  memset(newStr, 0, 100);
  for (int i = 0; i < (int)strlen(s); i++)
  {
    if (s[i] != '#')
    {
      Push(newStr, s[i]);
    }
    else
    {
      Pop(newStr);
    }
  }
  return newStr;
}

void LeeCodeBackSpace()
{

  char *S = (char *)"ab#c";
  char *T = (char *)"ab#c";
  char * newS = _removeCharIfEncounteredHash(S);
  char *newT = _removeCharIfEncounteredHash(T);
  return;
}



void _AddNode(TreeNode **root, int val)
{
  TreeNode * pNode = new TreeNode(val);
  *root = pNode;
}

int 
MaxDeepth(TreeNode * root)
{
  if (root == NULL)
    return 0;
  int maxLeft = MaxDeepth(root->left);
  int maxRight = MaxDeepth(root->right);
  printf("max left = %d, max right=%d )value:%d\n", maxLeft, maxRight, root->val);
  
  if (maxLeft > maxRight)
    return maxLeft+1;
  else
    return maxRight + 1;

}

void _MakeTree(TreeNode **tree)
{
  //              78
  //           /      \
  //         22       86
  //        /  \      /  
  //       08  59    82
  //      /    / \
  //     03   56  71
  //              /
  //             62
  TreeNode *root = NULL;
  *tree = new TreeNode(78);
  root = *tree;
  _AddNode(&root->left, 22);
  _AddNode(&root->left->left, 8);
  _AddNode(&root->left->left->left, 3);

  _AddNode(&root->left->right, 59);
  _AddNode(&root->left->right->left, 56);
  _AddNode(&root->left->right->right, 71);
  _AddNode(&root->left->right->right->left, 62);
  _AddNode(&root->right, 86);
  _AddNode(&root->right->left, 82);

}


void testRevservedBit(int num);

extern char** g_Table;


void replaceStringWithAssignment(char * str)
{
  char *buffer = NULL;
  char *SimpleText = (char*)"We are happy";
  int basic = strlen(SimpleText);
  char *p1;
  char *p2;
  int num=0;
  // calculate how many space inside target string
  //
  for (int i = 0; i < basic; i++)
  {
    if (' ' == SimpleText[i])
      num++;
  }
  buffer = new char[basic + (num * 2)];
  int finalLen = basic + num * 2;
  p2 = &buffer[finalLen - 1];
  p1 = &SimpleText[basic - 1];
  for (int i = basic; i >= 0; i--)
  {
    if (' ' == *p1)
    {
      *p2 = '0';
      p2--;
      *p2 = '2';
      p2--;
      *p2 = '%';
    }
    else
    {
      *p2 = *p1;
    }
    p2--;
    p1--;
  }
  printf("--------------\n");
  printf("original string = %s\n", SimpleText);
  printf("modified string = %s\n", buffer);
  printf("--------------\n");
}

void Build_Test_ListNodeForCPlusPlus();
void Test_str_function();

int main()                                       
{
  /// <summary>
  /// add all signle test method
  /// </summary>
  /// <returns></returns>
  Test_str_function();
  Build_Test_ListNodeForCPlusPlus();
  printf("fabnacci %d\n",Fabnacci(3));
  replaceStringWithAssignment(NULL);
  int scancode = 0;
  scanf("%d", &scancode);
  int InInput = 0;
#if 0
  int *InData = new int[16]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
#else
  int *InData = new int[11]{ 0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
#endif
  std::cout << "input a number for searching ";
  scanf("%d",&InInput);
  int round = Binary_Search(InData, 16, InInput);
  printf("find location = %d\n", round);
  return 0;
  testRevservedBit(35);
  testStrStr();
  testQueue();
  for( int i =1;i<40;i++)
    printf( "fabnacci value = %d\n",Fabnacci(i));

  TestMoveZero();
  testCousinBinaryTree();
  testEmpty();
  testBinaryTree();

  StackData();
  int returnSize = 0;
  int* returnColumnSizes = NULL;
  groupAnagrams(g_Table, 6, &returnSize, &returnColumnSizes);
  testHammingAlgorithm();
  DiameterOfBinaryTree();
  LeeCodeBackSpace();
  testMethod();
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
