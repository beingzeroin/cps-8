#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "trie.h"

char board[10][10];
char *word;
TNode *myTrie;

void generateWords();
void getWordsStartingFrom(int x,int y,int last, bool visited[4][4]);
void createDictionary();
void initializeVisited(bool visited[4][4]);

int main()
{
    createDictionary();
    int i;
    printf("Enter 4X4 matrix : \n\n");
    for(i = 0; i < 4; i++)
        scanf("%s",board[i]);
    generateWords();
    return 0;
}
void createDictionary()
{
    myTrie = createTrieNode();
    FILE *fp = fopen("dictionary.txt", "r");
    assert(fp != NULL);
    while(!feof(fp))
    {
        char word[100];
        fscanf(fp,"%s",word);
        insertWordTrie(myTrie,word);
    }
    fclose(fp);
}
void generateWords()
{
    int i, j;
    bool visited[4][4];
    word = malloc(17*sizeof(char));
    printf("\nWords are : \n\n");
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
        {
            word[0] = '\0';
            initializeVisited(visited);
            getWordsStartingFrom(i,j,0,visited);
        }
    free(word);
}
void initializeVisited(bool visited[4][4])
{
    int i, j;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            visited[i][j] = false;
}
void getWordsStartingFrom(int x,int y,int last, bool visited[4][4])
{
    visited[x][y] = true;

    word[last] = board[x][y];
    word[last+1] = '\0';

    if((last+1) >= 3 && hasWord(myTrie,word))
        printf("%s\n",word);

    if((x-1) >= 0 && !visited[x-1][y])//TOP
        getWordsStartingFrom(x-1,y,last+1,visited);
    if(((x-1) >= 0) && ((y+1) < 4) && !visited[x-1][y+1])//TOP-RIGHT
        getWordsStartingFrom(x-1,y+1,last+1,visited);
    if((y+1) < 4 && !visited[x][y+1])//RIGHT
        getWordsStartingFrom(x,y+1,last+1,visited);
    if(((x+1) < 4) && ((y+1) < 4) && !visited[x+1][y+1])//BOTTOM-RIGHT
        getWordsStartingFrom(x+1,y+1,last+1,visited);
    if((x+1) < 4 && !visited[x+1][y])//BOTTOM
        getWordsStartingFrom(x+1,y,last+1,visited);
    if(((x+1) < 4) && ((y-1) >= 0) && !visited[x+1][y-1])//BOTTOM-LEFT
        getWordsStartingFrom(x+1,y-1,last+1,visited);
    if((y-1) >= 0 && !visited[x][y-1])//LEFT
        getWordsStartingFrom(x,y-1,last+1,visited);
    if(((x-1) >= 0) && ((y-1) >= 0) && !visited[x-1][y-1])//TOP-LEFT
        getWordsStartingFrom(x-1,y-1,last+1,visited);

    visited[x][y] = false;// important
}
