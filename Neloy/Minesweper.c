#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Board[100][100];

int neighbourBoard[100][100];

void generateAndPrintMinesweeperBoard(int m,int n,int mines)
{
    int i,j,r,c;
    if(mines<0 || mines>m*n)
    {
        printf("NOT POSSIBLE");
        return;
    }
    else
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                Board[i][j]=0;
            }
        }
        for(i=0;i<mines;i++)
        {
            srand(time(NULL));
            r=rand()%m;
            c=rand()%n;
            if(Board[r][c]==1)
            {
                i--;
                continue;
            }
            else{
            Board[r][c]=1;
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d ",Board[i][j]);
            }
            printf("\n");
        }
    }
}

int countNeighbours(int r,int c,int m, int n)
{
    int count=0;
    if((r-1)>=0 && (c-1)>=0 && Board[r-1][c-1]==1)
        count++;
    if((r-1)>=0 && Board[r-1][c]==1)
        count++;
    if((r-1)>=0 && (c+1)<=n && Board[r-1][c+1]==1)
        count++;
    if((c-1)>=0 && Board[r][c-1]==1)
        count++;
    if((c+1)<=n && Board[r][c+1]==1)
        count++;
    if((r+1)<=m && (c-1)>=0 && Board[r+1][c-1]==1)
        count++;
    if((r+1)<=m && Board[r+1][c]==1)
        count++;
    if((r+1)<=m && (c+1)<=n && Board[r+1][c+1]==1)
        count++;

    return count;
}

void generateNeighbourCountBoard(int r,int c)
{
    int i,j;
    printf("\nNeighbour Board:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
           neighbourBoard[i][j]=0;
           neighbourBoard[i][j]=countNeighbours(i,j,r,c);
           printf("%d ",neighbourBoard[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m,n,c;
    scanf("%d %d %d",&m,&n,&c);
    generateAndPrintMinesweeperBoard(m,n,c);
    generateNeighbourCountBoard(m,n);
    return 0;
}
