#include <stdio.h>
#include <stdlib.h>

void generateAndPrintMineSweep(int m,int n,int mines,int a[100][100])
{
    int i,r,c,j;

    srand(time(NULL));
    for(i=0;i<mines;i++)
    {
        r=rand()%(m);
        c=rand()%(n);

        if(a[r][c]==1)
        {
            i--;

        }
        else
           a[r][c]=1;
    }
    for(i=0;i<m;i++)
    {

           printf("\n");
    {
        for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
    }
    }
}

int main()
{
    int m,n,mines,a[100][100];
    int i,j;

    printf("\n enter the rows and columns");
    scanf("%d%d",&m,&n);
    printf("\n enter the no. of mines");
    scanf("%d",&mines);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        a[i][j]=0;
     generateAndPrintMineSweep(m,n,mines,a);
     getch();


    return 0;
}
