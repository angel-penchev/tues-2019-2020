#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#define TRANSACTION_VALUE 50
#define TRANSACTION_AMOUNT 20

int balance = 10000;
pthread_mutex_t balance_mutex;

void *deposit(void *arg);
void *withdraw(void *arg);

int main(int argc, char *argv[]) {
    int depositors_size = 1;
    int withdrawers_size = 1;

    if (argc == 3) {
        depositors_size = atoi(argv[1]);
        withdrawers_size = atoi(argv[2]);
    } else if (argc == 1) {
    } else {
        printf("Error! Invalid argv.\n");
        return -1;
    }

    pthread_t depositors_threads[depositors_size];
    pthread_t withdrawers_threads[withdrawers_size];

    pthread_mutex_init(&balance_mutex, NULL);

    int dep_ids[depositors_size];
    for (int i = 0; i < depositors_size; i++) {
        dep_ids[i] = i + 1;
        pthread_create(&depositors_threads[i], NULL, deposit, (void *) &dep_ids[i]);
    }

    int wit_ids[withdrawers_size];
    for (int i = 0; i < withdrawers_size; i++) {
        wit_ids[i] = i + 1;
        pthread_create(&withdrawers_threads[i], NULL, withdraw, (void *) &wit_ids[i]);
    }

    for (int i = 0; i < depositors_size; i++) {
        pthread_join(depositors_threads[i], NULL);
    }

    for (int i = 0; i < withdrawers_size; i++) {
        pthread_join(withdrawers_threads[i], NULL);
    }

    pthread_mutex_destroy(&balance_mutex);

    if (balance) {
        printf("Remaining money: %d\n", balance);
    } else {
        printf("BANKRUPT!\n");
    }

    return 0;
}

void *deposit(void *arg) {
    int id = *(int*) arg;
    for (int i = 0; i < TRANSACTION_AMOUNT; i++) {
        pthread_mutex_lock(&balance_mutex);
        if (balance <= 0) {
            pthread_mutex_unlock(&balance_mutex);
            break;
        }
        balance += TRANSACTION_VALUE;
        printf("Banker %d deposited $%d to the bank account\n", id, TRANSACTION_VALUE);
        pthread_mutex_unlock(&balance_mutex);
        sleep(2);
    }
    pthread_exit(NULL);
}

void *withdraw(void *arg) {
    int id = *(int*) arg;
    for (int i = 0; i < TRANSACTION_AMOUNT; i++) {
        pthread_mutex_lock(&balance_mutex);
        if (balance <= 0) {
            pthread_mutex_unlock(&balance_mutex);
            break;
        }
        balance -= TRANSACTION_VALUE;
        printf("Banker %d withrawed $%d from the bank account\n", id, TRANSACTION_VALUE);
        pthread_mutex_unlock(&balance_mutex);
        sleep(2);
    }
    pthread_exit(NULL);
}
