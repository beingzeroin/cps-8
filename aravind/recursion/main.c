#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define swap(a,i,j) {char t = a[i];a[i] = a[j];a[j] = t;}
int fingers(int n)
{
    if(n==1)
        return 10;
    else if(n%2==0)
        return(11 + fingers(n-1));
    else
        return(10 + fingers(n-1));
}
int sumDigits(int n)
{
    if(n==0)
        return 0;
    return (n%10+sumDigits(n/10));
}
void stringReverse(char a[], int s, int e)
{

    if(s>=e)
        return;
    else
    {
        int temp = a[s];
        a[s] = a[e];
        a[e] = temp;
        stringReverse(a, s+1, e-1);
    }
}
void stringReverse1(char a[], int s, int e)
{
    if(s<e)
    {
        swap(a,s,e);
        stringReverse1(a,s+1,e-1);
    }
}
bool hasNumber(int a[], int length, int key)
{
    if(a[length]==key)
        return true;
    else if(length>=1)
        return hasNumber(a,length-1,key);
    else
        return false;
}
bool hasNumber1(int a[], int length, int key)
{
    if(length==0)
        return false;
    if(a[length]==key)
        return true;
    else if(length>=1)
        return hasNumber(a,length-1,key);
    else
        return false;
}
void printRevLL(LLNode *head)
{
    if(h==NULL)
        return;
    if(h->next!=NULL)
        printReverseRecursive(h->next);
    printf("%d ",h->data);
}
void printRevLL(LLNode *head)
{
    if(h!=NULL)
    {
        printReverseRecursive(h->next);
        printf("%d ",h->data);
    }
}
LLNode *alternateMerge(LLNode *h1, LLNode *h2)
{
	if(h1==NULL)
	return h2;
	if(h2==NULL)
	return h1;
	h1->next = alternateMerge(h2,h1->next);
	return h1;
}
LLNode *reverseRecursive(LLNode *h1, LLNode *p)
{
	if(h1==NULL)
	    return NULL;
	if(h1->next==NULL)
	{
	    h1->next = p;
	    return h1;
	}
	LLNode *l = reverseRecursive(h1->next,h1);
	h1->next = p;
	return l;
}
int main()
{
    int a[]={1,2,3,4,5,6,7};
    printf("%d",hasNumber(a,6,8));
    /*
    char a[]="Hello";
    stringReverse(a,0,strlen(a)-1);
    printf("%s",a);
    stringReverse1(a,0,strlen(a)-1);
    printf("%s",a);
    */
    //printf("%d",sumDigits(1));
    //printf("%d",fingers(2));
    return 0;
}
