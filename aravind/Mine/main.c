#include<stdio.h>
#include<stdlib.h>

int board[20][20];
void generateAndPrintMinesweeperBoard(int m,int n,int mines)
{
    int i=0,a,b,j;
    while(i<mines)
    {
        a = rand()%m;
        b = rand()%n;
        if(board[a][b]!=1)
        {
            board[a][b]=1;
            i++;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",board[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int length,breadth,mines;
    scanf("%d %d %d",&length,&breadth,&mines);
    generateAndPrintMinesweeperBoard(length,breadth,mines);
    return 0;
}
