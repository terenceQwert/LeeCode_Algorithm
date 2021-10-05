// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "hamming.h"
#define STR_1 "STRING 1"
#define STR_2 "STRING 2"
#define STR_3 "STRING 3"

#define INITIALIZE_SIZE 1
#define FINAL_SIZE      2  
#define THIRD_SIZE      3

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

class TreeNode
{
public:
  int val;
  TreeNode(int val) { this->val = val; }
  TreeNode() { val = 0; }
  TreeNode *left;
  TreeNode * right;
};

typedef enum Side {
  LEFT,
  RIGHT
};

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
  //           /     \
  //         22      86
  //        /  \     /  
  //       08  59   82
  //      /    / \
  //     03   56 71
  //             /
  //            62
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



int GetDepth(TreeNode * root, int target)
{
  if (root == NULL)
  {
    printf("val = NULL\n");
    return -1;
  } 
  printf("val = %d\n", root->val);
  if (root->val == target)
  {
    return 0;
  }
  int LeftDepth = GetDepth(root->left, target);
  if (LeftDepth != -1)
    return LeftDepth+=1;

  int RightDepth = GetDepth(root->right, target);
  if (RightDepth != -1)

    return RightDepth += 1;

  // not found
  return -1;
}

void DiameterOfBinaryTree()
{
  TreeNode *root = NULL;
  _MakeTree(&root);

  ///
  int depth = GetDepth(root, 86);
  depth = GetDepth(root, 59);
  
  /// given a 'not found' case 
  depth = GetDepth(root, 101);
  int maxDepthValue = MaxDeepth(root);

  printf("-------\n");
  printf("max depth:%d\n", maxDepthValue);
  printf("-------\n");
}

int main()                                       
{
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
