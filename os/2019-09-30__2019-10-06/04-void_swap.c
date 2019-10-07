//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: 10v
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: 04-swap.c
// FILE PURPOSE:
// Contains a function which swaps 2 intigers
//------------------------------------------------------------------------

#include <stdio.h>

void swap(void *pa, void *pb, size_t size);
int main() {
    // int a[] = {8, 88, 8, 888}, b[] = {99, 9};
    int a = 99, b = 8;
    printf("initial -> a = %d, b = %d\n", a, b);

    swap(&a, &b, sizeof(a));

    printf("at eof -> a = %d, b = %d\n", a, b);

    return 0;
}

void swap(void *pa, void *pb, size_t size) {
    //------------------------------------------------------------------------
    // FUNCTION: swap
    // Function which swaps 2 intigers
    // PARAMETERS:
    // *a - pointer to elements a
    // *b - pointer to elements b
    // size - size of the swapped variable types
    //------------------------------------------------------------------------

    unsigned char temp;
    unsigned char *a = pa, *b = pb;
    for(; size != 0; size--) {
        temp = *a;
        *a++ = *b;
        *b++ = temp;
    }
}
