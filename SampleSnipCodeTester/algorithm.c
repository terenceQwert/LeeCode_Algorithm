#include <stdio.h>
#include "Header.h"
// vertex 0
EdgeNode pNode0[] = {
  {11,11, NULL},
  {5,5,NULL},
  {4,4,NULL},
  {INFINITY,INFINITY,NULL}
};
EdgeNode pNode1[] = {
  {8,8, NULL},
  {4,4, NULL},
  {2,2, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode2[] = {
  {9,9, NULL},
  {6,6, NULL},
  {5,5, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode3[] = {
  {13,13, NULL},
  {2,2, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode4[] = {
  {7,7,NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode5[] = {
  {12,12, NULL},
  {8,8, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode6[] = {
  {5,5, NULL},
  {INFINITY,INFINITY,NULL}
};


EdgeNode pNode7[] = {
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode8[] = {
  {7,7, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode9[] = {
  {11,11, NULL},
  {10,10, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode10[] = {
  {13,13, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode11[] = {
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode12[] = {
  {9,9, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode13[] = {
  {INFINITY,INFINITY,NULL}
};
extern GraphAdjList GL;
VertextData gVertexTable[] = {
  {0, pNode0},
  {1, pNode1},
  {2, pNode2},
  {3, pNode3},
  {4, pNode4},
  {5, pNode5},
  {6, pNode6},
  {7, pNode7},
  {8, pNode8},
  {9, pNode9},
  {10, pNode10},
  {11, pNode11},
  {12, pNode12},
  {13, pNode13},
};


void _init()
{
  EdgeNode* pNext;
  for (int i = 0; i < sizeof(gVertexTable) / sizeof(VertextData); i++)
  {
    pNext = gVertexTable[i].pNode;
    int firstNode = 0;
    while (pNext->adjvex != INFINITY)
    {
      pNext->next = GL.adjList[i].firstEdge;
      GL.adjList[i].firstEdge = pNext;
      pNext = pNext++;
    }
  }
}

int
TopologicalSort(PGraphAdjList gL)
{
  EdgeNode* e;
  int i, k, gettop = 0;
  int top = 0;
  int count = 0;
  int* stack;
  stack = (int*)malloc(gL->numVertexes * sizeof(int));

  for (i = 0; i < gL->numVertexes; i++)
  {
    if (gL->adjList[i].in == 0)
    {
      stack[++top] = i; /* push it if 'in' filed of this vertext is zero */

    }

  }

  while (top != 0)
  {
    gettop = stack[top--]; // pop it out
    printf("%d -> ", gL->adjList[gettop].data);  // print this vertex
    count++;
    for (e = gL->adjList[gettop].firstEdge; e; e = e->next)
    {
      /* traversal all edege of this vertex */
      k = e->adjvex;
      if (!(--gL->adjList[k].in))
        stack[++top] = k; // if edge is 0, then push it into stack, to pop it for next circular output.
    }
  }

  if (count < gL->numVertexes) // if count is less than vertexes, it means circular is there.
    return -1;  // ERROR
  else
    return 0;   // OK


}

#if 1
// 2021-12-08
EdgeNode pNode20[] = {
  {1,3, NULL},
  {2,4, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode21[] = {
  {4,6, NULL},
  {3,5, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode22[] = {
  {5,7, NULL},
  {3,8, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode23[] = {
  {4,3, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode24[] = {
  {7,4, NULL},
  {6,9, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode25[] = {
  {7,6, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode26[] = {
  {9,2, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode27[] = {
  {8,5, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode28[] = {
  {9,3, NULL},
  {INFINITY,INFINITY,NULL}
};

EdgeNode pNode29[] = {
  {INFINITY,INFINITY,NULL}
};

#endif


int * etv;
int *ltv;
int * stack2;
int top2;

int
TopologicalSort2(PGraphAdjList GL)
{
  EdgeNode* e;
  int i, k, gettop;
  int top = 0;
  int count = 0;

  int* stack;
  stack = (int*)malloc(GL->numVertexes * sizeof(int));

  for( i=0;i<GL->numVertexes;i++){
      if (0 == GL->adjList[i].in)
        stack[++top] = i;
  }
  // initialize to 0
  top2 = 0;
  etv = (int*)malloc(GL->numVertexes & sizeof(int)); // the earliest time of event happened.
  for (i = 0; i < GL->numVertexes; i++)
  {
    etv[i] = 0;
  }
  stack2 = (int*)malloc(GL->numVertexes * sizeof(int));
  while (top != 0)
  {
    gettop = stack[top--];
    count++;
    stack2[++top2] = gettop;// push the vertex into topo queue for storing.
    for (e = GL->adjList[gettop].firstEdge; e; e = e->next)
    {
      k = e->adjvex;
      if (!(--GL->adjList[k].in))
      {
        stack[++top] = k;
      }
      //
      // ask the earliest time of happpened of each vertex.
      //
      if (((etv[gettop] + e->weight) > etv[k]))
        etv[k] = etv[gettop] + e->weight;
    }
  }
  if (count < GL->numVertexes)
    return -1;
  else
    return 0;
}

void CriticalPath(GraphAdjList * GL) {
  EdgeNode* e;
  int i, gettop, k, j;
  int ete, lte;
  TopologicalSort2(GL);

  ltv = (int*)malloc(GL->numVertexes * sizeof(int));  // the latest happened time of any of events...
  for (i = 0; i < GL->numVertexes; i++)
    ltv[i] = etv[GL->numVertexes - 1];                // initialize this lte array
  while (top2 != 0)
  {
    gettop = stack2[top2--];
    for (e = GL->adjList[gettop].firstEdge; e; e = e->next)
    {
      k = e->adjvex;
      if (ltv[k] - e->weight < ltv[gettop])
      {
        ltv[gettop] = ltv[k] - e->weight;
      }
    }
  }
  for (j = 0; j < GL->numVertexes; j++) {
    // calculate ete, lte and key activities
    for (e = GL->adjList[j].firstEdge; e; e = e->next)
    {
      k = e->adjvex;
      ete = etv[j];                 // the earliest time of this activity
      lte = ltv[k] - e->weight;     // the last time of this activity
      if (ete == lte)
        printf("<v%d, v%d> length:%d , ",
          GL->adjList[j].data, GL->adjList[k].data, e->weight);
    }
  }
}
