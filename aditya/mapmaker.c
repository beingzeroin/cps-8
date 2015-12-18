#include <stdio.h>
#include <string.h>

typedef struct{
    char name[11];
    int base_addr;
    int size;
    int dimensions;
    int dimension_bounds[10][2];
} myArray;
typedef struct{
    char name[11];
    int no_of_dim;
    int dimensions[10];
} arrayRef;

int getDimensions(myArray*,int,char*);
void printInput(myArray*,int,arrayRef*,int);
void computePhysicalAddress(myArray*,int,arrayRef);
int getCZero(myArray,arrayRef);
int getOtherCs(myArray,arrayRef,int);
int getCLs(myArray,arrayRef,int);
int getCs(myArray,arrayRef,int);

int main()
{
    myArray a[1000];
    arrayRef arr[1000];
    int n, r, i = 0, j, no_of_dimensions, k = 0, temp = 0;
    scanf("%d %d",&n,&r);
    j = n;
    while(j--){
        fflush(stdin);
        scanf("%s %d %d %d",a[i].name,&a[i].base_addr,&a[i].size,&a[i].dimensions);
        no_of_dimensions = 0;
        while(no_of_dimensions < a[i].dimensions){
            scanf("%d %d",&a[i].dimension_bounds[no_of_dimensions][0],&a[i].dimension_bounds[no_of_dimensions][1]);
            no_of_dimensions++;
        }
        i++;
    }
    j = r;
    while(j--){
        fflush(stdin);
        scanf("%s",arr[k].name);
        arr[k].no_of_dim = getDimensions(a,i,arr[k].name);
        temp = 0;
        while(temp < arr[k].no_of_dim){
            scanf("%d",&arr[k].dimensions[temp]);
            temp++;
        }
        k++;
    }
    j = 0;
    while(j < r){
        printf("%s[",arr[j].name);
        temp = 0;
        while(temp < arr[j].no_of_dim - 1){
            printf("%d, ",arr[j].dimensions[temp]);
            temp++;
        }
        printf("%d] = ",arr[j].dimensions[temp]);
        computePhysicalAddress(a,i,arr[j]);
        printf("\n");
        j++;
    }
    //printInput(a,i,arr,k);
    return 0;
}
void computePhysicalAddress(myArray *p,int size,arrayRef some_array){
    int addr = 0, i = 0;
    while(i < size){
        if(strcmp(p[i].name,some_array.name) == 0)
            break;
        i++;
    }
    addr += getCZero(p[i],some_array);
    addr += getOtherCs(p[i],some_array,1);
    printf("%d",addr);
}
int getCZero(myArray a,arrayRef some_array){
    int base = a.base_addr;
    int temp = getCLs(a,some_array,1);
    return base - temp;
}
int getOtherCs(myArray a,arrayRef some_array,int n){
    if(n == some_array.no_of_dim)
        return a.size*some_array.dimensions[n-1];
    return getCs(a,some_array,n)*some_array.dimensions[n-1] + getOtherCs(a,some_array,n+1);
}
int getCLs(myArray a,arrayRef some_array,int n){
    if(n == some_array.no_of_dim)
        return a.size*a.dimension_bounds[n-1][0];
    return getCs(a,some_array,n)*a.dimension_bounds[n-1][0] + getCLs(a,some_array,n+1);
}
int getCs(myArray a,arrayRef some_array,int n){
    if(n == some_array.no_of_dim)
        return a.size;
    return (a.dimension_bounds[n][1] - a.dimension_bounds[n][0] + 1)*getCs(a,some_array,n+1);
}
int getDimensions(myArray *p,int size,char *str){
    int i = 0;
    while(i < size){
        if(strcmp(p[i].name,str) == 0)
            return p[i].dimensions;
        i++;
    }
    return -1;
}
void printInput(myArray *p, int p_size, arrayRef *q, int q_size){
    int i = 0;
    while(i < p_size){
        printf("\n%s %d %d %d ",p[i].name,p[i].base_addr,p[i].size,p[i].dimensions);
        int temp = 0;
        while(temp < p[i].dimensions){
            printf("%d %d ",p[i].dimension_bounds[temp][0],p[i].dimension_bounds[temp][1]);
            temp++;
        }
        i++;
    }
    i = 0;
    while(i < q_size){
        printf("\n%s ",q[i].name);
        int temp = 0;
        while(temp < q[i].no_of_dim){
            printf("%d ",q[i].dimensions[temp]);
            temp++;
        }
        i++;
    }
}
