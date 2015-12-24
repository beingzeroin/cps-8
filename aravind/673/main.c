#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef char ElementType;
typedef struct LLNode LLNode;

// Define Structure LLNode
struct LLNode
{
    ElementType data;
    LLNode *next;
};

typedef struct stack Stack;
struct stack
{
    LLNode *top;
    int count;
};

LLNode* createLLNode(ElementType data)
{
    LLNode *a = malloc(sizeof(LLNode));
    a->data = data;
    a->next = NULL;
    return a;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    LLNode *a = createLLNode(data);
    a->next = head;
    return a;
}

LLNode* deleteFirstNode(LLNode *head)
{
    if(head==NULL)
        return head;
    LLNode *t = head->next;
    free(head);
    return t;
}

LLNode* destroyAllNodes(LLNode *head)
{
   LLNode *t = head;
   while(head!=NULL)
   {
       t = head->next;
       free(head);
       head = t;
   }
   return NULL;
}


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

int main()
{
    int n;
    scanf("%d\n",&n);
    while(t--)
    {
        gets(line);
        Stack *s = createStack();

    }
    return 0;
}
