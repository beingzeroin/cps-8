#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wordScramble()
{
    char s[100],s2[100];
    int i=0,j=0;
    printf("Enter the strings:\n");
    while(gets(s))
    {
        i=0;j=0;
        while(s[i] != '\0')
        {
            if(s[i] != ' ')
            {
                s2[j] = s[i];
                j++;
            }
            else
            {
                s2[j]='\0';
                printf("%s ",strrev(s2));
                j=0;
            }
            i++;
        }

        s2[j] = '\0';
        printf("%s ",strrev(s2));
        printf("\n");
        //s2[100] = '\0';
    }
}
