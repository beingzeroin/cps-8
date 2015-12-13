#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int Board[100][100];
int NeighbourBoard[100][100];
void generateAndPrintMinesweeperBoard(int m, int n, int mines)
{
 int i,j,k,r,c;
 for(i=0;i<m;i++)
 {
     for(j=0;j<n;j++)
     {
            Board[i][j]=0;

     }

 }
 for(k=0;k<mines;k++)
 {
     srand(time(NULL));
     r=rand()%m;
     c=rand()%n;
     if(Board[r][c]==1)
     {
         k--;
     continue;
     }
     else
     {
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
void PrintNeighbourBoard(int m,int n)
{
    int i,j;
  for(i=0;i<m;i++)
  {
     for(j=0;j<n;j++)
     {
         NeighbourBoard[i][j]=0;
         NeighbourBoard[i][j]=AssignNeighbours(m,n,i,j);
         printf("%d ",NeighbourBoard[i][j]);

     }
     printf("\n");
  }

}

int AssignNeighbours(int m,int n,int r,int c)
{
    int count=0;
    if((r-1)>=0&&(c-1)>=0&&Board[r-1][c-1]==1)
        count++;
    if((r-1)>=0&&Board[r-1][c]==1)
        count++;
    if((r-1)>=0&&(c+1)<=n&&Board[r-1][c+1]==1)
        count++;
    if((c-1)>=0&&Board[r][c-1]==1)
        count++;
    if((c+1)<=n&&Board[r][c+1]==1)
        count++;
    if((r+1)<=m&&(c-1)>=0&&Board[r+1][c-1]==1)
        count++;
    if((r+1)<=m&&Board[r+1][c]==1)
        count++;
    if((r+1)<=m&&(c+1)<=n&&Board[r+1][c+1]==1)
        count++;

    return count;
}

int main()
{

    int rows,col,mines;
    scanf("%d %d %d",&rows,&col,&mines);;
    generateAndPrintMinesweeperBoard(rows,col,mines);
    printf("\nNeighbourBoard\n\n");
    PrintNeighbourBoard(rows,col);
    return 0;
}
