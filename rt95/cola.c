#include<stdio.h>

int main()
{
    int n,r,b=1,e=0,c=0;
    printf("Enter the number of bottles purchased\n");
    scanf("%d",&n);
    while(n/3!=0)
    {
        r=n%3;
        n=n/3;
        e+=3*n;
        n=n+r;
        if(n%3==2&&c==0)
        {
            n+=b;
            c=1;
        }
    }
    if(n/3==0&&c==0)
        e+=1;
    printf("Max: %d\n",e);
    if(c==1)
        printf("Empty bottle borrowed");

}
