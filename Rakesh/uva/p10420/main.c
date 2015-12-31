#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct countries CL;
int totallines=0;
struct countries
{
    char cname[75];
    int count;
};
CL* list[2000];
int getIndex(char* c)
{
    int i;
    for(i=0; i<totallines; i++)
    {
        if(strcmp(list[i]->cname,c)==0)
            return i;
    }
    return -1;
}
void sort()
{
    int i,j,k;
    char c[75];
    for(i=0; i<totallines; i++)
        for(j=i+1; j<totallines; j++)
        {
            if(strcmp(list[i]->cname,list[j]->cname)>0)
            {
                strcpy(c,list[i]->cname);
                strcpy(list[i]->cname,list[j]->cname);
                strcpy(list[j]->cname,c);
                k=list[i]->count;
                list[i]->count=list[j]->count;
                list[j]->count=k;
            }
        }
}
int main()
{
    int n=0,i=0,j=0,index;
    char line[75];
    char cn[75];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        fflush(stdin);
        gets(line);
        sscanf(line,"%s",cn);
        index=getIndex(cn);
        if(index!=-1)
            (list[index]->count)++;
        else
        {
            list[j]= malloc(sizeof(CL));
            strcpy(list[j]->cname,cn);
            list[j]->count=1;
            j++;
            totallines=j;
        }
    }
    sort();
    for(i=0;i<totallines;i++)
        printf("%s %d\n",list[i]->cname,list[i]->count);
    return 0;
}

