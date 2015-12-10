#include<time.h>
#include<stdio.h>
int Board[100][100];
void generateAndPrintMinesweeperBoard(int m, int n, int mines)
{
    int r,c,i,j;
    srand(time(NULL));
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            Board[i][j
            ]=0;
    for(i=0;i<mines;i++)
    {
        r=rand()%m;
        c=rand()%n;
        if(Board[r][c]==1)
            i--;
        else
            Board[r][c]=1;
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",Board[i][j]);
        printf("\n");
    }

}
int main()
{
    generateAndPrintMinesweeperBoard(4,4,5);
    return 0;
}
