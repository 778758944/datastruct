//
//  MGraph.c
//  Graph
//
//  Created by Tom Xing on 12/28/18.
//  Copyright © 2018 Tom Xing. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

void createMGraph(MGraph * G) {
    printf("Please enter the number of vectex and edge: ");
    scanf("%d %d", &(G->numVectexes), &(G->numEdges));
    printf("numVectexes: %d, numEdges: %d\n", G->numVectexes, G->numEdges);
    
    while(getchar() != '\n') continue;
    
    printf("Please enter %d for each node: ", G->numVectexes);
    for(int i = 0; i < G->numVectexes; i++) {
        scanf("%c", &(G->vexs[i]));
    }
    
    while(getchar() != '\n') continue;
    
    for (int i = 0; i < G->numVectexes; i++) {
        for (int j = 0; j < G->numVectexes; j++) {
            G->arc[i][j] = INFINITY;
        }
    }
    
    
    for (int i = 0; i < G->numEdges; i++) {
        int x, y, v;
        printf("Please enter the x, y and value for it: ");
        scanf("%d%d%d", &x, &y, &v);
        G->arc[x][y] = v;
    }
    
    while(getchar() != '\n') continue;
    
}

void createAlGraph(GraphAdjList * G) {
    printf("Please enter the number of vexes and edges: ");
    scanf("%d%d", &(G->numVertexes), &(G->numEdges));
    printf("numVertex: %d, numEdges: %d\n", G->numVertexes, G->numEdges);
    while (getchar() != '\n') continue;
    
    printf("please enter %d value: ", G->numVertexes);
    for (int i = 0; i < G->numVertexes; i++) {
        scanf("%c", &(G->adjList[i].data));
    }
    
    while(getchar() != '\n') continue;
    
    for (int i = 0; i < G->numEdges; i++) {
        int x, y, weight;
        printf("Please enter the node i, j and weight: ");
        scanf("%d%d%d", &x, &y, &weight);
        EdgeNode * n1 = (EdgeNode *) malloc(sizeof(EdgeNode));
        n1->adjvex = x;
        n1->weight = weight;
        n1->next = G->adjList[y].firstEdge;
        G->adjList[y].firstEdge = n1;
        
        EdgeNode * n2 = (EdgeNode *) malloc(sizeof(EdgeNode));
        n2->adjvex = y;
        n2->weight = weight;
        n2->next = G->adjList[x].firstEdge;
        G->adjList[x].firstEdge = n2;
    }
    
    while (getchar() != '\n') continue;
}
