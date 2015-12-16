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

/* Returns 0 – SUN, 1 – MON, ... , 6 – SAT */
int determineFirstDayOfYear(int year)
{
    int d1, d2, d3;
    d1 = (year - 1.)/ 4.0;
    d2 = (year - 1.)/ 100.;
    d3 = (year - 1.)/ 400.;
    return (year + d1 - d2 + d3) %7;
}

int cal(int year, int m)
{

}

int printCal()
{
    int m,year,i;
    printf("Give the month and year:\n");
    scanf("%d %d",&m,&year);
    printf("%s %d",months[m],year);
    printf("\nSUN MON TUE WED THU FRI SAT\n");
    cal(year,m);
    return 0;
}

