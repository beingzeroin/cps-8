#include "Queue.h"
#include <stdlib.h>
#include <assert.h>

Queue *createQueue()
{
    //assert(false);
    Queue *q=malloc(sizeof(Queue));
    q->front=NULL;
        q->rear=NULL;
        q->count=0;
    return q;
}

void enqueue(Queue* q, ElementType data)
{
    assert(q!=NULL);
    q->rear=insertInEnd(q->rear,data);
    if(q->front==NULL)
        q->front=q->rear;
        q->count++;
}

ElementType dequeue(Queue *q)
{
    assert(q!=NULL);
    assert(q->front!=NULL||q->rear!=NULL);
    ElementType a=q->rear->data;
    q->rear=deleteFirstNode(q->rear);
    q->count--;
    return a;
}

bool isQueueEmpty(Queue *q)
{
   // assert(false);
    return ((q==NULL)||(q->rear==NULL));
}
Queue *destroyQueue(Queue *q)
{
   assert(q!=NULL);
   q->rear=destroyAllNodes(q->rear);
   free(q);
    return NULL;
}
