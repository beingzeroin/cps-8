#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n=0,i=0;
    scanf("%d",&n);
     int a[n];
    while (scanf("%d",&a[i]) == 1){i++; if(i==n)break;};
    for(i=0;i<n;i++)
    {
        if(a[i]==-3)
        printf(".");
        else if(a[i]==-2)
           printf(" ");
        else if(a[i]==-1)
             printf("\n");
        else printf("%c",a[i]+97);
    }

    return 0;
}
