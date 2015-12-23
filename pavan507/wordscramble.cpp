
#include<stdio.h>
#include<string.h>
char s[300];
//using namespace std;
void rev()
{
	int l=strlen(s),n,j;
	l-=1;
	n=l;
	char str[300];
	for(j=0;j<=n;j++)
	{
		str[j]=s[l];
		l--;
	}
str[j]='\0';
	strcpy(s,str);
}
int main()
{
	char c;
	int i=0,n;
	while((n=getchar())!=-1)
	{
	
		c= n;

		if((c!=' ')&&(c!='\t')&&(c!='\n'))
		{
			s[i]=c;
			i++;
		}
		else if((c==' ')||(c=='\t')||(c=='\n'))
		{
		
		    if(strcmp(s," ")==0)
		    printf("%c",c);
		    else
		    {
			
			s[i]='\0';
			rev();
			printf("%s%c",s,c);
			i=0;
			strcpy(s," ");
	        }
		
	}
}
	return 0;
}
