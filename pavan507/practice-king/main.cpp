#include <iostream>

using namespace std;
char a[20][20],c;
int m,n;
int isValid(int r,int c)
{
    if(r>=0&&r<=m&&c>=0&&c<=n)
        return 1;
    else
        return 0;

}
int getCount(int i,int j)
{
    int k=0,c,r;
    for(r=i-1; r<=i+1; r++)
    {
        for(c=j-1; c<=j+1; c++)
        {
            if(isValid(r,c)&&a[r][c]=='o')
            {

                a[r][c]='s';
                k++;
            }

        }

    }
    return k;
}
int main()
{
    int t,i,j,p,s;

        s=0;
        cin>>m>>n;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
                cin>>a[i][j];

        }
        for(i=0; i<m; i++)
        {

            for(j=0; j<n; j++)
            {
                if(a[i][j]=='k')
                s+= getCount(i,j);
            }
        }

        cout<<s<<endl;

    return 0;
}
