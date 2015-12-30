#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct graph Graph;

struct graph
{
    int nv;
    int ne;
    LinkedListNode** adjList;
};

Graph *createGraph(int nv);
void insertEdge(Graph *g, int u, int v);
void deleteEdge(Graph *g, int u, int v);
Graph *destroyGraph(Graph *g);

void printGraph(Graph *g);

void dfs(Graph *g);
void bfs(Graph *g);

void printPath(Graph *g, int s, int d);

#endif // GRAPH_H_INCLUDED
