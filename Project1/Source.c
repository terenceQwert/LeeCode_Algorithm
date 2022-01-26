#define INITGUID

#include <windows.h>
#include <strsafe.h>
#include <stdio.h>
#include <stdlib.h>
#include <cfgmgr32.h>
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

#if 0
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
/* 317fc439-3f77-41c8-b09e-08ad63272aa3 */ 
DEFINE_GUID(GUID_GPIOBUTTONS_LAPTOPSLATE_INTERFACE, 0x317fc439, 0x3f77, 0x41c8, 0xb0, 0x9e, 0x08, 0xad, 0x63, 0x27, 0x2a, 0xa3);

DWORD
GetDevicePath(
  _In_ LPGUID InterfaceGuid,
  _Out_ LPWSTR* DevicePath
)
{
  CONFIGRET cmRet = CR_SUCCESS;
  ULONG interfaceListSize = 0;

  *DevicePath = NULL;

  cmRet = CM_Get_Device_Interface_List_Size_Ex(&interfaceListSize, InterfaceGuid, 0, CM_GET_DEVICE_INTERFACE_LIST_PRESENT, NULL);
  if (cmRet != CR_SUCCESS) {
    goto exit;
  }

  *DevicePath = (LPWSTR)LocalAlloc(LMEM_ZEROINIT, interfaceListSize * sizeof((*DevicePath)[0]));
  if (NULL == *DevicePath) {
    cmRet = CR_OUT_OF_MEMORY;
    goto exit;
  }

  cmRet = CM_Get_Device_Interface_List_Ex(InterfaceGuid, 0, *DevicePath, interfaceListSize, CM_GET_DEVICE_INTERFACE_LIST_PRESENT, NULL);

exit:

  if (cmRet != CR_SUCCESS) {
    if (NULL != *DevicePath) {
      LocalFree(*DevicePath);
      *DevicePath = NULL;
    }
  }

  return CM_MapCrToWin32Err(cmRet, ERROR_UNIDENTIFIED_ERROR);
}



int __cdecl ToggleConversionIndicator(
  __in int argc,
  __in_ecount(argc) char** argv)
{
  LPWSTR DevicePath;
  HANDLE FileHandle;
  BOOL b;
  BYTE buffer;
  HWND hwnd;
  MSG msg;
  //assuming our GetDevicePath method is creating a device path using use SetupDi API
  b = GetDevicePath((LPGUID)&GUID_GPIOBUTTONS_LAPTOPSLATE_INTERFACE, &DevicePath);
  printf("DevicePath = %s\n", DevicePath);
  FileHandle = CreateFile(DevicePath,
    GENERIC_WRITE,
    0,
    NULL,
    OPEN_EXISTING,
    0,
    NULL);

  if (argc > 1) {
    printf("buffer = 0\n");
    buffer = 0;
  }
  else
  {
    printf("buffer = 1\n");
    buffer = 1;
  }
  if (FileHandle == INVALID_HANDLE_VALUE)
  {
    printf("create file error with %x", GetLastError());
    return 0;
  }
  WriteFile(FileHandle, &buffer, sizeof(buffer), NULL, NULL);
  
  return 0;
}

int main(int argc, char ** argv)
{
  ToggleConversionIndicator(argc, argv);
//  CreateALGraph(&g_Al);
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


