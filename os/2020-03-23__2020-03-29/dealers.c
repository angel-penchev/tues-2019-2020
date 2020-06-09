//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: XIv
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: dealers.c
// FILE PURPOSE:
// Multi-threaded car buying sim.
//------------------------------------------------------------------------

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>

#define N 20
#define M 5

pthread_mutex_t car_mutex[M];

void *init_buyer(void * parameters);

int main(int argc, char const *argv[]) {
    int *n_id;
    pthread_t buyer_threads[N];

    for (int i = 0; i < M; i++) {
        pthread_mutex_init(&car_mutex[i], NULL);
    }

    for (int i = 0; i < N; i++) {
        n_id = malloc(sizeof(int));
        *n_id = i;
        pthread_create(&buyer_threads[i], NULL, init_buyer, n_id);
    }

    pthread_exit(NULL);
    return 0;
}

void *init_buyer(void * parameters) {
    //------------------------------------------------------------------------
    // FUNCTION: *init_buyer
    // Test drives a car.
    // PARAMETERS:
    // void * parameters - contains n_id (number)
    //------------------------------------------------------------------------

    int *params = (int *) parameters;
    int n_id = params[0];

    for (;;) {
        for (int i = 0; i < M; i++) {
            if (pthread_mutex_trylock(&car_mutex[i]) == 0) {
                printf("Buyer %d takes car %d.\n", n_id, i);
                // sleep(1);
                printf("Buyer %d returns car %d.\n", n_id, i);
                pthread_mutex_unlock(&car_mutex[i]);
                return NULL;
            }
        }
    }
}
