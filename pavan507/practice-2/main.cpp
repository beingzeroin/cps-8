#include <iostream>
#include<math.h>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main()
{
    int v=0,h=0,t,n,u;
    char c;
    float ans;
    cin>>t;
    while(t--)
    {
        v=0.0;
        h=0.0;
        cin>>n;
        while(n--)
        {
            cin>>c>>u;
            if(c=='N')
                v+=u;
            if(c=='S')
                v-=u;
            if(c=='E')
                h+=u;
            if(c=='W')
                h-=u;

        }
       // cout<<v<<endl<<u
        ans=sqrt(v*v+h*h);
        cout.setf(ios::showpoint);
        printf("%.2f\n",ans);

    }
}
