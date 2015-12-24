#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "LLNode.h"
#include <stdbool.h>

typedef struct stack Stack;
struct stack
{
    LLNode *top;
    int count;
};

Stack *createStack();
void push(Stack *s, ElementType data);
ElementType pop(Stack *s);
ElementType peek(Stack *s);
bool isStackEmpty(Stack *s);
Stack * destroyStack(Stack *s);
int getStackElementCount(Stack *s);

#endif // STACK_H_INCLUDED
