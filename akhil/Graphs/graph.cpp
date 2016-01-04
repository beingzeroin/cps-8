#include "graph.h"
#include "llnode.h"
#include<stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <queue>
using namespace std;

Graph *createGraph(int nv)
{
  Graph *g =(Graph *)malloc(sizeof(Graph));

   g->nv= nv;
   g->ne =0;
   g->adjList= (LLNode **)malloc(nv * sizeof(LLNode *));
   int i;
   for(i=0;i<nv;i++)
        g->adjList[i] = NULL;

    return g;
}
void insertEdge(Graph *g, int u, int v)
{
    assert(g!=NULL);

    g->adjList[u]= insertInBegin(g->adjList[u],v);
    g->adjList[v]= insertInBegin(g->adjList[v],u);
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

}

void printGraph(Graph *g)
{

 int i;
 for(i=0;i<g->nv;i++)
 {
  printf(" %d",i);
  traverse(g->adjList[i]);
  printf("\n");
 }

}


void dfsInternal(Graph *g,int v ,bool visited[])
{
    if(visited[v])
        return;

     printf("%d",v);
     visited[v] = true;

     LLNode *t;

     for(t=g->adjList[v];t1=NULL;t=t->next)
     {
         dfsInternal(g,t->data);
     }

}

void dfsWithStart(Graph *g,int v)
{
     bool visited[g->nv];
    memset(visited,false,sizeof(visited));
    dfsInternal(g,v,visited);

}
  queue<int> q;

    bool visited[1000];
void bfs(Graph *g)
{
    queue<int> q;

    bool visited[g->nv];
    memset(visited,false,sizeof(visited));
    int i;
    for(i=0;i<g->nv;i++)
    {

    if(visited[i]==false)

    q.push(v);
    visited[v]=true;

    while(!q.empty)
    {
       int p=q.front();
        q.pop();
        printf(" %d",p);
        for(LLNode *t =g->adjList[v];t!=NULL;t=t->next )
        {
            if(!visited[t->data])
            {
                q.push(t->data);
                visited[t->data] = false;
            }
        }


    }
    }


}

int pathBetweenNodes[500];
bool visited[100] = false;
int pathIdx;
void printPath(Graph *g, int s, int d)
{
    if(s==d)
   if(visited[s])
    return;
    for(i=0;i<pathIdx;i++)
    {
        if(pathIdx=0)
        {
            printf("%d",s);
        }
        else
        {
            printf("->%d",pathBetweenNodes[i])
        }
    }

    pathBetweenNodes[0]=s;






   LLNode *t;
   for(t->adjList[s];t!=NULL;t=t->next)
   {
       pathBetweenNodes(t,t->data,d);

   }
   pathIdx--;


}
