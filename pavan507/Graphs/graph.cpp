#include "graph.h"
#include "llnode.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>

using namespace std;

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
void dfsInternal(Graph *g,int v,bool visited[])
{
    if(visited[v]==true)
        return;
    printf("%d ",v);
    visited[v]=true;
    for(LLNode *t=g->adjList[v];t!=NULL;t=t->next)
        dfsInternal(g,t->data,visited);

}
void dfs(Graph *g)
{
      bool visited[g->nv];
      memset(visited,false,sizeof(visited));
      for(int i=0;i<g->nv;i++)
      dfsInternal(g,i,visited);
}
void bfs(Graph *g)
{
    int v;
    queue<int>myqueue;
    bool visited[g->nv];
     memset(visited,false,sizeof(visited));
     int i;
     for(i=0;i<g->nv;i++)
     {
        if(visited[i]==false)
    myqueue.push(i);
    visited[i]=true;
    while(!myqueue.empty())
    {
        v=myqueue.front();
        myqueue.pop();
        printf("%d ",v);
        while(g->adjList[v]!=NULL)
        {
            if(visited[g->adjList[v]->data]==false)
            {

                myqueue.push(g->adjList[v]->data);
                visited[g->adjList[v]->data]=true;
            }
            g->adjList[v]=g->adjList[v]->next;

        }

    }

     }
}
int pathBetweenNodes[100];
bool visited[100];
int pathIdx;
void printPath(Graph *g, int s, int d)
{
    if(visited[s])
        return;
    if(s==d)
    {
        int i;
        for(i=0;i<pathIdx;i++)
        {

            if(i==0)
                printf("%d",pathBetweenNodes[i]);
            else
                printf("->%d",pathBetweenNodes[i]);
        }
        printf("->%d",d);
        printf("\n");
    }
pathBetweenNodes[pathIdx]=s;
pathIdx++;
visited[s]=true;
LLNode* t;
for(t=g->adjList[s];t!=NULL;t=t->next)
{
  //  if(!visited[t->data])
    printPath(g,t->data,d);
}
pathIdx--;
visited[s]=false;

}
