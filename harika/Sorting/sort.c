#include <assert.h>
#include <stdbool.h>

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
}
void selectionSort(int a[], int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        t=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[t])
                t=j;
        }
        if(t!=i)
            swap(a,t,i);

    }
}
void bubbleSort(int a[], int n)
{
    assert(false);
}


void merge(int a[], int l, int m, int h)
{
   assert(false);
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
    int j,i;
    int p=a[h];
    j=l-1;
    for(i=l;i<=h-1;i++)
    {
        if(a[i]<=p)
        {
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,h);
    return (i+1);

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
