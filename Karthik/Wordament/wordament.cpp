#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 4
char board[N][N];
bool visited[N][N];
char word[N*N +1];
int idx;
int wordCount[N*N +1];
bool isValid(int i,int j)
{
    if(i<0 || i>=N)
        return false;
    if(j<0 || j>=N)
        return false;
    return true;
}
void printWordsStartingAt(int i,int j)
{
    if(!isValid(i,j))
        return;
    if(visited[i][j])
        return;
    word[idx]=board[i][j];
    idx=idx+1;
    visited[i][j]=true;
    word[idx]='\0';
    if(strlen(word)>=3)
    {
        printf("%s\n",word);
        wordCount[strlen(word)]++;
    }
    int p,q;
    for(p=i-1;p<i+1;p++)
        for(q=j-1;q<j+1;q++)
            printWordsStartingAt(p,q);
    word[idx]='\0';
    idx--;
    visited[p][q]=false;
}
void printAllWords()
{
    word[0]='\0';
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            printWordsStartingAt(i,j);
}
void getBoard()
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%c",&board[i][j]);
}
