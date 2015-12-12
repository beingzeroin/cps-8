#include<stdio.h>
void getScores(long total,long diff)
{
    long a,b;
    if(total<diff)
        printf("impossible");
    else
    {
        a=total+diff;
        b=total-diff;
        if(a%2!=0 || b%2!=0)
            printf("impossible");
        else
            printf("%ld %ld",a/2,b/2);
    }
    printf("\n");
}
int main()
{
    long total,diff;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld %ld",&total,&diff);
        getScores(total,diff);
    }
    return 0;
}