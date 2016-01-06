#include <iostream>
#include "graph.h"
#include "llnode.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

Graph *createGraph(int nv)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->nv = nv;
    g->ne = 0;
    g->adjList = (LLNode **)malloc(nv * sizeof(LLNode *));
    for(int i = 0; i<nv; i++)
        g->adjList[i]=NULL;
    return g;

}
void insertEdge(Graph *g, int u, int v)
{
    assert(g!=NULL);
    g->adjList[u] = insertInBegin(g->adjList[u], v);
    g->adjList[v] = insertInBegin(g->adjList[v], u);
    g->ne++;
}
void deleteEdge(Graph *g, int u, int v)
{
    assert(g!=NULL);
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
    int i;
    for(i=0; i<g->nv; i++)
    {
        printf("%d : ",i);
        traverse(g->adjList[i]);
        printf("\n");
    }
}
void dfsInternal(Graph *g, int v, bool visited[])
{
    if(visited[v])
        return;

    cout<<v<<" ";
    visited[v]=true;
    LLNode *t;
    for(t=g->adjList[v];t!=NULL;t=t->next)
    {
        dfs(g,t->data);
    }
}
void dfs(Graph *g, int v)
{
    bool visited[g->nv];
    //Short hand way
    memset(visited, false, sizeof(visited));
    dfsInternal(g, v, visited);
}

void bfs(Graph *g)
{
    if(g==NULL)
        return;
    queue<int> q;
    bool visited[g->nv];
    //Short hand way
    memset(visited, false, sizeof(visited));

    for(int i=0; i<g->nv; i++)
    {
        if(visited[i]==false)
        {
            q.push(i);
            visited[i]= true;

            while(!q.empty())
            {
                cout<<q.front()<<" ";
                q.pop();

                while(g->adjList[i]!=NULL)
                {
                    if(!visited[g->adjList[i]->data])
                        q.push(g->adjList[i]->data);
                    visited[g->adjList[i]->data]=true;
                    g->adjList[i] = g->adjList[i]->next;
                }
            }
        }
    }
}

void printPath(Graph *g, int s, int d)
{

}
