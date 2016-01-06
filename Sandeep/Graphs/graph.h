#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "llnode.h"

typedef struct graph Graph;

struct graph
{
    int nv;
    int ne;
    LLNode** adjList;


};

Graph *createGraph(int nv);
void insertEdge(Graph *g, int u, int v);
void deleteEdge(Graph *g, int u, int v);
Graph *destroyGraph(Graph *g);

void printGraph(Graph *g);


void dfs(Graph *g);
void dfsWithStart(Graph *g, int v);

void bfs(Graph *g);
void bfs2(Graph *g, int v);

void dfs(Graph *g,int v);
void bfs(Graph *g,int v);


void printPath(Graph *g, int s, int d);

#endif // GRAPH_H_INCLUDED
