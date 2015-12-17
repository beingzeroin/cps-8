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

LLNode* createLLNode(ElementType data)
{
    LLNode *newNode=malloc(sizeof(LLNode));
    newNode->data=data;
    newNode->next=NULL;
    //assert(false);
    return newNode;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    //assert(false);
    LLNode *newHead=createLLNode(data);
    newHead->next=head;
    //head=newHead;
    return newHead;
}

LLNode* deleteFirstNode(LLNode *head)
{
    if(head==NULL)
        return NULL;
    else
    {
        LLNode *temp=head->next;
        free(head);
        return temp;
    }
}

LLNode* destroyAllNodes(LLNode *head)
{
   LLNode *prev=NULL;
   while(head!=NULL)
   {
       prev=head;
       head=head->next;
       free(prev);
   }
   return NULL;
}

typedef struct stack Stack;
struct stack
{
    LLNode *top;
    int count;
};
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
