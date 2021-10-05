#include <Windows.h>
#include <stdio.h>
#include "TreeNode.h"
#include "recursive.h"

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
    return LeftDepth += 1;

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