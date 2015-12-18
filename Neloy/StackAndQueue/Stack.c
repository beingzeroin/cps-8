#include "Stack.h"
#include <stdlib.h>
#include <assert.h>

Stack *createStack()
{
    //assert(false);
    Stack *t = malloc(sizeof(Stack));
    t->top = NULL;
    t->count = 0;
    return t;
}

void push(Stack *s, ElementType data)
{
    //assert(false);
    assert(s!=NULL);
    LLNode *t = createLLNode(data);
    t->next = s->top;
    s->top = t;
    s->count++;
}

ElementType pop(Stack *s)
{
    /*
    ElementType a = s->top->data;
    LLNode *t = s->top->next;
    free(s->top);
    s->top = t;
    s->count--;*/
    assert(s!=NULL);
    assert(s->top!=NULL);
    ElementType a = s->top->data;
    s->top = deleteFirstNode(s->top);
    s->count--;
    return a;
}

ElementType peek(Stack *s)
{
    assert(s!=NULL);
    ElementType a = s->top->data;
    //assert(false);
    return a;
}

bool isStackEmpty(Stack *s)
{
    //assert(false);
    /*if(s==NULL)
        return true;
    if(s->top == NULL)
        return true;
    else
        return false;*/
    return (s==NULL || s->top==NULL);
}

Stack * destroyStack(Stack *s)
{
    assert(s!=NULL);
    //if(s==NULL)
    //    return NULL;
   destroyAllNodes(s->top);
   free(s);
   return NULL;
}

int getStackElementCount(Stack *s)
{
    //assert(false);
    if(s==NULL)
        return 0;
    return s->count;
}
