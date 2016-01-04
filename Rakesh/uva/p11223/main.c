#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t=0,i;
    char input[2000];
    scanf("%i",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s",input);
        printf("Message #%i\n",i);
    }
    return 0;
}

