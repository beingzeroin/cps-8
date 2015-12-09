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

void printCalendar(int, int);

int main()
{
    int y,m;
    printf("Enter year, month: \n");
    scanf("%d%d",&y,&m);
    printCalendar(y,m);
    return 0;
}

void printCalendar(int year, int month)
{
    int j=1,i, flag=0, firstDay, numOfDays=0;
    printf("%s %d\n",months[month],year);

    if(year%4==0)
    {
        daysInMonth[2]++;
        flag=1;
    }

    printf("SUN MON TUE WED THU FRI SAT\n");

    firstDay = determineFirstDayOfYear(year);

    for(i=1;i<month;i++)
        numOfDays+=daysInMonth[i];
    firstDay += numOfDays;
    firstDay = (firstDay)%7;
    for(i=0;i<firstDay;i++)
        printf("    ");

    for(i=1+firstDay;i<=daysInMonth[month]+firstDay;i++)
    {
        printf("%3d ",j);
        if(i%7==0)
            printf("\n");
        j++;
    }
    if(flag==1)
    {
        daysInMonth[2]--;
    }
    printf("\n");
}
