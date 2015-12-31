#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    long long sum,diff;
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%lli %lli",&sum,&diff);
        if(sum<diff)printf("impossible\n");
        else
            printf("%lld %lld\n",(sum+diff)/2,(sum-diff)/2);
        n--;
    }
    return 0;
}
