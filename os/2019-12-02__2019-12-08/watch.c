//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: XIv
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: watch.c
// FILE PURPOSE:
// Recreated the system watch bin file, which reruns another process
// continiously in equal intervals of time
//------------------------------------------------------------------------

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <err.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#define _POSIX_SOURCE

int watch(char *const argv[]);

int main(int argc, char *const argv[]) {
    return watch(argv);
}

int watch(char *const argv[]) {
    //------------------------------------------------------------------------
    // FUNCTION: watch
    // Continuosly run the process loop.
    // PARAMETERS:
    // char *const argv[] - command to be executed
    //------------------------------------------------------------------------
    while (1) {
        int status;
        pid_t pid = fork();

        if (pid < 0) {
            status = -1;
        } else if (pid == 0) {
            char *const *passed_args = argv + 1;
            if (execvp (argv[1], passed_args) == -1) {
                perror (argv[1]);
                return status;
            };
        } else {
            if (waitpid (pid, &status, 0) != pid) {
                status = -1;
            }
        }
        if (status == -1) {
            perror ("fork");
        };

        sleep(2);
    }

    return 0;
}
