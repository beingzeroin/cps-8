#include <iostream>

using namespace std;
int m,n,flag=0,visited[20][20];
char a[20][20];
int isValid(int r,int c)
{
   // cout<<r<<" " <<c<<"     in isvalid\n";
    if(r>=0&&r<m&&c>=0&&c<n)
    {

      // cout<<"is valid\n";
        return 1;
    }
    else
    {

   // cout<<"not valid\n";
        return 0;
    }

}
void findRoot(int i,int j)
{
    if(a[i][j]=='X')
    {
        flag=1;
        return;

    }
    visited[i][j]=1;
    int r,c;
    if(isValid(i-1,j)&&a[i-1][j]!='1'&&!visited[i-1][j])
    {
        findRoot(i-1,j);
    }
    if(isValid(i,j-1)&&a[i][j-1]!='1'&&!visited[i][j-1])
    {
        findRoot(i,j-1);
    }
    if(isValid(i,j+1)&&a[i][j+1]!='1'&&!visited[i][j+1])
    {
        findRoot(i,j+1);

    }
    if(isValid(i+1,j)&&a[i+1][j]!='1'&&!visited[i+1][j])
    {
        findRoot(i+1,j);
    }



}

int main()
{
    int i,j,k,t,p,r;
    cin>>t;
    while(t--)
    {
        flag=0;

        cin>>m;
        n=m;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='A')
                {
                    p=i;
                    r=j;

                }
                visited[i][j]=0;
            }
        }
         cout<<p<<endl<<r<<endl;
        findRoot(p,r);
        if(flag==1)
            cout<<"True\n";
        else
            cout<<"False\n";
    }
    return 0;
}
