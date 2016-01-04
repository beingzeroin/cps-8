#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t=0,n=0,m=0;
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d %d",&n,&m);
        printf("%d\n",(n/3) * (m/3));
        t--;
    }
    return 0;
}

