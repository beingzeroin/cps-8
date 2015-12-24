#include "Queue.h"
#include <stdlib.h>
#include <assert.h>

Queue *createQueue()
{
    Queue *q=malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    q->count=NULL;
    return q;
}

void enqueue(Queue* q, ElementType data)
{
    q->rear=insertInEnd(q->rear,data);
    q->count++;
}

ElementType dequeue(Queue *q)
{
    ElementType data=q->front->data;
    deleteFirstNode(q->front);
    q->count--;
    return data;
}

bool isQueueEmpty(Queue *q)
{
    return(q==NULL||q->front==NULL);
}
Queue *destroyQueue(Queue *q)
{
     q->front=destroyAllNodes(q->front);
    free(q);
    return NULL;
}

