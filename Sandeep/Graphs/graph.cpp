#include "graph.h"
#include "llnode.h"
<<<<<<< HEAD
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <stdbool.h>

=======
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<queue>
#include<string.h>
>>>>>>> 59f32ad7baaafa31e6e69aef0e2f32642bc10e86
using namespace std;


Graph *createGraph(int nv)
{
<<<<<<< HEAD
    Graph * g = (Graph *)malloc(sizeof(Graph));
    g->nv = nv;
    g->ne = 0;
    g->adjList = (LLNode **)malloc(nv * sizeof(LLNode *));
    int i;
    for(i=0; i<nv; i++)
        g->adjList[i] = NULL;
    return g;
}
void insertEdge(Graph *g, int u, int v)
{
    assert(g!=NULL);

    g->adjList[u] = insertInBegin(g->adjList[u], v);
    g->adjList[v] = insertInBegin(g->adjList[v], u);
=======
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
>>>>>>> 59f32ad7baaafa31e6e69aef0e2f32642bc10e86
    g->ne++;
}
void deleteEdge(Graph *g, int u, int v)
{
    assert(g!=NULL);
<<<<<<< HEAD
    g->adjList[u] = deleteNodeWithValue(g->adjList[u], v);
    g->adjList[v] = deleteNodeWithValue(g->adjList[v], u);
=======
    g->adjList[u]=deleteNodeWithValue(g->adjList[u],v);
    g->adjList[v]=deleteNodeWithValue(g->adjList[v],u);
>>>>>>> 59f32ad7baaafa31e6e69aef0e2f32642bc10e86
    g->ne--;
}
Graph *destroyGraph(Graph *g)
{
return NULL;
}

void printGraph(Graph *g)
{
    int i;
<<<<<<< HEAD
    for(i=0; i<g->nv; i++)
    {
        printf("%d : ", i);
        traverse(g->adjList[i]);
        printf("\n");
    }
}

void dfsInternal(Graph *g, int v, bool visited[])
{
    if(visited[v])
        return;

    printf("%d ", v);
    visited[v] = true;
    LLNode *t;
    for(t=g->adjList[v];t!=NULL;t=t->next)
    {
        dfsInternal(g, t->data, visited);
    }
}

void dfsWithStart(Graph *g, int v)
{
    bool visited[g->nv];
    memset(visited, false, sizeof(visited));

    dfsInternal(g, v, visited);
}
=======
    for(i=0;i<g->nv;i++)
    {
        printf("%d ",g->nv);
        traverse(g->adjList[i]);
        printf("\n");
    }

>>>>>>> 59f32ad7baaafa31e6e69aef0e2f32642bc10e86

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
<<<<<<< HEAD
    bool visited[g->nv];
    memset(visited, false, sizeof(visited));

    for(int v = 0 ;v<g->nv;v++)
    {
        dfsInternal(g, v, visited);
    }
}

queue<int> q;
bool visited[1000];

void bfs2(Graph *g, int v)
{
    if(visited[v])
        return ;
=======
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




>>>>>>> 59f32ad7baaafa31e6e69aef0e2f32642bc10e86

    q.push(v);
    visited[v] = true;
    if(!q.empty())
    {
        int tmp = q.front();
        q.pop();

        printf("%d ", tmp);

        for(LLNode *t=g->adjList[v]; t!=NULL; t=t->next)
        {
            bfs2(g, t->data);
        }
    }
}
<<<<<<< HEAD
int pathBetweenNodes[500];
bool visited[100];
int idx;
=======
void bfs(Graph *g)
{
    queue<int> q;

    bool visited[g->nv];

    // Shorthand way
    memset(visited, false, sizeof(visited));

    int i;
    for(i=0; i<g->nv; i++)
    {
        if(visited[i]==false)
        {
            q.push(i);
            visited[i] =  true;

            while(!q.empty())
            {
                printf("%d ", q.front());
                q.pop();
>>>>>>> 6fd26ef8bca61539cf09865443377c3796d0b50a

                for(LLNode *t=g->adjList[i]; t!=NULL; t=t->next)
                {
                    if(!visited[t->data])
                    {
                        q.push(t->data);
                        visited[t->data] = true;
                    }
                }
            }
        }
    }
}
int pathBetweenNodes[2000];
int pathIdx=0;
void printPath(Graph *g, int s, int d)
{
    if(visited[s])
        return;

    if(s==d)
    {
        int i;
        printf("\n");
        for(i=0;i<pathIdx;i++)
        {
            if(i==0)
                printf("%d", pathBetweenNodes[i]);
            else
                printf("->%d", pathBetweenNodes[i]);

<<<<<<< HEAD

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

=======
        }
        printf("->%d", d);
        return;

    }

    pathBetweenNodes[pathIdx] = s;
    pathIdx++;
    visited[s] = true;

    LLNode *t;
    for(t=g->adjList[s];t!=NULL;t=t->next)
    {
        printPath(g, t->data, d);
    }
    pathIdx--;
    visited[s] = false;
>>>>>>> 6fd26ef8bca61539cf09865443377c3796d0b50a
}
