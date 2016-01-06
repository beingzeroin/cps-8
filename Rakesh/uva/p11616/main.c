#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char roman[]= {'I','V','X','L','C','D','M'};
int arabic[]= {1,5,10,50,100,500,1000};
bool isRoman(char []);
void toArabic(char []);
void toRoman(char []);
int main()
{
    char a[20];
    while(scanf("%s",a)>0)
    {
        if(isRoman(a))
            toArabic(a);
        else toRoman(a);
    }
    return 0;
}
bool isRoman(char a[])
{
    int i=0;
    while(i<7)
    {
        if(a[0]==roman[i])
            return true;
        i++;
    }
    return false;
}
void toArabic(char a[])
{
    int i=0,j=0,k=0;
    int value=0;
    while(a[i]!='\0')i++;
    for( ; i>=0; i--)
    {
        for(j=0; j<7; j++)
        {
            if(a[i]==roman[j])
            {
                if(k<=j)
                    value+=arabic[j];
                else
                    value-=arabic[j];
                k=j;
            }
        }
    }
    printf("%d\n",value);
}
void toRoman(char a[])
{
    int value=0,i=0,z=0,j=6;
    for( i=0; a[i]!='\0'; i++)
    {
        value=value*10+a[i]-48;
    }
    while(j>=0)
    {
        z=value/arabic[j];
        if(z!=0)
        {
            if(z<4)
                for(i=0; i<z; i++)
                    printf("%c",roman[j]);
            else if(z==5)
                printf("%c",roman[j+1]);
            else if(z==4)
                printf("%c%c",roman[j],roman[j+1]);
            else if(z<9)
            {
                printf("%c",roman[j+1]);
                for(i=0; i<z-5; i++)
                    printf("%c",roman[j]);
            }
            else if(z==9)
                printf("%c%c",roman[j],roman[j+2]);
        }
        value-=z*arabic[j];
        j=j-2;
    }
    printf("\n");
}
