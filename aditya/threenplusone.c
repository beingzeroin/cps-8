#include <stdio.h>

int threeNPlusOne(int n){
    int count = 1;
    while(n != 1){
        n = (n%2 != 0)?(3*n + 1):(n/2);
        count++;
    }
    return count;
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int low, high, i, result, temp;
    char ch;
    while(scanf("%d %d",&low,&high) == 2){
        printf("%d %d ",low,high);
        if(low > high)
            swap(&low,&high);
        result = 0;
        i = low;
        while(i!=(high+1)){
            temp = threeNPlusOne(i);
            if(result < temp)
                result = temp;
            i++;
        }
        printf("%d\n",result);
    }
    return 0;
}
