#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int stoi(char str[])
{
    int i=0,str2[20],nFlag=0;
    while(1)
    {
        if(str[i]==' ' || str[i]=='0')
            i++;
        else if(str[i]=='-')
        {
            nFlag=1;
            i++;
        }
        else if(str[i]>'0' && str[i]<='9')
            break;
    }
    int len=0;
    while(1)
    {
        if(str[i]==' ' || str[i]=='\0')
            break;
        else
        {
            str2[len]=str[i];
            i++;
            len++;
        }
    }
    int num=0;
    i=0;
    while(len>0)
    {
        num=num+((int)(str2[i]-48)*pow(10,len-1));
        len--;
        i++;
    }
    num++;
    if(nFlag==1)
        num=(-num);
    return num;
}
int main(int argc,char * argv[])
{
    int i;
    for(i=1;i<argc;i++)
        printf("%d\n",stoi(argv[i]));
    return 0;
}
