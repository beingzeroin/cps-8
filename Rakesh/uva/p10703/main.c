#include <stdio.h>
#include <stdlib.h>
int a[500][500],i,j;
void markSub(int,int,int,int);
int main()
{
    int W=0,H=0,N=0,X1=0,Y1=0,X2=0,Y2=0,totalpos=0,subpos=0,i=0,j=0;
    while(1)
    {
        for(i=0; i<500; i++)
            for(j=0; j<500; j++)
                a[i][j]=0;
        scanf("%d %d %d",&W,&H,&N);
        if(W==0 && H==0 && N==0) break;
        totalpos=W*H;
        while(N>0)
        {
            scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
            if(X1>=X2 && Y1>=Y2) markSub(X1-1,Y1-1,X2-1,Y2-1);
            else if(X1<=X2 && Y1>=Y2) markSub(X2-1,Y1-1,X1-1,Y2-1);
            else if(X1>=X2 && Y1<=Y2) markSub(X1-1,Y2-1,X2-1,Y1-1);
            else if(X1<=X2 && Y1<=Y2) markSub(X2-1,Y2-1,X1-1,Y1-1);
            N--;
        }
        for(i=0; i<W; i++)
            for(j=0; j<H; j++)
            {
                if(a[i][j]==1)
                    subpos+=1;
            }
        if(totalpos-subpos==0)
            printf("There is no empty spots.\n");
        else if(totalpos-subpos==1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n",totalpos-subpos);
        totalpos=0;
        subpos=0;
    }
    return 0;
}
void markSub(int X1,int Y1,int X2,int Y2)
{
    for(i=X2; X1>=i; i++)
        for(j=Y2; Y1>=j; j++)
            a[i][j]=1;
}
