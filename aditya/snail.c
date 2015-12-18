#include <stdio.h>
#include <stdbool.h>

int main()
{
    double h, u, d, f;
    while(true){
        scanf("%lf %lf %lf %lf",&h,&u,&d,&f);
        if(h == 0)
            break;
        double fatigue = (f/100)*u, distance = 0;
        int day = 0;
        while(distance <= h){
            distance += u;
            day++;
            if(distance > h)
                break;
            distance -= d;
            if((u-fatigue) >= 0)
                u -= fatigue;
            if(distance < 0){
                printf("failure on day %d\n",day);
                break;
            }
        }
        if(distance > h)
            printf("success on day %d\n",day);
    }
    return 0;
}
