#include <stdio.h>
#include <stdlib.h>

int time(double oldTime)
{
    long temp = 0,split = 0;
    long long sum = 0;
    long newTime = 0;
    temp = oldTime;
    split = temp%100;
    temp = temp/100;
    sum = sum + split;

    split = temp%100;
    temp = temp/100;
    split = split * 100;
    sum = sum + split;

    split = temp%100;
    temp = temp/100;
    split = split * 60 * 100;
    sum = sum + split;

    split = temp%100;
    temp = temp/100;
    split = split * 60 * 60 * 100;
    sum = sum + split;

    newTime = (sum * 1000)/864;

    return newTime;
}

int main()
{
    long oTime;
    long printTime;
    while(scanf("%ld",&oTime)==1)
    {
        printTime = time(oTime);
        printf("%7ld\n",printTime);
    }
    return 0;
}
