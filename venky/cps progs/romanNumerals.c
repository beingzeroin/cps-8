#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void romanToArabic(int l,char a[100])
{
    int i;
    /* if( ( (a[i]=='I') && (a[i+1]=='I') && (a[i+2]=='I')) || ((a[i]=='X') && (a[i+1]=='X') && (a[i+2]=='X')) || ((a[i]=='C') && (a[i+1]=='C') && (a[i+2]=='C')) || ((a[i]=='M') && (a[i+1]=='M') && (a[i+2]=='M')) || ((a[i]=='V') && (a[i+1]=='V')) || ((a[i]=='L') && (a[i+1]=='L')) || ((a[i]=='D') && (a[i+1]=='D')) )
     {
         printf("The given numeral cannot be converted to arabic number:");
         //exit (0);
     }*/
    //else
    //{
    for(i=0; i<l; i++)
    {
        if(a[i]=='I')
            a[i]=1;
        else if(a[i]=='V')
            a[i]=5;
        else if(a[i]=='X')
            a[i]=10;
        else if(a[i]=='L')
            a[i]=50;
        else if(a[i]=='C')
            a[i]=100;
        else if(a[i]=='D')
            a[i]=500;
        else if(a[i]=='M')
            a[i]=1000;
        else
        {
            printf("\nPlease enter correct a numeral.");
            getch();
            exit
            (0);
        }
    }
    int k;
    k=a[l-1];
    for(i=l-1; i>0; i--)
    {
        if(a[i]>a[i-1])
            k=k-a[i-1];
        else if(a[i]==a[i-1] || a[i]<a[i-1])
            k=k+a[i-1];
    }
    printf("\nEquivalent Decimal Number is %d ",k);
    //}
    //printf("Roman numbers:");
}

void arabicToRoman(int d)
{
    printf("integers");
}

int numberConversion()
{
    int i=0,count=0,count1=0;
    char a[100];
    printf("Enter the characters:");
    gets(a);
    int l = strlen(a);
    if((a[i] == 'I') || (a[i] == 'V') || (a[i] == 'X') || (a[i] == 'L') || (a[i] == 'C') || (a[i] == 'D') || (a[i] == 'M'))
    {
        while((a[i] == 'I') || (a[i] == 'V') || (a[i] == 'X') || (a[i] == 'L') || (a[i] == 'C') || (a[i] == 'D') || (a[i] == 'M'))
        {
            i++;
            count++;
        }
    }
    else
    {
        int decimal = atoi(a);
        if(decimal>=1 && decimal<=4000)
        {
            arabicToRoman(decimal);
        }
    }

    if(count==l)
        romanToArabic(l,a);

    return 0;
}
