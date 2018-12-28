#include "graphic.h"

void CreateMGraph(MGraph *G) {
    int i, j, k, w;
    printf("enter the vertex number and edge number:");
    scanf("%d %d", &(G->numVertexes), &(G->numEdges));

    for (i = 0; i < G->numVertexes; i++) {
        while (getchar() != '\n') {
            continue;
        }
        printf("enter the value of vertex in position %d:\n", i);
        scanf("%c", &(G->vexs[i]));
    }

    for (i = 0; i < G->numVertexes; i++) {
        for (j = 0; j < G->numVertexes; j++) {
            G->arc[i][j] = INFINITY;
        }
    }

    for(k = 0; k < G->numEdges; k++) {
        printf("enter i and j for the edge and value of w:");
        scanf("%d%d%d", &i, &j, &w);

        printf("i = %d, j = %d, w = %d\n", i, j, w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}


void CreateALGraph(GraphAdjList * G) {
    int i, j, k;
    EdgeNode * e;
    printf("enter the number of vertex and edge: \n");
    scanf("%d%d", &(G->numVertexes), &(G->numEdges));

    printf("numVertexes = %d, numEdges = %d", G->numVertexes, G->numEdges);

    for (i = 0; i < G->numVertexes; i++) {
        while (getchar() != '\n') {
            continue;
        }
        printf("enter the value in position %d\n", i);
        scanf("%c", &G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }

    for (k = 0; k < G -> numEdges; k++) {
        printf("please enter the number of vertex:\n");
        scanf("%d%d",&i, &j);

        printf("i = %d, j = %d", i, j);
        e = (EdgeNode *) malloc(sizeof(EdgeNode));

        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode *) malloc(sizeof(EdgeNode));

        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }


}


void DFS(MGraph G, int i) {
    int j;
    visited[i] = true;
    printf("%c\n", G.vexs[i]);

    for(j = 0; j < G.numVertexes; j++) {
        if (G.arc[i][j] != INFINITY && !visited[j]) {
            DFS(G, j);
        }
    }
}

void DFSTraverse(MGraph G) {
    int i;
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = false;
    }

    for (i = 0; i < G.numVertexes; i++) {
        //   连桶图只调用一次
        if (!visited[i]) {
            puts("call number");
            DFS(G, i);
        }
    }
}

void DFSForAdjList(GraphAdjList G, int i) {
    int j;
    visited[i] = true;
    printf("%c\n", G.adjList[i].data);
    EdgeNode * p = G.adjList[i].firstedge;

    while(p) {
        if (!visited[p->adjvex]) {
            DFSForAdjList(G, p->adjvex);
        }
        p = p->next;
    }
}

void DFSTraverseForAdjList(GraphAdjList G) {
    int i;
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = false;
    }

    for (i = 0; i < G.numVertexes; i++) {
        if (!visited[i]) {
            DFSForAdjList(G, i);
        }
    }
}


void MiniSpanTree_Prim(MGraph G) {
    int min, i, j, k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];

    lowcost[0] = 0;
    adjvex[0] = 0;

    // 初始化

    for (int i = 1; i < G.numVertexes; i++) {
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }


    for(i = 1; i < G.numVertexes; i++) {
        min = INFINITY;

        j = 1;
        k = 0;

        while (j < G.numVertexes) {
            // 在该定点到其他定点的所有路径里面找到最短的，并记录终点和权值
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }

            j++;
        }
        // 打印找到的权值和顶点位置
        printf("(%d, %d)", adjvex[k], k);
        lowcost[k] = 0;

        for (j = 1; j < G.numVertexes; j++) {
            // 查看从k点出发有没有更短路径到其他点
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }


}




