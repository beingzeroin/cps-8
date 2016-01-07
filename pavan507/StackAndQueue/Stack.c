#include "Stack.h"
#include <stdlib.h>
#include <assert.h>
#include "LLNode.h"
Stack *createStack()
{
    //assert(false);
    //return NULL;
    Stack *s=malloc(sizeof(Stack));
    s->top=NULL;
        s->count=0;
        return s;
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
    ElementType data=s->top->data;
    s->top=deleteFirstNode(s->top);
    s->count--;

    //assert(false);
    return data;
}

ElementType peek(Stack *s)
{
    assert(s!=NULL);
    assert(s->top!=NULL);
    ElementType data=s->top->data;
   // assert(false);
    return data;
}

bool isStackEmpty(Stack *s)
{
   // assert(false);
   //assert(s!=NULL);
    return (s==NULL||s->top==NULL);
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
   return s->count;
}
