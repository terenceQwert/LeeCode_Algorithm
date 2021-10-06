#include <Windows.h>
#include <stdio.h>
#include "BinaryTree.h"

void AddNode(TreeNode** node, int value)
{
  *node = new TreeNode(value);
}

void _BuildTree(TreeNode** root)
{
  TreeNode* start = *root;

  AddNode(&start->left, 49);
  AddNode(&start->left->left, 44);
  AddNode(&start->left->left->right, 77);

  AddNode(&start->left->right, 56);
  AddNode(&start->left->right->left, 07);

  AddNode(&start->right, 81);
  AddNode(&start->right->left, 82);
  AddNode(&start->right->right, 91);
  AddNode(&start->right->right->right, 101);
  AddNode(&start->right->right->right->right, 105);
  AddNode(&start->right->right->right->right->right, 106);

}

int 
GetMaxDepth(TreeNode* root)
{

  if (root == NULL)
    return 0;
  
  int left = GetMaxDepth(root->left);
  int right = GetMaxDepth(root->right);
  printf("node value:%3d, left = %3d, right = %3d \n", root->val, left, right);
  if (left >= right)
  {
    return left+1;
  }
  else
    return right+1;
}

int testBinaryTree()
{
  TreeNode* root = new TreeNode(37);
  /// build a new binarytree
  _BuildTree(&root);
  printf("max depth = %2d\n", GetMaxDepth(root));
  return GetMaxDepth(root);
}



//
// find cousin tree from starter.

int 
_GetDepth( TreeNode * root , int target, boolean * bFound)
{
  if (NULL == root) {
    bFound = FALSE;
    return 0;
  }
  if (root->val == target) {
    *bFound = true;
    return 0;
  }
  if (root->val != target)
  {
    int LeftDepth = _GetDepth(root->left, target, bFound) + 1;
    if (*bFound)
    {
      return LeftDepth;
    }
    int RightDepth = _GetDepth(root->right, target, bFound) + 1;
    if (*bFound)
    {
      return RightDepth;
    }
  }
}

void testCousinBinaryTree()
{
  TreeNode* root = new TreeNode(37);
  _BuildTree(&root);
  boolean bFound = FALSE;
  int Depth = _GetDepth(root, 37, &bFound);
  bFound = FALSE;
  Depth = _GetDepth(root, 82, & bFound);
  bFound = FALSE;
  Depth = _GetDepth(root, 49, & bFound);
  bFound = FALSE;
  Depth = _GetDepth(root, 81, & bFound);
}
