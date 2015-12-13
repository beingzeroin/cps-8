#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int Board[100][100];
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
int main()
{

    int m,n,mines;
    scanf("%d %d %d",&m,&n,&mines);;
    generateAndPrintMinesweeperBoard(m,n,mines);
    return 0;
}
