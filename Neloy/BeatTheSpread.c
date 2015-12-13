#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x,y,a,b;
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%d %d",&a,&b);
        if(a<b)
        {
            printf("impossible");
        }
        else if((a+b)%2!=0)
        {
            printf("impossible");
        }

        else{
        x=(a+b)/2;
        y=a-x;
        if(x>=0 && y>=0 )
        {
            if(x>y)
                printf("%d %d",x,y);
            else
                printf("%d %d",y,x);
        }
        else
            printf("impossible");
        }
        n--;
        printf("\n");
    }
    return 0;
}
