#include<stdio.h>
int main()
{
    int a[10][10],m,n;
    scanf("%d %d",&m,&n);
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    int r1=0,r2=m-1,c1=0,c2=n-1;
    int count=0;
    while(1)
    {
        for(i=r1,j=c1;j<=c2-1;j++)
        {
            printf("% d",a[i][j]);
            count++;
        }
        if(count==m*n)
            break;
        for(i=r1,j=c2;i<=r2-1;i++)
        {
            printf("% d",a[i][j]);
            count++;
        }
        if(count==m*n)
            break;
        for(i=r2,j=c2;j>=c1+1;j--)
        {
            printf("% d",a[i][j]);
            count++;
        }
        if(count==m*n)
            break;
        for(i=r2,j=c1;i>=r1+1;i--)
        {
            printf("% d",a[i][j]);
            count++;
        }
        if(count==m*n)
            break;
        c1++;
        c2--;
        r1++;
        r2--;
    }
    return 0;
}
