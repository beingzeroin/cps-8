#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int toDecimal(char *s,int l)
{
    int num=0,i=0;
    while(l>0)
    {
        num=num+((int)(s[i]-48)*pow(10,l-1));
        l--;
        i++;
    }
    return num;
}

char* decimalToRoman(char *s)
{
    int dec = atoi(s);

    int i=0;
    while(dec>0)
    {
        if(dec>=1000)
        {
            s[i++]='M';
            dec=dec-1000;
        }
        else if(dec>=900)
        {
            s[i++]='C';
            s[i++]='M';
            dec=dec-900;
        }
        else if(dec>=500)
        {
            s[i++]='D';
            dec=dec-500;
        }
        else if(dec>=400)
        {
            s[i++]='C';
            s[i++]='D';
            dec=dec-400;
        }
        else if(dec>=100)
        {
            s[i++]='C';
            dec=dec-100;
        }
        else if(dec>=90)
        {
            s[i++]='X';
            s[i++]='C';
            dec=dec-90;
        }
        else if(dec>=50)
        {
            s[i++]='L';
            dec=dec-50;
        }
        else if(dec>=40)
        {
            s[i++]='X';
            s[i++]='L';
            dec=dec-40;
        }
        else if(dec>=10)
        {
            s[i++]='X';
            dec=dec-10;
        }
        else if(dec>=9)
        {
            s[i++]='I';
            s[i++]='X';
            dec=dec-9;
        }
        else if(dec>=5)
        {
            s[i++]='V';
            dec=dec-5;
        }
        else if(dec>=4)
        {
            s[i++]='I';
            s[i++]='V';
            dec=dec-4;
        }
        else
        {
            s[i++]='I';
            dec--;
        }
    }
    s[i]='\0';
return s;
}

int main()
{
    int num[200];
    num['\0']=0;
    num['I']=1;
    num['V']=5;
    num['X']=10;
    num['L']=50;
    num['C']=100;
    num['D']=500;
    num['M']=1000;
    char s[100];
    int i=0,sum=0;
    while(gets(s))
    {
        if(s[0]>=48 && s[0]<=57)
        {
            printf("%s\n",decimalToRoman(s));
        }
        else
        {
            while(s[i]!='\0')
            {
                if(num[s[i]]>=num[s[i+1]])
                    sum=sum+(num[(int)s[i]]);
                else
                    sum=sum-(num[(int)s[i]]);
                i++;
            }
            printf("%d\n",sum);
            sum=0;
        }
        i=0;
    }
    return 0;
}
