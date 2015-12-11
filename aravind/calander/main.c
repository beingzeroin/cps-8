#include <stdio.h>
#include <stdlib.h>

int daysInMonth[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
char months[13][20]=
{
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
char days[8][20]=
{
	"",
	"Sun",
	"Mon",
	"Tue",
	"Wed",
	"Thu",
	"Fri",
	"Sat"
};
int determineFirstDayOfYear(int year)
{
int d1, d2, d3;
d1 = (year - 1.)/ 4.0;
d2 = (year - 1.)/ 100.;
d3 = (year - 1.)/ 400.;
return (year + d1 - d2 + d3) %7;
}
int determineFirstDayOfMonth(int month)
{

}
void printcalander(int y,int m,int space)
{
	int i,j;
	printf("%s\t%d\n",months[m],y);
	for(i=0;i<7;i++)
	{
		printf("%s\t",days[i+1]);
	}
	printf("\n");
	for(i=1;i<=daysInMonth[m];)
	{
		for(j=space;j<7;j++)
		{
			printf("%3d\t",i++);
		}
		printf("\n");
		space = 0;
	}
}

int main()
{
    int month, year;
	scanf("%d %d",month,year);
	printcalander(2015,2);
	return 0;
}
