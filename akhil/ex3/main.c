#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,a[100][100],r,c;

    printf("enter rows and columns\n");
    scanf("%d%d",&r,&c);

    for(i=0;i<r;i++)
    {
         printf("\n");
        for(j=0;j<c;j++)
        {
            printf(" %d",a[i][j]);

        }

    }
    return 0;
}
