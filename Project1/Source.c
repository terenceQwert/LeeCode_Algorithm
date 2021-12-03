#include <Windows.h>
#include <stdio.h>

typedef struct _Data
{
  UINT32 m;
  UINT32 n;
} Data;

typedef struct _Item
{
  Data ;
  int k;
} Item;


typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 9





typedef struct _EdgeNode {
  int adjvex;
  EdgeType info;

  struct EdgeNode* next;
}EdgeNode;

typedef struct _VertextNode {
  VertexType data;
  EdgeNode* firstedge;
} VertextNode, AdjList[MAXVEX];

typedef struct {
  AdjList adjList;
  int numNodes;
  int numEdges;
} GraphAdjList;

#if 1
void 
CreateALGraph(GraphAdjList* G)
{
  int i, j, k;
  EdgeNode* e;
  printf(" Pleazseinput vertex & edges \n");
  scanf("%d,%d", &G->numNodes, &G->numEdges);

  for (i = 0; i < G->numNodes; i++) {
    scanf(&G->adjList[i].data);
    G->adjList[i].firstedge = NULL;
  }

  for (k = 0; k < G->numEdges; k++)
  {
    printf("Plaese input edge (Vi,Vj) vex numbers \n");
    scanf("%d,%d", &i, &j);
    e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = j;
    e->info = j;
    e->next = G->adjList[i].firstedge;
    G->adjList[i].firstedge = e;

    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = i;
    e->info = i;
    e->next = G->adjList[i].firstedge;
    G->adjList[i].firstedge = e;

  }
}
#endif
GraphAdjList g_Al;

int gShortestTable[10][10] = { {0,0} };



int main()
{
  CreateALGraph(&g_Al);
  Item p;
  memset(&p, 0, sizeof(Item));
  p.k = 1;

  (*gShortestTable)[0] = 0;
  (*gShortestTable)[1] = 1;
  (*gShortestTable)[2] = 2;


  char** ptr = (char**)malloc(10);

  char** org = ptr;


  for( int i =0;i<=9;i++)
  { 
    *ptr = (char*)malloc(10);
    printf("level-%d %p\n",i, *ptr);
    ptr++;
  }

  (*org)[1] = 0;
  org++;
  (*org)[1] = 1;
  org++;
  (*org)[1] = 2;
  org++;
  (*org)[1] = 3;

#if 0  
  org[0][0] = 0;
  (*org)++;
  org[1][1] = 1;
  printf("org[1][1] = %d\n", (*org)[1]);
  (*org)++;
  org[2][2] = 2;
  printf("org[2][1] = %d\n", (*org)[1]);
  (*org)++;
  org[3][3] = 3;
  printf("org[3][1] = %d\n", (*org)[1]);
#endif

  return 0;
}


