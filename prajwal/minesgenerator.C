#include<stdio.h>
#include<conio.h>
#include<time.h>
int **print(int m,int n,int mines,int a[100][100])
{
int i,j,k,s;

srand(time(NULL));
for(i=1;i<=mines;i++)
{
j=rand()%(m)+1;
k=rand()%(m)+1;
printf("the generated random nos are: %d %d\n",j,k);
if(a[j][k]==1)
{
i--;
}
else
{
a[j][k]=1;
}
}
for(i=1;i<=m;i++)
{
printf("\n");
for(s=1;s<=n;s++)
{
printf("%d ",a[i][s]);
}
}
return a;
}
void neighbourcalculator(int m,int n,int c[100][100])
{
int i,j,b[100][100],count=0;
for(i=0;i<m+2;i++)
for(j=0;j<n+2;j++)
b[i][j]=0;
for(i=1;i<=m;i++)
{
printf("\n");
for(j=1;j<=n;j++)
{
b[i][j]=c[i][j];

 }
}
for(i=0;i<m+2;i++)
{
printf("\n");
for(j=0;j<n+2;j++)
{
printf("%d ",b[i][j]);
}
}
printf("\n");
for(i=1;i<=m;i++)
{
for(j=1;j<=n;j++)
{
count=0;
if(b[i][j]==1)
{
c[i][j]=9;
}
else
{
if(b[i][j-1]!=0)
{
count++;
}
if(b[i][j+1]!=0)
{
count++;
}
if(b[i+1][j]!=0)
{
count++;
}
if(b[i-1][j]!=0)
{
count++;
}
if(b[i-1][j-1]!=0)
{
count++;
}
if(b[i+1][j+1]!=0)
{
count++;
}
if(b[i-1][j+1]!=0)
{
count++;
}
if(b[i+1][j-1]!=0)
{
count++;
}
c[i][j]=count;
}
}
}
for(i=1;i<=m;i++)
{
printf("\n");
for(j=1;j<=n;j++)
{
printf("%d ",c[i][j]);
}
}
}
int main()
{
int m,n,mines,a[100][100],i,s,c[100][100];
clrscr();
printf("enter the size of the board-rows and columns: ");
scanf("%d %d",&m,&n);
printf("enter the no of mines: ");
scanf("%d",&mines);
for(i=1;i<=m;i++)
for(s=1;s<=n;s++)
a[i][s]=0;
**c=print(m,n,mines,a);
neighbourcalculator(m,n,a);
getch();
return 0;
}
