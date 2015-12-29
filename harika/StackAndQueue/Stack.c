#include "Stack.h"
#include <stdlib.h>
#include <assert.h>

Stack *createStack()
{
    Stack *s=malloc(sizeof(Stack));
    s->top=NULL;
    s->count=0;
    return s;

}

void push(Stack *s, ElementType data)
{
    s->top=insertInBegin(s->top,data);
    s->count++;
}

ElementType pop(Stack *s)
{
    assert(s->top!=NULL);
    ElementType data=s->top->data;

    s->top=deleteFirstNode(s->top);
    s->count--;
    return data;

}

ElementType peek(Stack *s)
{
    assert(s->top!=NULL);
    return s->top->data;

}

bool isStackEmpty(Stack *s)
{
    return(s==NULL || s->top==NULL);

}

Stack * destroyStack(Stack *s)
{
    s->top=destroyAllNodes(s->top);
    free(s);
    return NULL;
}

int getStackElementCount(Stack *s)
{
    return s->count;


}
