#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%ld ", time(NULL));
    srand(time(NULL));
    int i;
    for(i=1;i<=10;i++)
    {
        printf("%d ", rand());
    }

    return 0;
}
