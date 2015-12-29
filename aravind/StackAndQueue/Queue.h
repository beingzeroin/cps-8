#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "LLNode.h"
#include <stdbool.h>

typedef struct queue Queue;
struct queue
{
    LLNode *front, *rear;
    int count;
};

Queue *createQueue();
void enqueue(Queue* q, ElementType data);
ElementType dequeue(Queue *q);
bool isQueueEmpty(Queue *q);
Queue *destroyQueue(Queue *q);


#endif // QUEUE_H_INCLUDED
