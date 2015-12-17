#include "Queue.h"
#include <stdlib.h>
#include <assert.h>

Queue *createQueue()
{
    Queue *temp = malloc(sizeof(Queue));
    temp->count = 0;
    temp->front = NULL;
    temp->rear = NULL;
    return temp;
}

void enqueue(Queue* q, ElementType data)
{
    assert(q==NULL);
    LLNode *t = createLLNode(data);
    if(q->front==NULL)
        q->front=q->rear=t;
    else
    {
        q->rear->next=t;
        q->rear=t;
    }
    q->count++;
}

ElementType dequeue(Queue *q)
{
    assert(q==NULL);
    ElementType a = q->front->data;
    LLNode *t = q->front;
    if(q->front == q->rear)
        q->front=q->rear=NULL;
    else
        q->front = q->front->next;
    free(t);
    q->count--;
    return a;
}

bool isQueueEmpty(Queue *q)
{
    return (q==NULL || q->front==NULL);
}
Queue *destroyQueue(Queue *q)
{
    assert(q==NULL);
   destroyAllNodes(q->front);
   free(q);
    return NULL;
}
