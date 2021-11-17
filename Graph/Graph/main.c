//
//  main.c
//  Graph
//
//  Created by Tom Xing on 12/28/18.
//  Copyright © 2018 Tom Xing. All rights reserved.
//

#include "Graph.h"

int main(int argc, const char * argv[]) {
//    MGraph G;
//    createMGraph(&G);
//    int P[9];
//    int D[9];
//    ShortestPath_Dijkstra3(G, 0, D, P);
//    for (int i = 0; i < 9; i++) {
//        printf("path: %d, distance: %d\n", P[i], D[i]);
//    }
//    MiniSpanTree_Prim3(G);
//    M_BFS_TRAVERSE2(G);
//    MiniSpanTree_Prim2(G);
//    MiniSpanTree_Kruskal(G);
//    Patharc P;
//    ShortPathTable D;
//    ShortestPath_Dijkstra(G, 0, &P, &D);
//    ShortestPath_Dijkstra2(G, 0, P, D);
//    M_BFS_TRAVERSE(G);
//    M_DFS_TRAVERSE(G);
    GraphAdjList G;
    createAlGraphWithD(&G);
//    ADJ_DFS_TRAVERSE(G);
//    ADJ_DFS_TRAVERSE2(G);
//    ToplogicalSort(&G);
//    ADJ_DFS_TRAVERSE(G);
//    ADJ_BFS_TRAVERSE(G);
//    ADJ_BFS_TRAVERSE2(G);
    bool n = Toplogical_Sort3(G);
    printf("%d\n", n);
    
    /*
    
    Queue Q;
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    
    while (!QueueEmpty(&Q)) {
        QueueType i;
        DeQueue(&Q, &i);
        printf("i = %d\n", i);
    }
    
    EnQueue(&Q, 5);
    EnQueue(&Q, 6);
    
    while(!QueueEmpty(&Q)) {
        QueueType i;
        DeQueue(&Q, &i);
        printf("i = %d\n", i);
    }
     */
    
    // key path
    // 0 1 2 3 4 5 6 7 8 9
    // 0 2 4
    //0 1 3 0 2 4 1 3 5 1 4 6 2 3 8 2 5 7 3 4 3 4 6 9 4 7 4 5 7 6 6 9 2 7 8 5 8 9 3
    
//    GraphAdjList G;
//    createAlGraphWithD(&G);
//    CriticalPath(&G);
    return 0;
}
