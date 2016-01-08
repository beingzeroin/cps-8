#include <iostream>
#include<stdio.h>
using namespace std;
long long int dp[1000];
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
        if(dp[n]<0)
    dp[n]=(rec(n-1)+rec(n-2)+rec(n-4));
    else
        return dp[n];
    }
int main()
{
    int i;
    for(i=0;i<1000;i++)
        dp[i]=-1;
    printf("%ld ",rec(50));
    return 0;
}
