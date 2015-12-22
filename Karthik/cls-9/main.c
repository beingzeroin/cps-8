#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int totalFingers(int people)
{
    if(people==0)//or people==1
        return 0;//      return 10;
    if(people%2==0)
        return 11+totalFingers(people-1);
    else
        return 10+totalFingers(people-1);
}

int sumOfDigits(int n)
{
    if(n==0)
        return 0;
    return n%10 + sumOfDigits(n/10);
}

void reverse(char a[],int s,int e)
{
    if(s<e)
    {
        int temp=a[s];
        a[s]=a[e];
        a[e]=temp;
        reverse(a,s+1,e-1);
    }
}

bool searchInt(int arr[],int len,int key)
{
    if(len==-1)
        return false;
    if(arr[len-1]==key)
        return true;
    else
        searchInt(arr,len-1,key);
}

typedef struct n LLNode;
struct n
{
    int data;
    LLNode *next;
};

void printReverseRecursive(LLNode *h)
{
    if(h==NULL)
        return;
    printReverseRecursive(h->next);
    printf("%d ",h->data);
}
int main()
{
    int arr[20]={1,12,13,23};
    printf("%d",searchInt(arr,sizeof(arr)/sizeof(int),1));
    return 0;
}
