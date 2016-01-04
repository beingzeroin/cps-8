#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

#define	N	4
char board[N][N];
bool visited[N][N];
char word[N*N+1];
int idx=0;
int count[N*N+1];
//int r,c;
bool isValid(int r,int c)
{
    if(r>=0&&r<=3&&c>=0&&c<=3)
        return true;
    else
        return false;

}
void printWordsStartingAt(int i, int j)
{
    int r,c;
    if(visited[i][j]==true)
        return;
    if(!isValid(i,j))
        return;
    visited[i][j]=true;
    word[idx]=board[i][j];
    idx++;
    word[idx]='\0';
    // Keep board[i][j]


    if(strlen(word)>=3)
    {
        printf("%s\n", word);
        count[strlen(word)]++;
        //strcpy(word,"");
        //return;
    }
    for(r=i-1; r<=i+1; r++)
    {
        for(c=j-1; c<=j+1; c++)
        {

            printWordsStartingAt(r,c);
            /*visited[r][c]=false;
            idx--;
            word[idx]='\0';*/
            // for all neighbors of board[i][j] make recursive call

        }
    }
}

    void printAllWords()
    {
        int i,j;
        for(i=0; i<=3; i++)
        {
            for(j=0; j<=3; j++)
            {
                printWordsStartingAt(i, j);
                visited[i][j]=false;
                idx--;
                word[idx]='\0';
            }
        }
    }
    int main()
    {
        int i,j;
        printf("enter matrix\n");
        for(i=0;i<=3;i++)
        {
            for(j=0;j<=3;j++)
                scanf("%c",&board[i][j]);
        }
        /*for(i=0;i<=3;i++)
        {
            for(j=0;j<=3;j++)
            {
            printf("%c ",board[i][j]);
            }
            printf("\n");
        }*/
        //printf("before calling\n");
        printAllWords();
        return 0;
    }


