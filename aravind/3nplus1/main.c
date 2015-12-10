#include <stdio.h>
#include <stdlib.h>

void cyclelength(int num)
{
    int n=1;
    while(num!=1)
    {
       if(num%2==0)
       {
           num = num/2;
           n++;
       }
       else
       {
           num = 3*num + 1;
           n++;
       }
    }
    return n;
}

int main()
{
    int max,current=0;
    int a,b,temp=0;

    while(scanf("%d %d",&a,&b)==2)
    {
        max=0;
        printf("%d %d ",a,b);
        if(a>b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        for(i=a;i<=b;i++)
        {
            current = cyclelength(i);
            if(current>max)
            {
                max=current;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
