#include "graph.h"
#include "llnode.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>


Graph *createGraph(int nv)
{
    int i;
    Graph *g=(graph*)malloc(sizeof(graph));
     g->adjList=(LLNode**)malloc(nv*sizeof(LLNode*));
     g->ne=0;
     g->nv=nv;
     for(i=0;i<nv;i++)
        g->adjList[i]=NULL;
     return g;
}
void insertEdge(Graph *g, int u, int v)
{
    assert(g!=NULL);
g->adjList[u]=insertInBegin(g->adjList[u],v);
g->adjList[v]=insertInBegin(g->adjList[v],u);
g->ne++;

}
void deleteEdge(Graph *g, int u, int v)
{
    assert(g!=NULL);
g->adjList[u]=deleteNodeWithValue(g->adjList[u],v);
g->adjList[v]=deleteNodeWithValue(g->adjList[v],u);
g->ne--;
}
Graph *destroyGraph(Graph *g)
{

}
void printGraph(Graph *g)
{
    int i;
    for(i=0;i<g->nv;i++)
    {
        printf("%d :",i);
        traverse(g->adjList[i]);
        printf("\n");

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
