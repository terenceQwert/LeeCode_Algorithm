#include <Windows.h>
#include <stdio.h>

#include "Header.h" 




GraphAdjList GL =
{
  {
    {0,0, NULL},
    {0,1, NULL},
    {2,2, NULL},
    {0,3, NULL},
    {2,4, NULL},
    {3,5, NULL},
    {1,6, NULL},
    {2,7, NULL},
    {2,8, NULL},
    {1,9, NULL},
    {1,10, NULL},
    {2,11, NULL},
    {1,12, NULL},
    {2,13, NULL},
  },
  MAXVERTEX,
  4
};

extern EdgeNode pNode0[];

void _build_all()
{
  EdgeNode* pNext;
  for(int j = 0; j < MAXVERTEX;j++) {
    for (int i = 0; i < sizeof(pNode0) / sizeof(EdgeNode); i++)
    {
      // first node, we set its next to NULL
      pNext = &pNode0[i];
      if (0 != i)
      {
        //
        // due to we have initialized the default to NULL when firstEdge built....
        //
        pNext->next = GL.adjList[0].firstEdge;  
      }
      GL.adjList[0].firstEdge = pNext;
    }
  }

  EdgeNode* pEdgeNode = GL.adjList[0].firstEdge;
  for (;;)
  {
    printf("node value = %d \n", pEdgeNode->adjvex);
    if (pEdgeNode->next != NULL)
    {
      pEdgeNode = pEdgeNode->next;
    }
    else
    {
      break;
    }
  }
}


VOID BuildAllEdge()
{
  // build a link list 
  EdgeNode* p1;
  EdgeNode* pNext;

  pNext = (EdgeNode*)malloc(sizeof(EdgeNode));
  pNext->adjvex = 11;
  pNext->weight = 11;
  p1 = pNext;
  GL.adjList[0].firstEdge = p1;

  pNext = (EdgeNode*)malloc(sizeof(EdgeNode));
  pNext->adjvex = 5;
  pNext->weight = 5;
  // adjceent behind of next
  p1->next = pNext;
  p1 = pNext;

  pNext = (EdgeNode*)malloc(sizeof(EdgeNode));
  pNext->adjvex = 4;
  pNext->weight = 4;
  pNext->next = NULL;

  p1->next = pNext;
  p1 = pNext;

}

void 
_init_vertex( PGraphAdjList * pGL)
{
  *pGL = (PGraphAdjList)malloc(sizeof(GraphAdjList));
  PGraphAdjList pgl = *pGL;
  pgl->numEdges = 18;
  pgl->numVertexes = MAXVERTEX;

  // vertex 0
  VertexNode* pNode = (VertexNode*)malloc(sizeof(VertexNode));
  pNode->in = 0;
  pNode->data = 0;
  pgl->adjList[0].in = 0;
  pgl->adjList[0].data = 0;
  pgl->adjList[0].firstEdge = NULL;
  // build a link list 
  EdgeNode* p1;
  EdgeNode* pNext;

  p1 = (EdgeNode*)malloc(sizeof(EdgeNode));
  p1->adjvex = 11;
  p1->weight = 11;
  pgl->adjList[0].firstEdge = p1;

  pNext = (EdgeNode*)malloc(sizeof(EdgeNode));
  pNext->adjvex = 5;
  pNext->weight = 5;
  // adjceent behind of next
  p1->next = pNext;
  p1 = pNext;

  pNext = (EdgeNode*)malloc(sizeof(EdgeNode));
  pNext->adjvex = 4;
  pNext->weight = 4;
  pNext->next = NULL;

  p1->next = pNext;
  p1 = pNext;

  
}


void 
MiniSpanTree_Prim(Mgraph G)
{

}

void MinSpanTree_Prim(Mgraph G)
{
  int min, i, j, k;
  int adjvex[MAXVEX];
  int lowcost[MAXVEX];

  lowcost[0] = 0; // line 6 in book
  adjvex[0] = 0;  // line 7 in book

  //
  // initialize all data 
  //
  for (i = 1; i < G.numVertextes; i++)
  {
    lowcost[i] = G.arc[0][i];
    adjvex[i] = 0;
  }

  for (i = 1; i < G.numVertextes; i++)
  {
    min = INFINITY;
  
    j = 1; k = 0;
    while (j < G.numVertextes)
    {
      //
      // find out the minimum value, and store this value to min, and this point in "k".
      // Note:
      //  lowcost[j] !=0 <-- it is this same point, do not join saerching.
      //

      if (lowcost[j] != 0 && lowcost[j] < min)
      {
        // update this value into min
        min = lowcost[j];
        // update which point to "k"
        k = j;
      }
      // continue searching.
      j++;
    }

    printf("(%d,%d)", adjvex[k], k);
    lowcost[k] = 0;
    //
    // below is line 28 ~ 35
    //
    for (j = 1; j < G.numVertextes; j++)
    {
      //
      // if lowcost[j] = 0: it means it is same point, do not join saerching
      //
      if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
      {
        lowcost[j] = G.arc[k][j];
        adjvex[j] = k;
      }
    }
  }
}

typedef struct
{
  int begin;
  int end;
  int weight;
} Edge;


int Find(int* parent, int f)  /*find edge vetext end point*/
{
  //
  // original parenet array was initliazed as '0'
  //
  while (parent[f] > 0)
    f = parent[f];
  return f;
}
// Kruskal algorithm 
void MiniSpanTree_Krukal(Mgraph G)
{

  int i, n, m;
  Edge edges[MAXEDGES] = {
    {4,7,7},
    {2,8,8},
    {0,1,10},
    {0,5,11},
    {1,8,12},
    {3,7,16},
    {1,6,16},
    {5,6,17},
    {1,2,18},
    {6,7,19},
    {3,4,20},
    {3,8,21},
    {2,3,22},
    {3,6,24},
    {4,5,26}
  };
  int parent[MAXVEX];

  for (i = 0; i < G.numVertextes; i++)
  {
    parent[i] = 0;
  }
  for (i = 0; i < G.numEdges; i++)
  {
    n = Find(parent, edges[i].begin);
    m = Find(parent, edges[i].end);
    if (n != m)
    {
      parent[n] = m;
      printf("(%d, %d) %d ", edges[i].begin, edges[i].end, edges[i].weight);
    }
  }

}

int main()
{
  _init();
  TopologicalSort(&GL);
  _build_all();
  BuildAllEdge();
  PGraphAdjList GL;
  _init_vertex(&GL);
  /*
  * #define MAXVEX 9
  * #define MAXEDGES  15
  */
  Mgraph G;
  G.numVertextes = MAXVEX;
  G.numEdges = MAXEDGES;
  MiniSpanTree_Krukal(G);
  return 0;
}