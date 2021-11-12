#include <Windows.h>
#include <stdio.h>
enum Status
{
  OK,
  FAIL
};
typedef int QElementType;
#define MAXSIZE 6
typedef struct
{
  QElementType data[MAXSIZE];
  int front;
  int rear;

} SqQueue;

#include "SimpleQueue.h"

#if 1
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


  const QNode * p = Q->front->next;
  
  printf("Dequeue one element, its data = %d\n", p->data);
  // 
  // here: p means 'Q->front->next'
  //
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
#else
Status InitQueue(SqQueue* Q)
{
  Q->front = 0;
  Q->rear = 0;
  return OK;
}

int QueueLength(SqQueue Q)
{
  return (MAXSIZE + Q.rear - Q.front) % MAXSIZE;
}
Status EnQueue(SqQueue* Q, QElementType e)
{
  if (((Q->rear + 1) % MAXSIZE) == Q->front)
  {
    return FAIL;
  }
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXSIZE;
  return OK;
}

Status DeQueue(SqQueue* Q, QElementType* e)
{
  if (Q->front == Q->rear)
    return FAIL;
  *e = Q->data[Q->front];
  Q->front = (Q->front + 1) % MAXSIZE;
  return OK;
}
#endif
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

