#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int friendship[20000][20000];
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
    for(int i=0;i<idx;i++)
    {
        if(strcmp(name,names[i])==0)
            return i;

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
void addFriend(char str1[],char str2[])
{

    int id1,id2;
    id1=getIndex(str1);
    id2=getIndex(str2);
    if(id1==-1)
    {
        id1=addName(str1);
    }
    if(id2==-1)
    {
       id2=addName(str2);

    }
    friendship[id1][id2]=1;
    friendship[id2][id1]=1;

}
void listFriends()
{
    char name[20];
  printf("enter name to find friendlist\n");
  scanf("%s",name);
  printf("%s :",name);
  int in=getIndex(name);
  for(int i=0;i<idx;i++)
  {
      if(friendship[in][i]==1)
      {
        printf("%s ",names[i]);
      }

  }



}
void mutualFriends()
{
    char str1[20],str2[20];
    printf("enter names to find mutual friends\n");
    scanf("%s%s",str1,str2);
    int id1=getIndex(str1);
    int id2=getIndex(str2);
    for(int i=0;i<idx;i++)
    {
        if(friendship[id1][i]==1&&friendship[id2][i]==1)
        {

            printf("%s\n",names[i]);
        }

    }

}
void printPath(int id1,int id2);
void path(char str1[],char str2[])
{
    int id1=getIndex(str1);
    int id2=getIndex(str2);
    if(id1==-1||id2==-1)
        printf("no path exists\n");
        printf("%d %d\n",id1,id2);
    printPath(id1,id2);

}
int root[20000],k=0;
bool visited[20000];
void printPath(int id1,int id2)
{
     if(visited[id1])
        return;
    if(id1==id2)
    {
        for(int i=0;i<k;i++)
        {
            if(i==0)
                printf("%s",names[root[i]]);
            else
                printf("->%s",names[root[i]]);

        }
        printf("->%s",names[id2]);
    }

          root[k]=id1;
          k++;
    visited[id1]=true;
    for(int i=0;i<idx;i++)
    {
        if(friendship[id1][i]==1&&!visited[i])
        {
           //printf("call with %d %d\n",i,id2);
            printPath(i,id2);
        }

    }
    k--;
    visited[id1]=false;
}
int maxmm=0,minmm=30000;
void stats()
{
    int i,j,id1,id2,s;
   for(i=0;i<idx;i++)
   {
       s=0;
       for(j=0;j<idx;j++)
       {
           if(friendship[i][j]==1)
            s++;

       }
       if(s>maxmm)
       {
         id1=i;
        maxmm=s;
       }
       if(s<minmm)
       {

       id2=i;
        minmm=s;
       }
   }
    printf("person with max frns is %s=%d\n",names[id1],maxmm);
    printf("person with minmm frns is %s=%d\n",names[id2],minmm);
}
int main()
{

    int choice;
     char str1[20],str2[20];
       FILE *fp=fopen("friendship.txt","r");
        while(!feof(fp))
        {
            //printf("in while\n");
            fscanf(fp,"%s%s",str1,str2);
            addFriend(str1,str2);

        }
fclose(fp);
    while(true)
    {

        choice = showMenu();
        switch(choice)
        {
            case 1:printf("enter names to add friendship\n");
                   scanf("%s%s",str1,str2);
                   addFriend(str1,str2);
                   break;
            case 2:listFriends();
                   break;
            case 3:mutualFriends();
                   break;
            case 4:printf("enter names to find the path between them\n");
                   scanf("%s%s",str1,str2);
                   path(str1,str2);
                   break;
            case 5:stats();
                    break;


        case 6:
            return 0; // exit(0);
        }
    }


    return 0;
}
