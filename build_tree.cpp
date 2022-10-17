#include <Windows.h>
#include  <stdio.h>

struct BinaryTreeNode
{
  int m_nValue;
  BinaryTreeNode * m_pLeft;
  BinaryTreeNode * m_pRight;
};


BinaryTreeNode * ConstructCore(int * startPreorder, int * endPreorder,
  int * startInorder, int *endInorder)
{
  return NULL;
}

BinaryTreeNode * Construct(int * preorder, int * inorder, int length)
{

  if (preorder == nullptr || inorder == nullptr || length <= 0)
  {
    return nullptr;
  }
  return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

