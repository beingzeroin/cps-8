#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,k,i,j,m;
    //char article[15000][10000];
    char paidchar[100][2];
    scanf("%d",&n);
    char c;
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        for(j=0;j<k;j++)
            scanf("%c %c",&paidchar[j][0],&paidchar[j][1]);
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%s",c);

            // Process c and calculate it's count
        }

    }
    return 0;
}
