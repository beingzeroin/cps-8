#include "Stack.h"
#include <stdlib.h>
#include <assert.h>

Stack *createStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->top =NULL;
    s->count =0;
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
    ElementType data = s->top->data;
    s->top = deleteFirstNode(s->top);
    s->count--;
    return data;


}

ElementType peek(Stack *s)
{
    assert(s!=NULL);

    return s->top->data;
}

bool isStackEmpty(Stack *s)
{

        return  (s=NULL||s->top==NULL);
}

Stack * destroyStack(Stack *s)
{
    assert(s!=NULL);
   s->top = destroyAllNodes(s->top);
   return NULL;
}

int getStackElementCount(Stack *s)
{
    assert(s!=NULL);
    return s->count;
}
