#include<stdio.h>
int getSonarCount(int r,int c)
{
    int i=1,j=1,count=0;
	for(i=1;i<r-2;i=i+3)
		for(j=1;j<c-2;j=j+3)
			count++;
	if(r%3==0 && c%3!=0)
	{
        if(c%3==2)
			count+=((c-2)/3);
		else if(c%3==1)
			count+=((c-1)/3);
	}
	else if(r%3!=0 && c%3==0)
	{
        if(r%3==2)
			count+=((r-2)/3);
		else if(r%3==1)
			count+=((r-1)/3);
	}
    else if(r%3==0 && c%3==0)
		count+=((r-3)/3 + (c-3)/3 + 1);
	return count;
}
int main()
{
	int i,n,r,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&r,&c);
		printf("%d\n",getSonarCount(r,c));
	}
	return 0;
}