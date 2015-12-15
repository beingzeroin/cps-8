#include <stdio.h>
#include <stdlib.h>

typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};

LLNode *head = NULL;

LLNode *createLLNode(int data)
{
    LLNode *t = malloc(sizeof(LLNode));
    t->data = data;
    t->next = NULL;
    return t;
}

LLNode *insertInBegin(LLNode *h, int data)
{
    LLNode *t = createLLNode(data);
    t->next = h;
    return t;
}

void traverse(LLNode *h)
{
    LLNode *t = h;
    while(t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
}

LLNode *insertInEnd(LLNode *h, int data)
{
    if(h==NULL)
        h=createLLNode(data);
    else
    {
        LLNode *temp = h;
        while(temp->next != NULL)
            temp = temp->next;
        LLNode *t = createLLNode(data);
        temp->next = t;
    }
    return h;
}
