#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, m, c, n_array[100], m_array[1000], testcase = 1;
    bool switches[100];
    while(true){
        scanf("%d %d %d",&n,&m,&c);
        if(n == 0 && m == 0 && c == 0)
            break;
        int i = 0, consumption = 0, max = 0;
        for(i = 0; i < 100; i++)
            switches[i] = false;
        i = 0;
        while(i < n){
            scanf("%d",&n_array[i]);
            i++;
        }
        i = 0;
        while(i < m){
            scanf("%d",&m_array[i]);
            i++;
        }
        printf("Sequence %d\n",testcase);
        i = 0;
        while(i < m){
            int ind = m_array[i]-1;
            if(switches[ind] == false){
                consumption += n_array[ind];
                if(consumption > c){
                    printf("Fuse was blown.\n\n");
                    break;
                }
                switches[ind] = true;
            }
            else{
                consumption -= n_array[ind];
                switches[ind] = false;
            }
            i++;
            if(consumption > max)
                max = consumption;
        }
        if(i == m){
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n",max);
        }
        testcase++;
    }
    return 0;
}
