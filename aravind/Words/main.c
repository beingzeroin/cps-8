#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void input()
{
    char a[500],c;
    int i = 0,j = 0,k,n;
    while((c=getchar())!=EOF)
    {
        if(c=='\n'||c=='\t'||c==' ')
        {
            a[i]='\0';
            n = strlen(a);
            for(k=(n-1);k>=0; k--)
            {
                printf("%c",a[k]);
            }
            i=0;
            putchar(c);
        }
        else
        {
            a[i++]=c;
        }

    }
}
int main()
{
    input();
    return 0;
}
