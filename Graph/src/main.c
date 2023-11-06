#include <stdio.h>
#include "graph.h"

#define INFINITY 9999


int main()
{   
    struct graph *myGraph = createGraph((ROWS + EDGEROWS) * (COLS / 2));

    addEdges(myGraph);

    displayGraph(myGraph);

    printf("\n");
    return 0;
}