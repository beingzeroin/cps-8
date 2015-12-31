#include <stdio.h>
#include <stdlib.h>
int cycleLength=0;
int maxCycleLength=0;
void generateSeries(unsigned int);
void calculateMaxCycleLength(unsigned int,unsigned int);
int main()
{
    unsigned int i,j;
    while(scanf("%d %d",&i,&j)==2)
    {
        if(i<j)
            calculateMaxCycleLength(i,j);
        else calculateMaxCycleLength(j,i);
        printf("%d %d %d\n",i,j,maxCycleLength);
        maxCycleLength=0;
    }
    return 0;
}
void calculateMaxCycleLength(unsigned int i,unsigned int j)
{
    unsigned int k;
    for( k=i; k<=j; k++)
    {
        generateSeries(k);
        if(cycleLength>maxCycleLength)
            maxCycleLength=cycleLength;
        cycleLength=0;
    }
}
void generateSeries(unsigned int n)
{
    while(n!=1)
    {
        if(n%2==0)
        {
            n=n/2;
            cycleLength++;
        }
        else
        {
            n=3*n+1;
            cycleLength++;
        }
    }
    cycleLength++;
}
