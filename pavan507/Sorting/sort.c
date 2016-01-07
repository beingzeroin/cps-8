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
    int i,j,t=0,k;
    for(i=1;i<n;i++)
    {
        k=0;
        for(j=i-1;j>=0;j--)
        {
            if(j<0)
                a[0]=t;
        if(a[j]>a[i]&&k==0)
        {
            t=a[i];
            k=1;
        }

         if(k==1)
        {
            a[j+1]=a[j];
        }

    }
}
}
void selectionSort(int a[], int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i]>a[j])
                swap(a,i,j);

        }

    }
   // assert(false);
}
void merge(int a[], int l, int m, int h)
{
    int b[h+l-1],i=l,j=m+1,k=0;
    while(i<=m&&j<=h)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
     while(i<=m)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=h)
    {
        b[k]=a[j];
        k++;
        j++;
    }

    j=0;
    for(i=l;i<=h;i++)
      {
          a[i]=b[j++];
      }

}

void bubbleSort(int a[], int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        if(a[j]>a[j+1])
        {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
    }

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
    return a[l];
    //assert(false);
}
void quickSortR(int a[], int l, int h)
{
    int pivot,i,j,t;
    if(l<=h)
    {
        pivot=l;
        i=l;
        j=h;
        while(i<j)
        {
           while(a[i]<=a[pivot]&&i<=h)
                i++;
           while(a[j]>a[pivot]&&j>=l)
            j--;
            if(i<j)
            {
           t=a[i];
           a[i]=a[j];
           a[j]=t;
            }
        }
        t=a[j];
        a[j]=a[pivot];
        a[pivot]=t;
        quickSortR(a,l,j-1);
        quickSortR(a,j+1,h);


    }
}

void quickSort(int a[], int n)
{
	quickSortR(a, 0, n-1);
}
