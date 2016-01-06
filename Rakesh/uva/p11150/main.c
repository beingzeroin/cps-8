#include <stdio.h>
#include <stdlib.h>
int emptybottles(int);
int count=0;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",n+emptybottles(n));
        count=0;
    }
    return 0;
}
int emptybottles(int n)
{
    if(n!=2){
    int exchange=n/3;
    int remaining=n%3;
    if(exchange!=0)
        return exchange+emptybottles(exchange+remaining);
    else return 0;}
    else return 1;
}
