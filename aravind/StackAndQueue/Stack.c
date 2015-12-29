#include "Stack.h"
#include <stdlib.h>
#include <assert.h>

Stack *createStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    s->count = 0;
    return s;
}

void push(Stack *s, ElementType data)
{
    assert(s!=NULL);
    s->top = insertInBegin(s->top,data);
    s->count++;
}

ElementType pop(Stack *s)
{

    assert(s!=NULL);
    assert(s->top!=NULL);
    ElementType data = s->top->data;
    s->top = deleteFirstNode(s->top);
    s->count--;
    return data;
}

ElementType peek(Stack *s)
{
    assert(s!=NULL);
    assert(s->top!=NULL);
    return s->top->data;
}

bool isStackEmpty(Stack *s)
{
    return (s==NULL || s->top==NULL); /* count also can be used */
}

Stack * destroyStack(Stack *s)
{
    assert(s!=NULL);
    s->top = destroyAllNodes(s->top);
    free(s);
    return NULL;
}

int getStackElementCount(Stack *s)
{
    assert(s!=NULL);
    return (s->count);
}
