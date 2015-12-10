#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char a[20],c;

void input()
{
    int i = 0;
    while((c=getchar())!=EOF)
    {
        if(strcmp(a,""))
        {
            strrev(a);
            printf("%s",a);
        }
        if(c=='\n'||c=='\t'||c==' ')
        {
            i=0;
            printf("%c",c);
        }
        else
        {
            a[i++]=c;
        }
        a[i]='\0';
    }
}
int main()
{
    input();
    return 0;
}
