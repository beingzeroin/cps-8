#include <iostream>
#include <cstdio>
#include "graph.h"

using namespace std;

int main()
{
    Graph *g = createGraph(10);

    insertEdge(g, 0, 4);
    insertEdge(g, 0, 3);
    insertEdge(g, 1, 3);
    insertEdge(g, 1, 5);
    insertEdge(g, 2, 4);
    insertEdge(g, 4, 5);
    printGraph(g);
    //insertEdge(g, 6, 7);

    //printGraph(g);

    return 0;
}
