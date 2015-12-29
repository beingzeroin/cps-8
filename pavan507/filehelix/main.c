#include<stdio.h>
int a[100][100],count=0,rows,cols,i,j,k;
void top(int m,int n)
{
	//printf("in top\n");
	for(j=n;j<cols;j++)
	{
		if(a[m][j]!=-1)
		{

	//	printf("in top\n");
		printf("%d ",a[m][j]);
		a[m][j]=-1;
		count++;
		if(count>=k)
		break;
	}
	}

}
void right(int rm,int rn)
{
	//printf("\n in right rm=%d  rn=%d\n",rm,rn);
	for(i=rm;i<rows;i++)
	{
		if(a[i][rn]!=-1)
		{

		printf("%d ",a[i][rn]);
		a[i][rn]=-1;
		count++;
		if(count>=k)
		break;
	}
	}

}
void bottom(int m,int n)
{
	//printf("\n in bottom");
	for(j=n;j>=0;j--)
	{
		if(a[m][j]!=-1)
		{

		printf("%d ",a[m][j]);
		a[m][j]=-1;
		count++;
		if(count>=k)
		break;
	}
	}


}
void left(int m,int n)
{
	//printf("\n in left");
	for(i=m;i>=0;i--)
	{
	   // printf("\ninleft %d",i);
		if(a[i][n]>=0)
		{

		printf("%d ",a[i][n]);
		a[i][n]=-1;
		count++;
		if(count>=k)
		break;
	}
}

}
void display()
{

    int i,j;
    for(i=0;i<rows;i++)
    {

        for(j=0;j<cols;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
int main()
{
	int tm,tn,rm,rn,bm,bn,lm,ln,m,n,t;
	//printf("enter tezst cases\n");
	FILE *fo=fopen("C:\\Users\\Welcome\\Desktop\\cps-8\\Sandeep\\TEST1_PROB_2_INP.txt","r");
	fscanf(fo,"%d%d",&rows,&cols);
	printf("rows=%d  cols=%d\n",rows,cols);
	while((rows!=0)&&(cols!=0))
	{
	    count=0;
    printf("rows=%d  cols=%d\n",rows,cols);
		//printf("enter rows and columns\n");
		//scanf("%d%d",&rows,&cols);
		for(i=0;i<rows;i++)
		{
			for(j=0;j<cols;j++)
			fscanf(fo,"%d",&a[i][j]);
		}
		display();
			tm=0;tn=0;rm=0;rn=cols-1;bm=rows-1;bn=cols-1;lm=rows-1;ln=0;
			//printf("in main rn=%d\n",rn);
		k=rows*cols;

		while(count!=k)
		{
			//printf("in while\n");
			//printf("\n tm=%d tn=%d\n",tm,tn);
		top(tm,tn);
		if(count>=k)
		break;
		//printf("\n rm=%d rn=%d\n",rm,rn);
		right(rm,rn);
		if(count>=k)
		break;
		//printf("\n bm=%d bn=%d\n",bm,bn);
		bottom(bm,bn);
		if(count>=k)
		break;
		//printf("\n lm=%d ln=%d\n",lm,ln);
		//display();
		left(lm,ln);
		if(count>=k)
		break;
		//display();
		tm++;tn++;rm++;rn--;bm--;bn--;lm--;ln++;
		}
		fscanf(fo,"%d%d",&rows,&cols);
		printf("\n");
	}
	fclose(fo);
	return 0;
}
