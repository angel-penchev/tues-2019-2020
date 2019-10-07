//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: 10v
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: 02-strcat.c (unix file name)
// FILE PURPOSE:
// Contains a function which appends the 2 strings
//------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

char* strcat( char* destination, const char* source );

int main() {
    char source[50], destination[50];
    strcpy(source,  "Gosho");
    strcpy(destination, " is gone");

    printf("%s\n", strcat(source, destination));
    return 0;
}

char* strcat( char* destination, const char* source ) {
    //------------------------------------------------------------------------
    // FUNCTION: strcat (име на функцията)
    // Function which appends the 2 strings
    // PARAMETERS:
    // destination - the string to which the text should be appended to
    // source - the string which should be appended to the destination
    //------------------------------------------------------------------------

    strcpy(destination + strlen (destination), source);
    return destination;
}
