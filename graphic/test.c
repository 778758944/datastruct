#include "graphic.h"


int main(void) {
    /*
    MGraph G;
    CreateMGraph(&G);
    DFSTraverse(G);
    */
   GraphAdjList G;
   CreateALGraph(&G);
   DFSTraverseForAdjList(G);
    return 0;
}