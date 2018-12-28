#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXVEX 100 // man vex number
#define INFINITY 65535

typedef char VertexType;
typedef int EdgeType;

static bool visited[MAXVEX];


typedef struct {
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

typedef struct EdgeNode {
    int adjvex;
    EdgeType weight;
    struct EdgeNode * next;
} EdgeNode;

typedef struct VertexNode {
    VertexType data;
    EdgeNode * firstedge;
} VertexNode, AdjList[MAXVEX];


typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;



void CreateMGraph(MGraph *G);
void CreateALGraph(GraphAdjList * G);
void DFS(MGraph G, int i);
void DFSTraverse(MGraph G);
void DFSForAdjList(GraphAdjList G, int i);
void DFSTraverseForAdjList(GraphAdjList G);
void MiniSpanTree_Prim(MGraph G);
