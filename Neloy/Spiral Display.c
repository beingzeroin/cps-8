#include <stdio.h>
#include <stdlib.h>

int main()
{
//    FILE *fp = fopen("input.txt","r");
    int i,j,m[5][5],ru,cu,rl=0,cl=0;
  /*  char c;
    ru=0;
    cu=0;
    while(!feof(fp))
    {
        fscanf(fp,"%c",&c);
        if(c=='\n')
        {
            ru++;
            cu=0;
            continue;
        }
        m[ru][cu]=(c-48);
        printf("%d %d%d\n",m[ru][cu],ru,cu);
        cu++;
    }
*/
    scanf("%d %d",&ru,&cu);
    for(i=0;i<ru;i++)
    {
        for(j=0;j<cu;j++)
            scanf("%d",&m[i][j]);
    }
    ru--; cu--;
    while(rl<=ru && cl<=cu)
    {
        for(i=cl;i<=cu;i++)
            printf("%d ",m[rl][i]);
        if(rl==ru)
            break;
        for(i=rl+1;i<=ru;i++)
            printf("%d ",m[i][cu]);
        if(cl==cu)
            break;
        for(i=cu-1;i>=cl;i--)
            printf("%d ",m[ru][i]);
        for(i=ru-1;i>=rl+1;i--)
            printf("%d ",m[i][cl]);
        rl++; ru--;
        cl++; cu--;
    }

    return 0;
}
