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
#include "Queue.h"

bool visited[MAXVEX];
int * etv, *ltv;
int * stack2;
int top2;

int Find(int * parent, int f) {
    while (parent[f] > 0)
        f = parent[f];
    return f;
}
void createMGraph(MGraph * G) {
    printf("Please enter the number of vectex and edge: ");
    scanf("%d %d", &(G->numVectexes), &(G->numEdges));
    printf("numVectexes: %d, numEdges: %d\n", G->numVectexes, G->numEdges);
    
    while(getchar() != '\n') continue;
    
    printf("Please enter %d for each node: ", G->numVectexes);
    for(int i = 0; i < G->numVectexes; i++) {
        scanf("%d", &(G->vexs[i]));
    }
    
    while(getchar() != '\n') continue;
    
    for (int i = 0; i < G->numVectexes; i++) {
        for (int j = 0; j < G->numVectexes; j++) {
            G->arc[i][j] = INFINITY;
        }
    }
    
    printf("Please enter the x, y and value for %d times: ", G->numEdges);
    for (int i = 0; i < G->numEdges; i++) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        G->arc[x][y] = v;
        G->arc[y][x] = v;
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
        scanf("%d", &(G->adjList[i].data));
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

void MDfs(MGraph G, int i) {
    visited[i] = true;
    printf("%d\n", G.vexs[i]);
    for (int j = 0; j < G.numVectexes; j++) {
        if (G.arc[i][j] != INFINITY && !visited[j]) MDfs(G, j);
    }
}

void M_DFS_TRAVERSE(MGraph G) {
    for (int i = 0; i < G.numVectexes; i++) {
        visited[i] = false;
    }
    
    for (int i = 0; i < G.numVectexes; i++) {
        if (!visited[i]) MDfs(G, i);
    }
}

void MDFS2(MGraph G, int i) {
    visited[i] = true;
    printf("%d\n", G.vexs[i]);
    for (int j = 0; j < G.numVectexes; j++) {
        if (G.arc[i][j] < INFINITY && !visited[j]) MDFS2(G, j);
    }
}

void M_DFS_TRAVERSE2(MGraph G) {
    int len = G.numVectexes;
    for (int i = 0; i < len; i++) {
        visited[i] = false;
    }
    
    for (int i = 0; i < len; i++) {
        if (!visited[i]) MDFS2(G, i);
    }
}

void AdjDfs(GraphAdjList G, int i) {
    visited[i] = true;
    VertexNode node = G.adjList[i];
    printf("%d\n", node.data);
    EdgeNode * edge = node.firstEdge;
    while (edge) {
        if (!visited[edge->adjvex]) AdjDfs(G, edge->adjvex);
        edge = edge->next;
    }
}

void ADJ_DFS_TRAVERSE(GraphAdjList G) {
    for (int i = 0; i < G.numVertexes; i++) {
        visited[i] = false;
    }
    
    for (int i = 0; i < G.numVertexes; i++) {
        if (!visited[i]) AdjDfs(G, i);
    }
}

void M_BFS_TRAVERSE(MGraph G) {
    for (int i = 0; i < G.numVectexes; i++) {
        visited[i] = false;
    }
    
    Queue Q;
    initQueue(&Q);
    
    for (int i = 0; i < G.numVectexes; i++) {
        if (!visited[i]) {
            EnQueue(&Q, i);
            while (!QueueEmpty(&Q)) {
                int index;
                DeQueue(&Q, &index);
                visited[index] = true;
                printf("%d\n", G.vexs[index]);
                for (int j = 0; j < G.numVectexes; j++) {
                    if (G.arc[index][j] != INFINITY && !visited[j]) {
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}

void M_BFS_TRAVERSE2(MGraph G) {
    Queue q;
    initQueue(&q);
    for (int i = 0; i < G.numVectexes; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.numVectexes; i++) {
        if (!visited[i]) {
            visited[i] = true;
            printf("%d\n", G.vexs[i]);
            EnQueue(&q, i);
            while (!QueueEmpty(&q)) {
                int t;
                DeQueue(&q, &t);
                for (int j = 0; j < G.numVectexes; j++) {
                    if (G.arc[t][j] < INFINITY && !visited[j]) {
                        printf("%d\n", G.vexs[j]);
                        visited[j] = true;
                        EnQueue(&q, j);
                    }
                }
            }
        }
    }
    
}

void ADJ_BFS_TRAVERSE(GraphAdjList G) {
    for (int i = 0; i < G.numVertexes; i++) {
        visited[i] = false;
    }
    
    Queue Q;
    initQueue(&Q);
    
    for (int i = 0; i < G.numVertexes; i++) {
        if (!visited[i]) {
            visited[i] = true;
            EnQueue(&Q, i);
            while (!QueueEmpty(&Q)) {
                int index;
                DeQueue(&Q, &index);
                VertexNode node = G.adjList[index];
                printf("%d\n", node.data);
                EdgeNode * temp = node.firstEdge;
                while (temp) {
                    if (!visited[temp->adjvex]) {
                        EnQueue(&Q, temp->adjvex);
                        visited[temp->adjvex] = true;
                    };
                    temp = temp->next;
                }
            }
        }
    }
}

void MiniSpanTree_Prim(MGraph G) {
    int min, i, j, k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];
    
    lowcost[0] = 0;
    adjvex[0] = 0;
    
    for (i = 1; i < G.numVectexes; i++) {
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }
    
    for (i = 1; i < G.numVectexes; i++) {
        min = INFINITY;
        j = 1;
        k = 0;
        
        while (j < G.numVectexes) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                k = j;
                min = lowcost[j];
            }
            j++;
        }
        // k is destination of the short edge
        // means the first edge
        printf("(%d, %d)", adjvex[k], k);
        // k is the node in the shortest tree
        lowcost[k] = 0;
        for(j = 1; j < G.numVectexes; j++) {
            // the weight from k to the node which is not included
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}

void MiniSpanTree_Prim2(MGraph G) {
    int lowcast[MAXVEX];
    // the start of current low cast path;
    int vextex[MAXVEX];
    int all = 0;
    
    vextex[0] = 0;
    lowcast[0] = 0;
    for (int i = 1; i < G.numVectexes; i++) {
        vextex[i] = 0;
        lowcast[i] = G.arc[0][i];
    }
    // remain G.numVectexes - 1 point
    for (int i = 0; i < G.numVectexes - 1; i++) {
        int min = INFINITY;
        int k = 0;
        int j = 1;
        // find the low cast in lowcast arr
        while (j < G.numVectexes) {
            if (lowcast[j] != 0 && lowcast[j] < min) {
                min = lowcast[j];
                k = j;
            }
            j++;
        }
        all += min;
        printf("(%d, %d)\n", vextex[k], k);
        // add the low path node
        lowcast[k] = 0;
        // update low cast
        for (int j = 1; j < G.numVectexes; j++) {
            // find the lower cast path to the same node from k, update lowcast and vextex
            if (lowcast[j] != 0 && G.arc[k][j] < lowcast[j]) {
                lowcast[j] = G.arc[k][j];
                vextex[j] = k;
            }
        }
        
    }
    
    printf("all sum is %d\n", all);
}

void MiniSpanTree_Prim3(MGraph G) {
    int len = G.numVectexes;
    int adjvex[len];
    int lowcost[len];
    adjvex[0] = 0;
    lowcost[0] = 0;
    int sum = 0;
    
    for (int i = 1; i < len; i++) {
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }
    
    for (int i = 1; i < len; i++) {
        int min = INFINITY,
            j = 1,
            k = 0;
        
        while (j < len) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        
        printf("from %d to %d\n", adjvex[k], k);
        sum += G.arc[adjvex[k]][k];
        lowcost[k] = 0;
        for (j = 1; j < len; j++) {
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
    
    printf("sum = %d\n", sum);
    
    
}


void MiniSpanTree_Kruskal(MGraph G) {
    int i, n, m;
    
    Edge edges[MAXVEX];
    int parent[MAXVEX];
    printf("please enter the edge arr: ");
    for (i = 0; i < G.numEdges; i++) {
        int begin, end, weight;
        scanf("%d%d%d", &begin, &end, &weight);
        edges[i].begin = begin;
        edges[i].end = end;
        edges[i].weight = weight;
    }
    
    for (int i = 0; i < G.numVectexes; i++) {
        parent[i] = 0;
    }
    
    for (int i = 0; i < G.numEdges; i++) {
        Edge edge = edges[i];
        n = Find(parent, edge.begin);
        m = Find(parent, edge.end);
        
        if (m != n) {
            parent[n] = m;
            printf("(%d, %d) weight: %d\n", edge.begin, edge.end, edge.weight);
        }
    }
}

void ShortestPath_Dijkstra(MGraph G, int v0, Patharc * P, ShortPathTable * D) {
    int v, w, k, min;
    int final[MAXVEX];
    for (v = 0; v < G.numVectexes; v++) {
        final[v] = 0;
        (*D)[v] = G.arc[v0][v];
        (*P)[v] = 0;
    }
    
    (*D)[v0] = 0;
    final[v0] = 1; // v0 to v0 is not need to calculate
    
    for (v = 1; v < G.numVectexes; v++) {
        min = INFINITY;
        k = 0;
        for (w = 0; w < G.numVectexes; w++) {
            if (!final[w] && (*D)[w] < min) {
                k = w;
                min = (*D)[w];
            }
        }
        
        final[k] = 1;
        for (w = 0; w < G.numVectexes; w++) {
            if (!final[w] && (min + G.arc[k][w]) < (*D)[w]) {
                (*D)[w] = min + G.arc[k][w];
                (*P)[w] = k;
            }
        }
    }
}


void ShortestPath_Dijkstra2(MGraph G, int index, Patharc P, ShortPathTable D) {
    bool final[MAXVEX];
    for (int i = 0; i < G.numVectexes; i++) {
        P[i] = index;
        D[i] = G.arc[index][i];
        final[i] = false;
    }
    // to index node self
    D[index] = 0;
    final[index] = true;
    
    for (int i = 0; i < G.numVectexes; i++) {
        int min = INFINITY, k = 0;
        for (int j = 0; j < G.numVectexes; j++) {
            if (!final[j] && D[j] < min) {
                min = D[j];
                k = j;
            }
        }
        
        final[k] = true;
        
        for (int w = 0; w < G.numVectexes; w++) {
            if (!final[w] && (min + G.arc[k][w]) < D[w]) {
                D[w] = min + G.arc[k][w];
                P[w] = k;
            }
        }
        
    }
    
}

void ShortestPath_Dijkstra3(MGraph G, int v, int * D, int * P) {
    int len = G.numVectexes;
    int final[len];
    for (int i = 0; i < len; i++) {
        final[i] = 0;
        D[i] = G.arc[v][i];
        P[i] = 0;
    }
    
    final[v] = 1;
    D[v] = 0;
    
    for (int j = 1; j < len; j++) {
        int min = INFINITY, k = v;
        
        for (int x = 0; x < len; x++) {
            if (final[x] != 1 && D[x] < min) {
                min = D[x];
                k = x;
            }
        }
        
        final[k] = 1;
        
        for (int x = 0; x < len; x++) {
            if (final[x] != 1 && min + G.arc[k][x] < D[x]) {
                D[x] = min + G.arc[k][x];
                P[x] = k;
            }
        }
        
    }
}


void createAlGraphWithD(GraphAdjList * G) {
    printf("Please enter the number of vexes and edges: ");
    scanf("%d%d", &(G->numVertexes), &(G->numEdges));
    printf("numVertex: %d, numEdges: %d\n", G->numVertexes, G->numEdges);
    while (getchar() != '\n') continue;
    
    printf("please enter %d value: ", G->numVertexes);
    for (int i = 0; i < G->numVertexes; i++) {
        scanf("%d", &(G->adjList[i].data));
        G->adjList[i].firstEdge = NULL;
        G->adjList[i].ind = 0;
    }
    
    while(getchar() != '\n') continue;
    printf("Please enter the node i, j and weight for %d times: ", G->numEdges);
    for (int i = 0; i < G->numEdges; i++) {
        int x, y, weight;
        scanf("%d%d%d", &x, &y, &weight);
        
        EdgeNode * n2 = (EdgeNode *) malloc(sizeof(EdgeNode));
        n2->adjvex = y;
        n2->weight = weight;
        n2->next = G->adjList[x].firstEdge;
        G->adjList[x].firstEdge = n2;
        G->adjList[y].ind += 1;
    }
    
    while (getchar() != '\n') continue;
}


bool ToplogicalSort(GraphAdjList * G) {
    EdgeNode * e;
    int i, k, gettop;
    int top = 0;
    int count = 0;
    int * stack;
    stack = (int *) malloc(sizeof(int) * G->numVertexes);
    // collect initial ind = 0
    for (i = 0; i < G->numVertexes; i++) {
        if (G->adjList[i].ind == 0) {
            stack[++top] = i;
        }
    }
    
    while(top != 0) {
        gettop = stack[top--];
        printf("%d ->", G->adjList[gettop].data);
        count++;
        for (e = G->adjList[gettop].firstEdge; e; e = e->next) {
            k = e->adjvex;
            if (!(--G->adjList[k].ind)) {
                stack[++top] = k;
            }
        }
    }
    
    if (count < G->numVertexes) {
        return false;
    }
    
    return true;
}

bool ToplogicalSort2(GraphAdjList * G) {
    EdgeNode * e;
    int i, k, gettop;
    int top = 0;
    int count = 0;
    int *stack;
    stack = (int *) malloc(G->numVertexes * sizeof(int));
    for (i = 0; i < G->numVertexes; i++) {
        if (0 == G->adjList[i].ind) {
            stack[++top] = i;
        }
    }
    
    top2 = 0;
    etv = (int *) malloc(G->numVertexes * sizeof(int));
    for (i = 0; i < G->numVertexes; i++) {
        etv[i] = 0;
    }
    
    stack2 = (int *) malloc(G->numVertexes * sizeof(int));
    while(top != 0) {
        gettop = stack[top--];
        count++;
        
        stack2[++top2] = gettop;
        
        for (e = G->adjList[gettop].firstEdge; e; e = e->next) {
            k = e->adjvex;
            if (!(--G->adjList[k].ind)) {
                stack[++top] = k;
            }
            
            if (etv[gettop] + e->weight > etv[k]) {
                etv[k] = etv[gettop] + e->weight;
            }
        }
    }
    
    if (count < G->numVertexes) return false;
    
    return true;
}


void CriticalPath(GraphAdjList * G) {
    EdgeNode * e;
    int i, gettop, k, j;
    int ete, lte;
    ToplogicalSort2(G);
    ltv = (int *) malloc(G->numVertexes * sizeof(int));
    // initial later time for event
    for (i = 0; i < G->numVertexes; i++) {
        ltv[i] = etv[G->numVertexes - 1];
    }
    
    while(top2 != 0) {
        gettop = stack2[top2--];
        for (e = G->adjList[gettop].firstEdge; e; e = e->next) {
            k = e->adjvex;
            if (ltv[k] - e->weight < ltv[gettop]) {
                ltv[gettop] = ltv[k] - e->weight;
            }
        }
    }
    
    for (j = 0; j < G->numVertexes; j++) {
        for (e = G->adjList[j].firstEdge; e; e = e->next) {
            k = e->adjvex;
            ete = etv[j];
            lte = ltv[k] - e->weight;
            if (ete == lte) {
                printf("<%d, %d> length: %d\n", j, k, e->weight);
            }
        }
    }
    
    
}


void ADJ_DFS_HELPER(GraphAdjList G, int i) {
    VertexNode node = G.adjList[i];
    printf("%d\n", node.data);
    visited[i] = true;
    EdgeNode * edge = node.firstEdge;
    while (edge != NULL) {
        if (!visited[edge->adjvex]) {
            ADJ_DFS_HELPER(G, edge->adjvex);
        }
        edge = edge->next;
    }
}


void ADJ_DFS_TRAVERSE2(GraphAdjList G) {
    printf("\n\n");
    int len = G.numVertexes;
    for (int i = 0; i < len; i++) {
        visited[i] = false;
    }
    
    for (int i = 0; i < len; i++) {
        if (!visited[i]) {
            ADJ_DFS_HELPER(G, i);
        }
    }
}

void ADJ_BFS_TRAVERSE2(GraphAdjList G) {
    printf("\n\n");
    int len = G.numVertexes;
    for (int i = 0; i < len; i++) {
        visited[i] = false;
    }
    
    for (int i = 0; i < len; i++) {
        if (!visited[i]) {
            VertexNode node = G.adjList[i];
            printf("%d\n", node.data);
            visited[i] = true;
            EdgeNode * edge = node.firstEdge;
            while (edge) {
                if (!visited[edge->adjvex]) {
                    printf("%d\n", G.adjList[edge->adjvex].data);
                    visited[edge->adjvex] = true;
                }
                edge = edge->next;
            }
        }
    }
}

bool Toplogical_Sort3(GraphAdjList G) {
    int len = G.numVertexes,
        count = 0;
    Queue q;
    initQueue(&q);
    
    for (int i = 0; i < len; i++) {
        if (G.adjList[i].ind == 0) {
            EnQueue(&q, i);
        }
    }
    
    while (!QueueEmpty(&q)) {
        int index;
        EdgeNode * e;
        DeQueue(&q, &index);
        VertexNode node = G.adjList[index];
        count++;
//        printf("%d\n", node.data);
        for (e = node.firstEdge; e != NULL; e = e->next) {
            if ((--G.adjList[e->adjvex].ind) == 0) {
                EnQueue(&q, e->adjvex);
            }
        }
    }
    
    return count == len;
}





