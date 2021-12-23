#include <Windows.h>
#include <stdio.h>

typedef struct BiTNode {
  int data;
  struct BiTNode* lchild, * rchild;
} BiTNode, *BiTree;


boolean 
SearchBST(BiTree T, int key, BiTree f, BiTree* p)
{
  if (!T)
  {
    *p = f;
    return FALSE;
  }
  else if (key == T->data) {
    // find one 
    *p = T;
    return TRUE;
  }
  else if (key < T->data)
  {
    return SearchBST(T->lchild, key, T, p);
  }
  else
    return SearchBST(T->rchild, key, T, p);
}

boolean 
InsertBST(BiTree* T, int key)
{
  BiTree  p, s;
  if (!SearchBST(*T, key, NULL, &p))
  {
    // can not find it
    s = (BiTree)malloc(sizeof(BiTNode));
    s->data = key;
    s->lchild = s->rchild = NULL;
    if (!p)
    {
      /// it is used to insert new node 's' as root 
      *T = s;
    }
    else if (key < p->data)
    {
      // insert @left side of this tree
      p->lchild = s;
    }
    else
    {
      p->rchild = s;
    }
    return TRUE;
  }
  else
    return FALSE;
}


void initiailzeBiTree()
{
  int i;
  int a[10] = { 62,88,58,47,35,73,51,99,37,93 };
  BiTree T = NULL;
  for (i = 0; i < 10; i++) {
    InsertBST(&T, a[i]);
  }
}

