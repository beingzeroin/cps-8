#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,j=0,k;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d",&j);
        k=((315*j+36962)/10)%10;
        k>0?printf("%d\n",k):printf("%d\n",-k);
        t--;
    }
    return 0;
}
