//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: 10v
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: 01-strlen.c (unix file name)
// FILE PURPOSE:
// Contains a function returning the size of a string
//------------------------------------------------------------------------

#include <stdio.h>

size_t strlen( const char *text );

int main() {
    printf("%ld\n", strlen("Gosho is gone"));
    return 0;
}

size_t strlen( const char *text ) {
    //------------------------------------------------------------------------
    // FUNCTION: strlen (име на функцията)
    // Function returning the size of a string
    // PARAMETERS:
    // text - a sequence of character to be taken the length of
    //------------------------------------------------------------------------

    int i = 0;
    for(; *(text + i) != '\0'; i++);
    return i;
}
