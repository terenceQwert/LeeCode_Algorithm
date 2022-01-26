#include <Windows.h>
#include <stdio.h>
#include "AVL_Header.h"

void R_Rotate(BiTree* p)
{
  BiTree L;
  L = (*p)->lchild;
  (*p)->lchild = L->rchild;
  L->rchild = (*p);
  *p = L;
}


void L_Rotate(BiTree* P)
{

  BiTree R;
  R = (*P)->rchild;
  (*P)->rchild = R->lchild;
  R->lchild = (*P);
  *P = R;
}

void LeftBalance(BiTree* T)
{
  BiTree L, Lr;

  L = (*T)->lchild;
  switch (L->bf)
  {
  case LH:
    (*T)->bf = L->bf = EH;
    R_Rotate(T);
    break;
  case RH:
    Lr = L->rchild;
    switch (Lr->bf)
    {
    case LH:
      (*T)->bf = RH;
      L->bf = EH;
      break;
    case EH:
      (*T)->bf = EH;
      L->bf = EH;
      break;
    case RH:
      (*T)->bf = EH;
      L->bf = LH;
      break;
    default:
      break;
    }
    Lr->bf = EH;
    L_Rotate(&(*T)->lchild);
    R_Rotate(T);
    break;
  default:
    break;
  }
}


