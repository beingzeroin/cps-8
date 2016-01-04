#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,M,N,a,b;
    while(1)
    {
        scanf("%d",&k);
        if(k==0) break;
        scanf("%d %d",&M,&N);
        while(k!=0)
        {
            scanf("%d %d",&a,&b);
            if(a==M || b==N)
                printf("divisa\n");
            else if(a>M && b>N)
                printf("NE\n");
            else if(a>M && b<N)
                printf("SE\n");
            else if(a<M && b<N)
                printf("SO\n");
            else if(a<M && b>N)
                printf("NO\n");
            k--;
        }
    }
    return 0;
}
