#include "Stack.h"
#include <stdlib.h>
#include <assert.h>

Stack *createStack()
{
    //assert(false);
    Stack *newTop=malloc(sizeof(Stack));
    newTop->top=NULL;
    newTop->count=0;
    return newTop;
}

void push(Stack *s, ElementType data)
{
    assert(s!=NULL);
    s->top=insertInBegin(s->top,data);
    s->count++;
    //assert(false);
}

ElementType pop(Stack *s)
{
    assert(s!=NULL);
    assert(s->top!=NULL);
    ElementType a=s->top->data;
    s->top=deleteFirstNode(s->top);
    s->count--;
    //assert(false);
    return a;
}

ElementType peek(Stack *s)
{
    assert(s!=NULL);
    assert(s->top!=NULL);
    return s->top->data;
}

bool isStackEmpty(Stack *s)
{
    //assert(s!=NULL);
    return (s==NULL || s->top==NULL);
}

Stack * destroyStack(Stack *s)
{
    assert(s!=NULL);
    s->top=destroyAllNodes(s->top);
    free(s);
    return NULL;
}

int getStackElementCount(Stack *s)
{
    assert(s!=NULL);
    //assert(false);
    return s->count;
}
