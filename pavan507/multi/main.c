#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fo=fopen("C:\\Users\\Welcome\\Desktop\\cps-8\\Sandeep\\TEST1.txt","r");
    do
    {

        fscanf(fo,"%d %d",&m,&n);
        if(m==0&&n==0)
            break;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                fscanf(fo,"%d",a[i][j]);

        }
        l=m;
        k=n;
        for(i=0.j=0;j<m,i>=0;j++)
        {
            if(j==l)
            {
                j--;
                while(i<k)
                {
                i++;
                printf("%d ",a[i][j]);
                }
                l--;
                k--;
            }
            if(i==n)
            {
                i--;
                while(i>k)

            }

        }

    }
    return 0;
}
