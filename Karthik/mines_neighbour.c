#include<time.h>
#include<stdio.h>
char Board[100][100];
void generateAndPrintMinesweeperBoard(int m, int n, int mines)
{
    int r,c,i,j;
    srand(time(NULL));
    for(i=0;i<=m+1;i++)
        for(j=0;j<=n+1;j++)
            Board[i][j]='0';
    for(i=0;i<mines;i++)
    {
        r=rand()%m + 1;
        c=rand()%n + 1;
        if(Board[r][c]=='*')
            i--;
        else
            Board[r][c]='*';
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            printf("%c ",Board[i][j]);
        printf("\n");
    }
    generateAndPrintNeighbours(m,n);

}
char getNeighbourCount(int m,int n)
{
    int i,j;
    char count=48;
	for(i=m-1;i<=m+1;i++)
	{
        for(j=n-1;j<=n+1;j++)
		{
            if(Board[i][j]=='*')
			    count+=1;
		}
	}
    //printf("\n%d",count);
	return count;
}
void generateAndPrintNeighbours(int m,int n)
{
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(Board[i][j]=='0')
                Board[i][j]=getNeighbourCount(i,j);
	printf("\n\n");
	for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            printf("%c ",Board[i][j]);
        printf("\n");
    }
}
int main()
{
    generateAndPrintMinesweeperBoard(4,4,5);
    return 0;
}
