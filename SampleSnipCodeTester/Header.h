#pragma once


#define MAXVEX 9
#define MAXVERTEX 14

#define MAXEDGES  15
#define INFINITY 65535

typedef struct _MGraph
{
  int numVertextes;
  int numEdges;
  int arc[MAXVEX][MAXVEX];
} Mgraph;

/* 2021/12/02 topology algorithm */
typedef struct {
  /* adjvect: vertext or called node */
  int adjvex;
  int weight;
  struct EdgeNode* next;
} EdgeNode;


typedef struct _VertexNode {
  int in;
  int data;
  EdgeNode* firstEdge;
} VertexNode, AdjList[MAXVERTEX];

typedef struct _GraphAdjList
{
  AdjList adjList;
  int numVertexes;
  int numEdges;
} GraphAdjList, * PGraphAdjList;

typedef struct _VertexData
{
  int vertex;
  EdgeNode* pNode;
} VertextData;

