#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"
#include "Queue.h"

void stackUnitTests()
{
    printf("\nStack Unit Tests\n");

    assert(isStackEmpty(NULL)==true);

    Stack *s = createStack();

    assert(isStackEmpty(s)==true);

    int elements[] = {1, 2, 3, 4, 5};
    int i, n, e;
    n = sizeof(elements)/sizeof(int);
    for(i=0; i<n; i++)
        push(s, elements[i]);

    assert(isStackEmpty(s)!=true);
    i=n-1;
    while(!isStackEmpty(s))
    {
        printf("Peek: %d ", peek(s));
        assert(peek(s)==elements[i]);

        e = pop(s);
        printf("Pop: %d ", e);
        assert(e==elements[i]);
        assert(s->count==i);
        printf("Count: %d\n", s->count);
        i--;
    }

    assert(isStackEmpty(s));
    s = destroyStack(s);
    assert(s==NULL);
}

void queueUnitTests()
{
    printf("\nQueue Unit Tests\n");

    assert(isQueueEmpty(NULL)==true);

    Queue *q = createQueue();

    assert(isQueueEmpty(q)==true);

    int elements[] = {1, 2, 3, 4, 5};
    int i, n, e;
    n = sizeof(elements)/sizeof(int);
    for(i=0; i<n; i++)
        enqueue(q, elements[i]);

    assert(isQueueEmpty(q)==false);
    i=0;
    while(!isQueueEmpty(q))
    {
        assert(q->count==n-i);
        printf("Count: %d, ", q->count);
        e = dequeue(q);
        assert(e==elements[i]);
        printf("Dequeue: %d\n", e);

        i++;
    }
    q = destroyQueue(q);
}

void runUnitTests()
{
    stackUnitTests();
    //queueUnitTests();
}

int main()
{
    runUnitTests();
    return 0;
}
