#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MINUS_INF -1
#define PLUS_INF 1

typedef struct{
    float x1;
    float y1;
    float x2;
    float y2;
    float r;
}lines;

void perform_swap(lines *);
float* getXElements(lines *,int);
float* sort_array(float *,int);
float getTransparencyCoefficient(lines *,int,float,float);

int main()
{
    int t;
    char ch;
    scanf("%d",&t);
    while(t){
        scanf("%c",&ch);/*Enter key*/
        int nl,np,i = 0;
        lines l[1000];
        scanf("%d",&nl);
        while(i < nl){
            scanf("%f %f %f %f %f",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2,&l[i].r);
            perform_swap(&l[i]);
            i++;
        }
        np = 2*nl + 1;
        printf("%d\n",np);
        float *arr = getXElements(l,nl);
        i = 0;
        printf("-inf %.3f %.3f\n",arr[i],1.0);
        i++;
        while(i < (np-1)){
            printf("%.3f %.3f %.3f\n",arr[i-1],arr[i],getTransparencyCoefficient(l,nl,arr[i-1],arr[i]));
            i++;
        }
        printf("%.3f +inf %.3f",arr[i-1],1.0);
        if(t > 1)
            printf("\n\n");
        t--;
    }
    return 0;
}

void perform_swap(lines *p){
    if(p->x1 > p->x2){
        float temp = p->x1;
        p->x1 = p->x2;
        p->x2 = temp;
        temp = p->y1;
        p->y1 = p->y2;
        p->y2 = temp;
    }
}
float* getXElements(lines *p,int n){
    float *a = malloc(2*n*sizeof(int));
    int i = 0, j = 0;
    while(i < n){
        a[j++] = p[i].x1;
        a[j++] = p[i].x2;
        i++;
    }
    return sort_array(a,2*n);
}
float* sort_array(float *a,int n){
    int i = 0, j = 0;
    for(i = 0;i < n-1;i++){
        for(j = i+1;j < n;j++){
            if(a[i] > a[j]){
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return a;
}
float getTransparencyCoefficient(lines *l,int n,float lower,float higher){
    int i = 0;
    float coefficient = 1.0;
    while(i < n){
        if(lower >= l[i].x1 && higher <= l[i].x2)
            coefficient *= l[i].r;
        i++;
    }
    return coefficient;
}






