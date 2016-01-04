#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int board[100][100];

void init(int r,int c,int mine)
{
    int i,j,m,n,k;
     srand(time(NULL));
    for(i=0;i<r;i++)
       {
           for(j=0;j<c;j++)
            board[i][j]=0;
       }
    for(k=0;k<mine;)
    {

        m=rand()%r;
        n=rand()%c;
        if(board[m][n]!=9)
        {
            board[m][n]=9;
            k++;
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            {
                if(board[i][j]==9)
                {
                    if(board[i][j-1]!=9&&i>=0&&j-1>=0)
                        board[i][j-1]++;
                    if(board[i][j+1]!=9&&i>=0&&j+1>=0)
                        board[i][j+1]++;
                    if(board[i-1][j]!=9&&i-1>=0&&j>=0)
                        board[i-1][j]++;
                    if(board[i+1][j]!=9&&i+1>=0&&j>=0)
                        board[i+1][j]++;
                    if(board[i-1][j-1]!=9&&i-1>=0&&j-1>=0)
                        board[i-1][j-1]++;
                    if(board[i+1][j-1]!=9&&i+1>=0&&j-1>=0)
                        board[i+1][j-1]++;
                    if(board[i-1][j+1]!=9&&i-1>=0&&j+1>=0)
                        board[i-1][j+1]++;
                    if(board[i+1][j+1]!=9&&i+1>=0&&j+1>=0)
                        board[i+1][j+1]++;
                }
            }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            {
                printf("%2d",board[i][j]);
            }
            printf("\n");
    }
}


int main()
{
    int row,col,minec;
    printf("Enter no of rows,col and mine count\n");
    scanf("%d %d %d",&row,&col,&minec);
    init(row,col,minec);
}
