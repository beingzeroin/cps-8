#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Board[100][100];
void generateAndPrintMinesweeperBoard(int m,int n,int mines)
{
    int i,j,r1,c1;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(mines>0 && mines<(m*n))
            {
                for(i=0; i<m; i++)
                {
                    for(j=0; j<n; j++)
                    {
                        Board[i][j] = 0;
                    }
                }
                for(i=0; i<mines; i++)
                {
                    srand(time(NULL));
                    r1 = rand() % m;
                    c1 = rand() % n;
                    if(Board[r1][c1] == 1)
                    {
                        i--;
                        continue;
                    }
                    else
                        Board[r1][c1] = 1;
                }
            }
            printf("\n");
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d",Board[i][j]);
                printf(" ");
            }
            printf("\n");
        }
    }
}

int mines()
{
    int a,b,mines;
    printf("Enter the board dimensions and mines:");
    scanf("%d %d %d",&a,&b,&mines);
    generateAndPrintMinesweeperBoard(a,b,mines);
    return 0;
}
