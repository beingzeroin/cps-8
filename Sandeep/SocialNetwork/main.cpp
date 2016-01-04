#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

int friendship[20000][2000];
char names[20000][100];
int idx;

int addName(char name[])
{
    strcpy(names[idx], name);
    idx++;
    return idx-1;
}
int getIndex(char name[])
{
    int i;
    for(i=0;i<idx;i++)
        if(strcmp(names[i], name)==0)
            return i;

    return -1;
}
void addFriends(char n1[], char n2[])
{
    int n1Idx, n2Idx;
    if((n1Idx = getIndex(n1))==-1)
        n1Idx = addName(n1);
    if((n2Idx = getIndex(n2))==-1)
        n2Idx = addName(n2);

    friendship[n1Idx][n2Idx] =1;
    friendship[n2Idx][n1Idx] =1;
    //printf("\nAdded %s and %s as Friends", n1, n2);
}
int showMenu()
{
    printf("\n\nMENU\n");
    printf("1. Add Friendship\n");
    printf("2. List Friends\n");
    printf("3. Mutual Friends\n");
    printf("4. Path Between Two\n");
    printf("5. Stats\n");
    printf("6. Exit\n\n");

    printf("Enter your Choice: ");
    int ch;
    scanf("%d", &ch);
    return ch;
}
int main()
{
    char n1[100], n2[100];
    int choice;

    FILE *fp = fopen("friendship.txt", "r");
    assert(fp!=NULL);
    while(!feof(fp))
    {
        fscanf(fp, "%s %s\n", n1, n2);
        addFriends(n1, n2);
    }
    fclose(fp);
    while(true)
    {
        choice = showMenu();
        switch(choice)
        {
        case 1:
            printf("Enter n1 and n2: ");
            scanf("%s %s", n1, n2);
            addFriends(n1, n2);
            break;
        case 6:
            return 0; // exit(0);
        }
    }


    return 0;
}
