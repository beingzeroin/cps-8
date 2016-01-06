#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


void insertionSort(int a[], int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>t)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=t;
    }
    //assert(false);
}
void selectionSort(int a[], int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        t=i;
        for(j=i+1;i<n;i++)
        {
            if(a[j]<a[t])
                t=j;
        }
        swap(a,i,t);
    }
    //assert(false);
}
void bubbleSort(int a[], int n)
{
    assert(false);
}


void merge(int a[], int l, int m, int h)
{
    int *t;
    int i,len;
    len=h-l;
    t=(int *)malloc(len*sizeof(int));
    int l1=l,h1=m;
    int l2=m+1,h2=h;
    for(i=0;i<len&&l1<=h1&&l2<=h2;i++)
    {
        if(a[l1]<=a[l2])
        {
            t[i]=a[l1];
            l1++;
        }
        else if(a[l2]<a[l1])
        {
            t[i]=a[l2];
            l2++;
        }
    }
    if(l1==h1)
        for( ;i<len && l2<=h2;i++,l2++)
            t[i]=a[l2];
    else if(l2==h2)
        for( ;i<len && l1<=h1;i++,l1++)
            t[i]=a[l1];
    int j;
    for(i=l,j=0;i<h && j<len;i++,j++)
        a[i]=t[j];
    //assert(false);
}

void mergeSortR(int a[], int l, int h)
{
    if(l>=h)
        return;

    int m=(l+h)/2;

    mergeSortR(a, l, m);
    mergeSortR(a, m+1, h);
    merge(a, l, m, h);
}

void mergeSort(int a[], int n)
{
    mergeSortR(a, 0, n-1);
}



int getPivot(int a[], int l, int h)
{
    assert(false);
}
void quickSortR(int a[], int l, int h)
{
	if(l>=h)
		return;
	int p = getPivot(a, l, h);
	quickSortR(a, l, p-1);
	quickSortR(a, p+1, h);
}

void quickSort(int a[], int n)
{
	quickSortR(a, 0, n-1);
}
