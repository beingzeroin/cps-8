#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int cmdLineArguments(int ac, char *av[])
{

    printf("%d\n", ac);

    int i;
    for(i=0;i<ac;i++)
        printf("%s\n", av[i]);
    return 0;
}

int fileHandling()
{
    // OPEN FILE
    FILE *fp = fopen("C:\\Users\\Sandy\\Desktop\\myFile.txt", "r");
    FILE *fo = fopen("out.txt", "w");
    assert(fp!=NULL);
    assert(fo!=NULL);

    char c;
    while(!feof(fp)){
        fscanf(fp, "%c", &c);
        fprintf(fo, "%c", c);
    }
    fclose(fp);
    fclose(fo);

    // TILL WE ARE NOT AT EOF
        // KEEP READING
        // KEEP PRINTING

    // CLOSE THE FILE


    return 0;
}

void swapByValue(int x, int y)
{
    int t;
    t = x;
    x = y;
    y = t;
}
void swapByReference(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
}
int main()
{
    int a=10, b=20;

    printf("BEFORE SWAP: a:%d, b:%d\n", a, b);
    swapByValue(a, b);
    printf("AFTER SWAP: a:%d, b:%d\n", a, b);
    swapByReference(&a, &b);
    printf("AFTER SWAP BY REF: a:%d, b:%d", a, b);
    return 0;
}
