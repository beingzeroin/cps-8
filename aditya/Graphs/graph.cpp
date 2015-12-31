#include "graph.h"
#include "llnode.h"
#include <stdlib.h>
#include <stdio.h>

Graph *createGraph(int nv)
{
    graph *newGraph = (graph*)malloc(sizeof(graph));
    newGraph->nv = nv;
    newGraph->ne = 0;
    newGraph->adjList = (LLNode**)malloc(sizeof(LLNode*));
    int i = 0;
    while(i < nv){
        newGraph->adjList[i] = NULL;
        i++;
    }
    return newGraph;
}
void insertEdge(Graph *g, int u, int v)
{
    g->adjList[u] = insertInBegin(g->adjList[u],v);
    g->adjList[v] = insertInBegin(g->adjList[v],u);
    g->ne++;
}
void deleteEdge(Graph *g, int u, int v)
{
    g->adjList[u] = deleteNodeWithValue(g->adjList[u],v);
    g->adjList[v] = deleteNodeWithValue(g->adjList[v],u);
    g->ne--;
}
Graph *destroyGraph(Graph *g)
{
    return NULL;
}

void printGraph(Graph *g)
{
    printf("Edges : %d",g->ne);
    int i = 0;
    while(i < g->nv){
        printf("%d : ",i);
        traverse(g->adjList[i]);
        printf("\n");
        i++;
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
