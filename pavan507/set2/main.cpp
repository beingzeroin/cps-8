#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t,c,flag=0,i;
	cin>>t;
	int a[27];
	char s[10000000];
	while(t--)
	{
	    flag=0;
	    for(i=0;i<27;i++)
            a[i]=0;
		cin>>s;
		for(i=0;s[i]!='\0';i++)
		{
			c=s[i]-'a';
			a[c]++;
		}
		for(i=0;i<27;i++)
		{
            if(a[i]%2!=0)
            {
                flag++;

            }
	}
	if(flag>1)
	cout<<"False\n";
	else
        cout<<"True\n";

}
return 0;
}
