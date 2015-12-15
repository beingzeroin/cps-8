#include <stdio.h>
#include <stdlib.h>

typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};

LLNode *createLLNode(int data)
{
    LLNode *temp = malloc(sizeof(LLNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
LLNode *insertInBegin(LLNode *h,int data)
{
    LLNode *temp;
    temp = createLLNode(data);
    temp->next = h;
    return temp;
}
LLNode *insertInEnd(LLNode *h,int data);
void traverse(LLNode *h)
{
    LLNode *t = h;
    while(t->next!=NULL) //while(
    {
        printf("%d ",t->date);
        t = t->next;
    }
}
int main()
{
    LLnode *head = NULL;
    head = insertInBegin(head, 5);
    head = insertInBegin(head, 4);
    head = insertInBegin(head, 3);
    head = insertInBegin(head, 2);
    head = insertInBegin(head, 1);
    traverse(head);
    return 0;
}

