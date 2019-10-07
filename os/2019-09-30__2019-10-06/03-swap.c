//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: 10v
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: 03-swap.c (unix file name)
// FILE PURPOSE:
// Contains a function which swaps 2 intigers
//------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

void swap(int *a, int *b);

int main() {
    int a = 8, b = 88;
    printf("initial -> a = %d, b = %d\n", a, b);

    swap(&a, &b);
    printf("at eof -> a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int *a, int *b) {
    //------------------------------------------------------------------------
    // FUNCTION: swap (име на функцията)
    // Function which swaps 2 intigers
    // PARAMETERS:
    // a - integer a
    // b - integer b
    //------------------------------------------------------------------------

    int temp = *a;
    *a = *b;
    *b = temp;
}
