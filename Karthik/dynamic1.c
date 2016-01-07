#include<stdio.h>
int dp[1000];
int rec(int n)
{
    if(n<0)
        return 0;
    if(n=1)
        return 1;
    if(n==2)
        return 2;
    if(n==4)
        return 4;
    dp[n-1]=rec(n-1);
    dp[n-2]=rec(n-2);
    dp[n-4]=rec(n-4);
    dp[n]=dp[n-1]+dp[n-2]+dp[n-4];
    return dp[n];
}

int main()
{
    int i;
    for(i=0;i<1000;i++)
        dp[i]=-1;
    int n;
    scanf("%d",&n);
    printf("%d",rec(n));
}
