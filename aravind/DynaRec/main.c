#include <stdio.h>
#include <stdlib.h>
long long dp[1000];
int arraywinePrices[5];
int totalYears = 5;
int Max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
int profit(int start, int end)
{
    int yearsleft = end - start;
    int yearspassed = totalYears - yearsleft;
    if(yearsleft<0)
    {
        return 0;
    }
    if(dp[start][end]==-1)
        dp[start][end] = Max(yearspassed*arraywinePrices[start]+(profit(start+1,end)), yearspassed*arraywinePrices[end]+(profit(start,end-1)));
    return dp[start][end];
}
long long rec(int n)
{
    if(n<0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==4)
        return 6;
    if(dp[n]<0)
        dp[n] = (rec(n-1)+rec(n-2)+rec(n-4));
    return dp[n];
}
int main()
{
    int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            dp[i][j] = -1;
    arraywinePrices[0]=3;
    arraywinePrices[1]=4;
    arraywinePrices[2]=2;
    arraywinePrices[3]=1;
    arraywinePrices[4]=5;
    printf("%d ",profit(0,4));
    return 0;
    /*
    int i;
    int n;
    for(i=0;i<1000;i++)
    {
        dp[i]= -1;
    }
    scanf("%d",&n);
    printf("%lld",rec(n));
    return 0;
    */

}
