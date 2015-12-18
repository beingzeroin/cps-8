#include <stdio.h>
#include <stdlib.h>

int daysInMonth[14]= {0,31,28,31,30,31,30,31,31,30,31,30,31,29};
char months[14][20]=
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
	"December",
	"February"
};
char days[7][20]=
{
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
int checkLeapYear(int year)
{
    if(year%4==0&&year%100!=00)
    {
        return 1;
    }
    else if(year%100==0&&year%400==0)
    {
        return 1;
    }
    else
        return 0;
}
int determineFirstDayOfMonth(int month,int year)
{
    int check = 1,temp = 0,firstDay;
    firstDay = determineFirstDayOfYear(year);
    while(check != month)
    {
        temp = temp + daysInMonth[check];
        check++;
    }
    return ((temp%7)+ firstDay)%7 ;
}
void printcalander(int y,int m)
{
	int i,sum,check=0;
	int firstDay;
	int leapOrNot;
    leapOrNot = checkLeapYear(y);
	firstDay = determineFirstDayOfMonth(m,y);
	if(leapOrNot==1&&m>2)
    {
        firstDay++;
    }
    else if(leapOrNot==1&&m==2)
    {
        m=13;
    }
	printf("%s\t%d\n",months[m],y);
	for(i=0;i<7;i++)
	{
		printf("%s\t",days[i]);
	}
	printf("\n");
	sum = 0;

	for(i=1;i<=daysInMonth[m];)
	{
        while(sum != firstDay)
        {
            printf("   \t");
            sum++;
            check++;
        }
        if(check == 7)
        {
            check = 0;
            printf("\n");
        }
        printf("%3d\t",i++);
        check++;
    }
}

int main()
{
    int month, year;
	scanf("%d %d",&month,&year);

	printcalander(year,month);
	return 0;
}
