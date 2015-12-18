#include "Stack.h"
#include <stdlib.h>
#include <assert.h>


Stack *createStack()
{
    Stack *s=malloc(sizeof(Stack));
    s->top=NULL;
    s->count=0;

}

void push(Stack *s, ElementType data)
{
    assert(s->top!=NULL);
    s->top=insertInBegin(s->top,data);
    s->count++;
    return s->top;
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
    ElementType d=s->top->data;
    return s->top->data;
}

bool isStackEmpty(Stack *s)
{
    assert(s->top!=NULL);
    if(s->top==NULL)
        return true;
    else
        return false;           //if(s->count==0) also can be used
}

Stack * destroyStack(Stack *s)
{
   assert(s->top!=NULL);
   s->top= destroyAllNodes(s->top);
   return NULL;
}

int getStackElementCount(Stack *s)
{
    assert(s->top!=NULL);

}
