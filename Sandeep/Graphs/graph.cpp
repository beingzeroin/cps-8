#include "graph.h"
#include "llnode.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<queue>
#include<string.h>
using namespace std;


Graph *createGraph(int nv)
{
    Graph *g=(Graph *)malloc(sizeof(Graph));
    g->nv=nv;
    g->ne=0;
    g->adjList=(LLNode **)malloc(nv * sizeof(LLNode *));
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
return NULL;
}

void printGraph(Graph *g)
{
    int i;
    for(i=0;i<g->nv;i++)
    {
        printf("%d ",g->nv);
        traverse(g->adjList[i]);
        printf("\n");
    }


}
 void dfsInternal(Graph *g,int v,bool visited[])
 {
     if(visited)
        return ;
     printf("%d ",v);
     LLNode *t;
     for(t=g->adjList[v];t!=NULL;t=t->next)
     {
         dfs(g,t->data);
     }
 }                          //MEMSET -sets the first num bytes
void dfs(Graph *g,int v)
{
 queue<int> q;
 bool visited[g->nv];
 memset(visited,false,sizeof(visited));
 dfsInternal(g,v,visited);
}

void bfs(Graph *g,int v)
{
 queue<int> q;
 bool visited[g->nv];

 memset(visited,false,sizeof(visited));
 int i;
 for(i=0;i<g->nv;i++)
 {
 q.push(v);
 visited[v]=true;
 while(!q.empty())
 {
     printf("%d ",q.front());
     q.pop();

    for(i=LLNode *t;i<)
 }
 }





}
int pathBetweenNodes[500];
bool visited[100];
int idx;

void printPath(Graph *g, int s, int d)
{


    if(s==d)
    {
        for()
    }



        LLNode *t;
    for(t=adjList[s];t!=NULL;t=t->next)
    {
        printPath(g,t->data,d);
    }
    idx--;

}
