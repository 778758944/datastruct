//
//  MGraph.h
//  Graph
//
//  Created by Tom Xing on 12/28/18.
//  Copyright © 2018 Tom Xing. All rights reserved.
//

#ifndef MGraph_h
#define MGraph_h
#define MAXVEX 100
#define INFINITY 65535

typedef char VertexType;
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
    VertexType data;
    EdgeNode * firstEdge;
} VertexNode, AdjList[MAXVEX];


typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;

void createMGraph(MGraph * G);
void createAlGraph(GraphAdjList * G);


#endif /* MGraph_h */
