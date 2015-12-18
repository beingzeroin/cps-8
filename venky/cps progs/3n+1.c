#include <stdio.h>
#include <stdlib.h>

int cycleLength(int n)
{
    int count = 1;
    while(n!=1)
    {
        if(n%2 == 0)
            n=n/2;
        else
            n=((3*n)+1);
        count++;
    }
    return count;
}

int calMaxCL()
{
    int i,a,b,temp;
    //int count1[200];
    //printf("Enter the nos:");
    while(scanf("%d %d",&a,&b)==2)
    {
        printf("%d %d",a,b);
        if(a>b)
        {
            temp = a;
            a = b;
            b = temp;
        }

        int maxCL = cycleLength(a);
        int curCL;
        for(i=a+1; i<=b; i++)
        {
            curCL  = cycleLength(i);
            if(curCL>maxCL)
                maxCL=curCL;
        }
        printf(" %d",maxCL);
    }
    return 0;
}
