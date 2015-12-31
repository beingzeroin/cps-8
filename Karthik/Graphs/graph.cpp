#include "graph.h"
#include "llnode.h"
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

Graph *createGraph(int nv)
{
    Graph *g=(Graph *)malloc(sizeof(Graph));
    g->nv=nv;
    g->ne=0;
    g->adjList=(LLNode **)malloc(nv*sizeof(LLNode *));
    int i;
    for(i=0;i<nv;i++)
        g->adjList[i]=NULL;
    return g;
}
void insertEdge(Graph *g, int u, int v)
{
    g->adjList[u]=insertInBegin(g->adjList[u],v);
    g->adjList[v]=insertInBegin(g->adjList[v],u);
    g->ne++;
}
void deleteEdge(Graph *g, int u, int v)
{
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
        printf("%d : ",i);
        traverse(g->adjList[i]);
        printf("\n");
    }
}

void dfsInternal(Graph *g,int v,bool visited[])
{
    if(visited[v])
        return;
    printf("%d ",v);
    visited[v]=true;
    LLNode *t;
    for(t=g->adjList[v];t!=NULL;t=t->next)
        dfsInternal(g,t->data,visited);
}
void dfs(Graph *g,int v)
{
    bool visited[g->nv];
    memset(visited,false,sizeof(visited));

    dfsInternal(g,v,visited);
}
void bfs(Graph *g,int v)
{
    bool visited[g->nv];
    memset(visited,false,sizeof(visited));
    //int i=0;
    queue<int> myQ;
    myQ.push(v);
    visited[v]=true;
    printf("\n");
    while(!myQ.empty())
    {
        //for(i=0;i<myQ.size();i++)
        //{
            int temp=myQ.front();
            LLNode *tempNode=g->adjList[temp];
            printf("%d ",temp);
            myQ.pop();
            //tempNode=tempNode->next;
           while(tempNode!=NULL)
            {
                if(visited[tempNode->data]==false)
                {
                    myQ.push(tempNode->data);
                    visited[temp]=true;
                }
                tempNode=tempNode->next;
            }
        //}
    }
}

void printPath(Graph *g, int s, int d)
{

}
