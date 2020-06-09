//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: XIv
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: starcraft3.c
// FILE PURPOSE:
// Starcraft 3 clone.
//------------------------------------------------------------------------

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define MAX_SCVs 200
#define MINERAL_BLOCK_SIZE 500
#define TOTAL_MARINES 20

int scvs = 5;
int minerals_collected = 0;
int mineral_map_blocks_amount;
int *mineral_map_blocks_left;
int marines = 0;

pthread_t scv_threads[200];
pthread_t stdin_thread;
pthread_mutex_t scv_mutex;
pthread_mutex_t *mineral_blocks_mutex;
pthread_mutex_t command_center_mutex;
pthread_mutex_t stdout_mutex;

void *init_scv(void *parameters);
void *init_stdin();
int buy_with_minerals(int cost);

int main(int argc, char const *argv[]) {
    // Getting amout of mineral blocks
    mineral_map_blocks_amount = 2;
    if (argc >= 2) mineral_map_blocks_amount = atoi(argv[1]);

    // Setting all the mineral blocks to have 500 minerals
    mineral_map_blocks_left = malloc(mineral_map_blocks_amount * sizeof(int));
    for (int i = 0; i < mineral_map_blocks_amount; i++) {
        mineral_map_blocks_left[i] = MINERAL_BLOCK_SIZE;
    }
    
    // Allocing mutex memory
    mineral_blocks_mutex = malloc(mineral_map_blocks_amount * sizeof(pthread_mutex_t));

    // Init mutexes
    pthread_mutex_init(&scv_mutex, NULL);
    for (int i = 0; i < mineral_map_blocks_amount; i++) {
        pthread_mutex_init(&mineral_blocks_mutex[i], NULL);
    }
    pthread_mutex_init(&command_center_mutex, NULL);
    pthread_mutex_init(&stdout_mutex, NULL);

    // Init SCV threads
    for (int i = 0; i < scvs; i++) {
        unsigned int limit = time(0) + 1;
        while (time(0) < limit);
        if (pthread_mutex_lock(&scv_mutex) == -1) {
            // perror("ERROR");
            // return -1;
        }
        if (pthread_create(&scv_threads[i], NULL, init_scv, &i) != 0) {
            perror("ERROR");
            return -1;
        }
        if (pthread_mutex_unlock(&scv_mutex) == -1) {
            // perror("ERROR");
            // return -1;
        }
    }

    // Init stdin thread
    if (pthread_create(&stdin_thread, NULL, init_stdin, NULL) != 0) {
        perror("ERROR");
        return -1;
    }

    // Joining the stdin thread (end of game)
    if (pthread_join(stdin_thread, NULL) != 0) {
        perror("ERROR");
        return -1;
    }
    for (int i = 0; i < scvs; i++) {
        if (pthread_join(scv_threads[i], NULL) != 0) {
            perror("ERROR");
            return -1;
        }
    }

    if (pthread_mutex_lock(&stdout_mutex) == -1) {
        // perror("ERROR");
        // return -1;
    }
    printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n", mineral_map_blocks_amount * MINERAL_BLOCK_SIZE, minerals_collected, scvs, marines);
    if (pthread_mutex_unlock(&stdout_mutex) == -1) {
        // perror("ERROR");
        // return -1;
    }

    // Destroying all mutexes
    if (pthread_mutex_destroy(&scv_mutex) == -1) {
        // perror("ERROR");
        // return -1;
    }
    for (int i = 0; i < mineral_map_blocks_amount; i++) {
        if (pthread_mutex_destroy(&mineral_blocks_mutex[i]) == -1) {
            // perror("ERROR");
            // return -1;
        }
    }
    if (pthread_mutex_destroy(&command_center_mutex) == -1) {
        // perror("ERROR");
        // return -1;
    }

    // Freeing memory
    free(mineral_blocks_mutex);
    free(mineral_map_blocks_left);

    return 0;
}

void *init_scv(void *parameters) {
    //--------------------------------------------
    // FUNCTION: init_scv
    // Creates an SCV thread.
    // PARAMETERS:
    // parameters - parameters
    //----------------------------------------------
    
    
    if (pthread_mutex_lock(&command_center_mutex) == -1) {
        // perror("ERROR");
        pthread_exit(NULL);
    }
    int *params = (int *) parameters;
    int scv_id = params[0];
    if (pthread_mutex_unlock(&command_center_mutex) == -1) {
        // perror("ERROR");
        pthread_exit(NULL);
    }

    int mineral_blocks_status_filled[mineral_map_blocks_amount];
    for (int i = 0; i < mineral_map_blocks_amount; i++) {
        mineral_blocks_status_filled[i] = 1;
    }

    // if (pthread_mutex_unlock(&scv_mutex)) {
    //     // perror("ERROR");
    //     // return -1;
    // }

        // printf("init %d\n", scv_id); 
    for (int is_scv_done = 0; is_scv_done == 0;) {
        is_scv_done = 1;
        for (int i = 0; i < mineral_map_blocks_amount; i++) {
            if (mineral_blocks_status_filled[i] == 1) {
                // sleep(3);
                if (pthread_mutex_trylock(&mineral_blocks_mutex[i]) == 0) {
                    is_scv_done = 0;
                    if (mineral_map_blocks_left[i] == 0) {
                        mineral_blocks_status_filled[i] = 0;
                        if (pthread_mutex_unlock(&mineral_blocks_mutex[i]) == -1) {
                            // perror("ERROR");
                            // pthread_exit(NULL);
                        }
                        continue;
                    }

                    if (pthread_mutex_lock(&stdout_mutex) == -1) {
                        // perror("ERROR");
                        // pthread_exit(NULL);
                    }
                    printf("SCV %d is mining from mineral block %d\n", scv_id, i + 1);
                    printf("SCV %d is transporting minerals\n", scv_id);
                    if (pthread_mutex_unlock(&stdout_mutex) == -1) {
                        // perror("ERROR");
                        // pthread_exit(NULL);
                    }

                    // sleep(2);


                    if (pthread_mutex_lock(&command_center_mutex) == -1) {
                        // perror("ERROR");
                        // pthread_exit(NULL);
                    }

                    if (mineral_map_blocks_left[i] < 8) {
                        minerals_collected += mineral_map_blocks_left[i];
                        mineral_map_blocks_left[i] = 0;
                        mineral_blocks_status_filled[i] = 0;
                    } else {
                        minerals_collected += 8;
                        mineral_map_blocks_left[i] -= 8;
                    }

                    if (pthread_mutex_unlock(&command_center_mutex) == -1) {
                        // perror("ERROR");
                        // pthread_exit(NULL);
                    }


                    if (pthread_mutex_lock(&stdout_mutex) == -1) {
                        // perror("ERROR");
                        // pthread_exit(NULL);
                    }

                    printf("SCV %d delivered minerals to the Command Center\n", scv_id);
                    if (pthread_mutex_unlock(&stdout_mutex) == -1) {
                        // perror("ERROR");
                        // pthread_exit(NULL);
                    }

                    if (pthread_mutex_unlock(&mineral_blocks_mutex[i]) == -1) {
                        // perror("ERROR");
                        // pthread_exit(NULL);
                    }
                }
            }
        }
    }
    pthread_exit(NULL);
}

void *init_stdin() {
    //--------------------------------------------
    // FUNCTION: init_stdin
    // Creates an stdin thread.
    // PARAMETERS:
    // NULL.
    //----------------------------------------------

    for (char input;;) {
        if (marines >= TOTAL_MARINES) {
            break;
        }

        scanf("%c", &input);
        if (input == 'm') {

            if (buy_with_minerals(50) == 0) {
                // sleep(1);
                marines++;
                if (pthread_mutex_lock(&stdout_mutex) == -1) {
                    // perror("ERROR");
                    // pthread_exit(NULL);
                }
                printf("You wanna piece of me, boy?\n");
                if (pthread_mutex_unlock(&stdout_mutex) == -1) {
                    // perror("ERROR");
                    // pthread_exit(NULL);
                }
            } else {
                if (pthread_mutex_lock(&stdout_mutex) == -1) {
                    // perror("ERROR");
                    // pthread_exit(NULL);
                }
                printf("Not enough minerals.\n");
                if (pthread_mutex_unlock(&stdout_mutex) == -1) {
                    // // perror("ERROR");
                    // pthread_exit(NULL);
                }
            }
        }

        if (input == 's') {

            if (buy_with_minerals(50) == 0) {
                // sleep(4);
                if (pthread_mutex_lock(&stdout_mutex) == -1) {
                    // perror("ERROR");
                    pthread_exit(NULL);
                }
                if (pthread_create(&scv_threads[scvs], NULL, init_scv, &scvs) != 0) {
                    perror("ERROR");
                    pthread_exit(NULL);
                }
                scvs++;
                if (pthread_mutex_unlock(&stdout_mutex) == -1) {
                    // perror("ERROR");
                    pthread_exit(NULL);
                }

                if (pthread_mutex_lock(&stdout_mutex) == -1) {
                    // perror("ERROR");
                    pthread_exit(NULL);
                }
                printf("SCV good to go, sir.\n");
                if (pthread_mutex_unlock(&stdout_mutex) == -1) {
                    // perror("ERROR");
                    pthread_exit(NULL);
                }
            } else {
                if (pthread_mutex_lock(&stdout_mutex) == -1) {
                    // perror("ERROR");
                    pthread_exit(NULL);
                }
                printf("Not enough minerals.\n");
                if (pthread_mutex_unlock(&stdout_mutex) == -1) {
                    // perror("ERROR");
                    pthread_exit(NULL);
                }
            }

        }
    }
    pthread_exit(NULL);
}

int buy_with_minerals(int cost) {
    //--------------------------------------------
    // FUNCTION: buy_with_minerals
    // Tries to sub cost from minerals_colected.
    // PARAMETERS:
    // cost: cost
    //----------------------------------------------

    if (minerals_collected < cost) {
        // return -1;
    }

    if (pthread_mutex_lock(&command_center_mutex) == -1) {
        // perror("ERROR");
        // return -1;
    }

    minerals_collected -= cost;

    if (pthread_mutex_unlock(&command_center_mutex) == -1) {
        // perror("ERROR");
        // return -1;
    }
    return 0;
}
