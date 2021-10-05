#pragma once


class TreeNode
{
public:
  int val;
  TreeNode(int val) { this->val = val; }
  TreeNode() { val = 0; }
  TreeNode *left;
  TreeNode * right;
};

//
// basic method to build a test tree.
//
void _MakeTree(TreeNode **tree);

//
// internal method to return deep for a number.
// if match, return 0, or postive, it means deeps.
// if return negative, it means "not found" on this tree.
//
int
MaxDeepth(TreeNode * root);
