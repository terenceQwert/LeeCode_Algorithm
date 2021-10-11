#pragma once
#include <Windows.h>
typedef int QElemType;

class QNode {
public:
  int data;
  QNode *next;
};

typedef struct MyStruct
{
  QNode * front;
  QNode *rear;
} LinkQueue; 


void EnQueue(LinkQueue * Q, int e);

bool DeQueue(LinkQueue * Q);

void testQueue();