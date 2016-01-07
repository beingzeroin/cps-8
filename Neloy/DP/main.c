#include <stdio.h>
#include <stdlib.h>

long long table[1000];

int rec(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==4)
        return 6;
    if(n<0)
        return 0;
    if(table[n-1]==-1)
        table[n-1]=rec(n-1);
    if(table[n-2]==-1)
        table[n-2]=rec(n-2);
    if(table[n-4]==-1)
        table[n-4]=rec(n-4);
    if(table[n]<0)
        table[n] = table[n-1]+table[n-2]+table[n-4];
    return table[n];
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld\n",rec(n));
}
