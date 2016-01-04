#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char input[10000],ch;
int k=0;
void reversePattern(int);
int main()
{
    int i=0;
    while (1 == scanf("%[^\n]%*c",input))
    {
        while(input[i]!='\0')
        {
            if(input[i]==' ')
            {
                reversePattern(i-1);
                k=i+1;
            }
            i++;
        }
        reversePattern(i-1);
        i=0;k=0;
        puts(input);
    }
    return 0;
}
void reversePattern(int j)
{
    while(j>k)
    {
        ch=input[j];
        input[j]=input[k];
        input[k]=ch;
        k++;
        j--;
    }
}

