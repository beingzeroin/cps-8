#include <stdio.h>
#include <stdlib.h>

typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};

int main()
{
    LLNode *head = NULL;
    int i=0,n,n1;
    int a[10];
    printf("Enter the no of nos to insert at beginning:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        head = insertInBegin(head, a[i]);
    }
    printf("\n");

    printf("Enter the no of nos to insert at ending:");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
        head = insertInEnd(head, a[i]);
    }
    printf("\n\n");

    traverse(head);
    return 0;
}
