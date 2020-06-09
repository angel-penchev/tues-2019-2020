//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: XIv
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: primes.c
// FILE PURPOSE:
// Multi-threaded prime number counter.
//------------------------------------------------------------------------

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>
#define MAX_COMMAND_SIZE 256
#define MAX_THREADS 256

void *count_primes(void * parameters);

int main(int argc, char const *argv[]) {
    char raw_command[MAX_COMMAND_SIZE];
    char command;
    int *number;
    pthread_t threads[MAX_THREADS];
    int current_thread = 0;

    for (;;) {
        number = malloc(sizeof(int));
        *number = -1;

        if (fgets(raw_command, MAX_COMMAND_SIZE, stdin) == NULL) {
            break;
        }
        sscanf(raw_command, "%c%d", &command, number);

        if (command == 'e') {
            break;
        } else if (command == 'p' && *number != -1) {
            if (pthread_create(
                &threads[current_thread++],
                NULL,
                count_primes,
                number
            )) {
                printf("ERROR; pthread_create()\n");
            }
        } else {
            printf("Supported commands:\np N - Starts a new calculation for the number of primes from 1 to N\ne - Waits for all calculations to finish and exits\n");
        }
    }

    free(number);
    pthread_exit(NULL);;
    return 0;
}

void *count_primes(void * parameters) {
    //------------------------------------------------------------------------
    // FUNCTION: count_primes
    // Counts the amount of primes between 2 and N-1
    // PARAMETERS:
    // void * parameters - contains N (number)
    //------------------------------------------------------------------------

    int *params = (int *) parameters;
    int number = params[0];

    printf("Prime calculation started for N=%d\n", number);
    
    int count = 0;
    int is_prime;
    for (int i = 2; i < number; i++) {
        is_prime = 1;
        for (int j = 2; j < i; j++) {
            if (!(i % j)) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            count++;
        }
    }

    printf("Number of primes for N=%d is %d\n", number, count);
}