#include <stdio.h>
#include <stdlib.h>
int a[100][100];
void minesweeperboardgen(int m,int n,int mines)
{
    int i,j,k;
    for(i=0; i<mines;)
    {
        int r=rand()%m;
        int c=rand()%n;
        if(a[r][c]!=1)
        {
            a[r][c]=1;
            i++;
        }
    }
    for(k=0; k<m; k++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",a[k][j]);
        }
        printf("\n");
    }
}

int main()
{
    minesweeperboardgen(4,4,5);
    return 0;
}
