#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

#include <assert.h>

bool isSorted(int a[], int n)
{
    int i;
    for(i=1; i<n; i++)
        if(a[i]<a[i-1])
            return false;
    return true;
}


int main()
{
    int a_even[]= {3, 1, 5, 7, 9, 0, -1, 2};
    int a_odd[]= {3, 1, 5, 7, 9, 0, -1, 2, -6};
    int a_even_sorted[] = {-1, 0, 1, 2, 3, 5, 7, 9};
    int a_odd_sorted[]= {-6, -1, 0, 1, 2, 3, 5, 7, 9};
    int a_even_size = sizeof(a_even)/sizeof(int);
    int a_odd_size = sizeof(a_odd)/sizeof(int);
    int a_even_sorted_size = sizeof(a_even_sorted)/sizeof(int);
    int a_odd_sorted_size = sizeof(a_odd_sorted)/sizeof(int);

    assert(isSorted(a_even, a_even_size)==false);
    assert(isSorted(a_odd, a_odd_size)==false);
    assert(isSorted(a_even_sorted, a_even_sorted_size)==true);
    assert(isSorted(a_odd_sorted, a_odd_sorted_size)==true);

    /* EXERCISE - 1

    insertionSort(a_even, a_even_size);
    insertionSort(a_odd, a_odd_size);
    insertionSort(a_even_sorted, a_even_sorted_size);
    insertionSort(a_odd_sorted, a_odd_sorted_size);

*/
    /*

    EXERCISE - 2*/

    bubbleSort(a_even, a_even_size);
    bubbleSort(a_odd, a_odd_size);
    bubbleSort(a_even_sorted, a_even_sorted_size);
    bubbleSort(a_odd_sorted, a_odd_sorted_size);



    /*

    EXERCISE - 3

    selectionSort(a_even, a_even_size);
    selectionSort(a_odd, a_odd_size);
    selectionSort(a_even_sorted, a_even_sorted_size);
    selectionSort(a_odd_sorted, a_odd_sorted_size);
*/


    /*

    EXERCISE - 4

      mergeSort(a_even, a_even_size);
      mergeSort(a_odd, a_odd_size);
      mergeSort(a_even_sorted,a_even_sorted_size);
      mergeSort(a_odd_sorted, a_odd_sorted_size);
*/

    /*

    EXERCISE - 5

    quickSort(a_even, a_even_size);
    quickSort(a_odd, a_odd_size);
    quickSort(a_even_sorted,a_even_sorted_size);
    quickSort(a_odd_sorted, a_odd_sorted_size);

*/



    assert(isSorted(a_even, a_even_size)==true);
    assert(isSorted(a_odd, a_odd_size)==true);
    assert(isSorted(a_even_sorted, a_even_sorted_size)==true);
    assert(isSorted(a_odd_sorted, a_odd_sorted_size)==true);
    printf("SUCCESS");
    return 0;
}
