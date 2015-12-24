
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
typedef int ElementType;
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
    LLNode *t  = malloc(sizeof(LLNode));
    t->next = NULL;
    t->data = data;
    return t;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    LLNode *t = createLLNode(data);
    //if(head==NULL)
    //  return t;
    t->next = head;
    return t;
}
LLNode *insertInEnd(LLNode *head,ElementType data)
{
    LLNode *newNode=createLLNode(data);
    LLNode *temp=head;
    if(head==NULL)
    return newNode;
    while(temp->next!=NULL)
    {

        temp=temp->next;
    }
    temp->next=newNode;


    return head;
}
LLNode* deleteLastNode(LLNode *head)
{
    if(head==NULL)
        return head;
    LLNode* temp1=head;
    if(temp1->next==NULL)
    {


        free(head);
    return NULL;
    }
    LLNode* temp2=head->next;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
        temp1=temp1->next;

    }
    return temp1;


}
LLNode* deleteFirstNode(LLNode *head)
{
    if(head==NULL)
        return NULL;
    LLNode *t = head->next;
    free(head);
    return t;
}

LLNode* destroyAllNodes(LLNode *head)
{
    LLNode *n;
    while(head!=NULL)
    {
        n = head->next;
        free(head);
        head=n;
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
    s->top = insertInBegin(s->top, data);
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
    return (s==NULL || s->top==NULL);
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
    return s->count;
}
void stackUnitTests()
{
    printf("\nStack Unit Tests\n");

    assert(isStackEmpty(NULL)==true);

    Stack *s = createStack();

    assert(isStackEmpty(s)==true);

    int elements[] = {1, 2, 3, 4, 5};
    int i, n, e;
    n = sizeof(elements)/sizeof(int);
    for(i=0; i<n; i++)
        push(s, elements[i]);

    assert(isStackEmpty(s)!=true);
    i=n-1;
    while(!isStackEmpty(s))
    {
        printf("Peek: %d ", peek(s));
        assert(peek(s)==elements[i]);

        e = pop(s);
        printf("Pop: %d ", e);
        assert(e==elements[i]);
        assert(s->count==i);
        printf("Count: %d\n", s->count);
        i--;
    }

    assert(isStackEmpty(s));
    s = destroyStack(s);
    assert(s==NULL);
}
void runUnitTests()
{
    stackUnitTests();
    //queueUnitTests();
}

int main()
{
    runUnitTests();
    return 0;
}

