#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int friendship[2000][2000];
char names[2000][100];
int idx;

void addName(char name[])
{
    strcpy(names[idx], name);
    idx++;
}
int getIndex(char name[])
{
    int i=0;
    while(1)
    {
        if(strcmp(names[i],name)==0);
            return i;
        i++;
    }
    return -1;
}
int showMenu()
{
    printf("MENU\n");
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
void addFriendship(char *s1,char *s2)
{
    int idx1=getIndex(s1);
    int idx2=getIndex(s2);
    friendship[idx1][idx2]=1;
    friendship[idx2][idx1]=1;
}
void listFriends(char *s)
{
    int idx=getIndex(s),i;
    for(i=0;i<2000;i++)
        if(friendship[idx][i]==1)
            printf("%s\n",names[i]);
}
void listMutualFriends(char *s1,char *s2)
{
    int idx1=getIndex(s1);
    int idx2=getIndex(s2);
    int i;
    for(i=0;i<2000;i++)
        if(friendship[idx1][i]==1 && friendship[idx2][i]==1)
            printf("%s\n",names[i]);
}
int leastFriendly()
{
    int i,j;
    int leastIdx=0,leastVal=2000;
    for(i=0;i<2000;i++)
    {
        int least=0;
        for(j=0;j<2000;j++)
            if(friendship[i][j]==1)
                least++;
        if(least<leastVal)
        {
            leastVal=least;
            leastIdx=i;
        }
    }
    return leastIdx;
}
int mostFriendly()
{
    int i,j;
    int mostIdx=0,mostVal=0;
    for(i=0;i<2000;i++)
    {
        int most=0;
        for(j=0;j<2000;j++)
            if(friendship[i][j]==1)
                most++;
        if(most>mostVal)
        {
            mostVal=most;
            mostIdx=i;
        }
    }
    return mostIdx;
}
int main()
{

    int choice;
    char *s1=NULL,*s2=NULL,*s=NULL;
    while(true)
    {
        choice = showMenu();
        switch(choice)
        {
        case 1:
            //char *s1,*s2;
            scanf("%s,%s",s1,s2);
            addFriendship(s1,s2);
            break;
        case 2:
            //char *s;
            scanf("%s",s);
            listFriends(s);
            break;
        case 3:
            //char *s1,*s2;
            scanf("%s,%s",s1,s2);
            listMutualFriends(s1,s2);
            break;
        case 4:
            //printPath();
            break;
        case 5:
            printf("Least Friendly :%s\n",names[leastFriendly()]);
            printf("Most Friendly : %s\n",names[mostFriendly()]);
            break;
        case 6:
            return 0; // exit(0);
        }
    }


    return 0;
}
