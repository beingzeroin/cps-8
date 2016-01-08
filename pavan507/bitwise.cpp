#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long long int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		while(n>0)
		{
			if(!(n&(n-1)))
			{
				printf("%d\n",n);
				break;
				
			}
			n--;
		}
	}
	return 0;
}
