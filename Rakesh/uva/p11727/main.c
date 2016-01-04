#include <stdio.h>
#include <stdlib.h>
int survives(int,int,int);
int main()
{
    int n=0,i=0,a=0,b=0,c=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        printf("Case %d: %d\n",i,survives(a,b,c));
    }
    return 0;
}
int survives(int a,int b,int c)
{
    if((a>b && a<c) || (a>c && a<b) || (a==b && a<c))return a;
    if((b>a && b<c) || (b>c && b<a) || (b==a && b<c))return b;
    return c;
}
