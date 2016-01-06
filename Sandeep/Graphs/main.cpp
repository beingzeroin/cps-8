#include <iostream>
#include <cstdio>
#include "graph.h"

using namespace std;

int main()
{
    Graph *g = createGraph(5);

    insertEdge(g, 0, 1);
    insertEdge(g, 2, 1);
    insertEdge(g, 1, 3);
    insertEdge(g, 3, 4);
    //insertEdge(g, 2, 4);
    //insertEdge(g, 4, 5);
    //insertEdge(g, 6, 7);

    printGraph(g);

    printf("BFS: ");
    bfs(g);
    printf("\nDFS: ");
    dfs(g);

    dfs(g,0);
        printGraph(g);


    printPath(g, 0, 5);
    // 0->4->5
    // 0->3->1->5
    return 0;
}
