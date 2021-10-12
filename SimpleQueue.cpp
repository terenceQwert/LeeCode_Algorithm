#include <Windows.h>
#include <stdio.h>

#include "SimpleQueue.h"

void EnQueue(LinkQueue * Q, int e)
{
  QNode * s = (QNode *)malloc(sizeof(QNode));
  s->data = e;
  s->next = NULL;
  Q->rear->next = s;
  Q->rear = s;
}

bool DeQueue(LinkQueue * Q)
{
  if (Q->front == Q->rear)
  {
    printf("front is same as rear, Queue is empty\n");
    return false;
  }


  QNode * p = Q->front->next;
  
  printf("Dequeue one element, its data = %d\n", p->data);
  Q->front->next = Q->front->next->next;

  if (p == Q->rear)
  {
    ///
    /// it is the final element, so the Q->rear = Q->front
    ///
    Q->front = Q->rear;
  }
//  printf("check the 2nd element is predicted data ? %d\n", Q->front->next->data);
  return true;
}

void
testQueue()
{
  LinkQueue *plQueue = new LinkQueue();
  QNode *pFirstQ = new QNode();
  pFirstQ->data = 0;
  plQueue->front = plQueue->rear = pFirstQ;
  EnQueue(plQueue, 1);
  EnQueue(plQueue, 2);
  EnQueue(plQueue, 4);
  EnQueue(plQueue, 3);
  EnQueue(plQueue, 54);
  EnQueue(plQueue, 4332);
  EnQueue(plQueue, 2322);
  EnQueue(plQueue, 21);

  while ( false != DeQueue(plQueue) );




}

