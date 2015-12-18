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
int isleap(int year)
{
	if(((year%4==0)&&(year%100!=0))||(year%400==0))
	return 1;
	else
	return 0;
}
int determineFirstDayOfYear(int year)
{
    int d1, d2, d3;
    d1 = (year - 1.)/ 4.0;
    d2 = (year - 1.)/ 100.;
    d3 = (year - 1.)/ 400.;
    return (year + d1 - d2 + d3) %7;
}
void printCalender(int year,int month)
{
    int day,c=0,k,i;
    printf("%s  %d\n",months[month],year);
    printf("sun mon tue wed thu fri sat\n");
    day=determineFirstDayOfYear(year);
    if(isleap(year))
    daysInMonth[2]=29;
    else
    daysInMonth[2]=28;
    
    for(i=0;i<month;i++)
    day+=daysInMonth[i];
    day%=7;
  //  printf("%d",day);
    while(day>0)
    {
day--;
    c++;
        printf("    ");
    }
    k=daysInMonth[month];
    for(i=1;i<=k;i++)
    {
        if(c%7==0)
        {
            c=1;
            printf("\n");
            printf("%2d  ",i);

        }
        else
        {
            printf("%2d  ",i);
            c++;

        }


    }
}
int main()
{
	int year,month;
	printf("enter year and month\n");
	scanf("%d %d",&year,&month);
    printCalender(year,month);
    return 0;
}

