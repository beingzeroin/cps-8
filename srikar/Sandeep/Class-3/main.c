#include <stdio.h>
#include <stdlib.h>
#include<time.h>


int main()
{
    //printf("%ld ", time(NULL));
    srand(time(NULL));
    int i,m,n,j,l,k,c=0,a[100][100];
    //k=rand()%2;
   // printf("%d\n",c);
    printf("enter rows columns and num of 1's\n");
    scanf("%d%d%d",&m,&n,&l);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
           k=rand()%2;
           a[i][j]=k;
           if(k==1)
            c++;
           if(c==l)
            break;

        }
        if(c==l)
            break;
        //printf("%d ", rand());
    }
    for(i+=1;i<=m;i++)
    {

        for(j+=1;j<=n;j++)
            a[i][j]=0;
    }
    for(i=1;i<=m;i++)
    {

        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    return 0;
}
