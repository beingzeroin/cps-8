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
    /*
    int *p, *c, *t;
    int temp = 0;
    p = a;
    c = a+1;
    while(c < a+n)
    {
        if(*c > *p)
        {
            c++;
            p++;
        }
        else
        {
            t = p;
            temp = *c;
            while(t >= a)
            {
                if(*t > *c)
                {
                    *c = *t;
                    t--;
                }
                else
                {
                    *t = temp;
                }
            }
        }
    }
    */
    int i, j;
    for(i=1;i<n;i++)

        for(j=i-1;j>=0;j--)
        {
            if()
        }
}
void selectionSort(int a[], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i] > a[j])
            {
                swap(a,j,i);
            }
        }
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
