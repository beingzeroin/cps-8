#include "graph.h"
#include "llnode.h"
#include <assert.h>

Graph *createGraph(int nv)
{
    Graph *g=malloc(sizeof(Graph));
    g->nv=nv;
    g->ne=0;
    g->adjList=(LLNode **)malloc(nv * sizeof(LLNode));
    int i;
    for(i=0;i<nv;i++)
        g->adjList[i]=NULL;
    return g;
}
void insertEdge(Graph *g, int u, int v)
{
    assert(g!=NULL);
    g->adjList[u]=insertInBegin(g->adjList[u],v);
    g->adjList[v]=insertInBegin(g->adjList[v],u);
    g->nv++;
}
void deleteEdge(Graph *g, int u, int v)
{
    assert(g!=NULL);
    g->adjList[u]=deleteNodeWithValue(g->adjList[u],v);
    g->adjList[v]=deleteNodeWithValue(g->adjList[v],u);
    g->nv--;
}
Graph *destroyGraph(Graph *g)
{

}

void printGraph(Graph *g)
{
    int i;
    for(i=0;i<g->nv;i++)
    {
        printf("%d :",g->adjList[])
    }
}

void dfs(Graph *g)
{

}
void bfs(Graph *g)
{

}

void printPath(Graph *g, int s, int d)
{

}
