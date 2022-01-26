#pragma once

typedef struct BiTNode {
  int data;
  int bf;
  struct BiTNode* lchild, * rchild;
} BiTnode, *BiTree;


void R_Rotate(BiTree* p);

void L_Rotate(BiTree* P);

#define LH +1 // Left higher 
#define EH  0 // Equal height
#define RH -1 // Right higher

void LeftBalance(BiTree* T);

void
HammingDistanceTestCase();