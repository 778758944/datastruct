//
//  MGraph.h
//  Graph
//
//  Created by Tom Xing on 12/28/18.
//  Copyright © 2018 Tom Xing. All rights reserved.
//

#ifndef MGraph_h
#define MGraph_h
#include <stdbool.h>
#include <stdio.h>
#define MAXVEX 100
#define INFINITY 65535

typedef int VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVectexes, numEdges;
} MGraph;


typedef struct EdgeNode {
    int adjvex;
    EdgeType weight;
    struct EdgeNode * next;
} EdgeNode;

typedef struct {
    int ind;
    VertexType data;
    EdgeNode * firstEdge;
} VertexNode, AdjList[MAXVEX];


typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;

typedef struct {
    int begin;
    int end;
    int weight;
} Edge;

typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

void createMGraph(MGraph * G);
void createAlGraph(GraphAdjList * G);
void createAlGraphWithD(GraphAdjList * G);

// MGraph DFS
void MDfs(MGraph G, int i);
void M_DFS_TRAVERSE(MGraph G);

// Adj DFS
void AdjDfs(GraphAdjList G, int i);
void ADJ_DFS_TRAVERSE(GraphAdjList G);

// BFS
void M_BFS_TRAVERSE(MGraph G);
void ADJ_BFS_TRAVERSE(GraphAdjList G);

void MiniSpanTree_Prim(MGraph G);
void MiniSpanTree_Prim2(MGraph G);

void MiniSpanTree_Kruskal(MGraph G);

void ShortestPath_Dijkstra(MGraph G, int v0, Patharc * P, ShortPathTable * D);

void ShortestPath_Dijkstra2(MGraph G, int index, Patharc P, ShortPathTable D);

// top logica
bool ToplogicalSort(GraphAdjList * G);
bool ToplogicalSort2(GraphAdjList * G);

void CriticalPath(GraphAdjList * G);

// review1
void M_DFS_TRAVERSE2(MGraph G);
void M_BFS_TRAVERSE2(MGraph G);
void MiniSpanTree_Prim3(MGraph G);
void ShortestPath_Dijkstra3(MGraph G, int v, int * D, int * P);
void ADJ_DFS_TRAVERSE2(GraphAdjList G);
void ADJ_BFS_TRAVERSE2(GraphAdjList G);
bool Toplogical_Sort3(GraphAdjList G);



#endif /* MGraph_h */
