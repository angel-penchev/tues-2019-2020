//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: 10v
// NUMBER: 3
// PROBLEM: #5
// FILE NAME: 05-strdup.c
// FILE PURPOSE:
// Duplicates a string and returns the copy address
//------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strdup( const char *str );

int main() {
    char str[] = "goneisobama";
    printf("initial -> %s\ncloned  -> %s\n", str, strdup(str));
    return 0;
}

char *strdup( const char *str ) {
    // ------------------------------------------------------------------------
    // FUNCTION: strdup
    // Duplicates a string and returns the copy address
    // PARAMETERS:
    // *str - the string to be cloned
    // ------------------------------------------------------------------------

    char *new_str = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    return strcpy(new_str, str);
}
