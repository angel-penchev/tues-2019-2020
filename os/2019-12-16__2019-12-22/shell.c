//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: XIv
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: shell.c
// FILE PURPOSE:
// Create a simple shell interpreter.
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#define STRING_LENGTH 100

int shell();
char **parse_cmdline (char *cmdline);
int run_command(char * const* command);

int main(int argc, char const *argv[]) {
    return shell();
}

int shell() {
    //------------------------------------------------------------------------
    // FUNCTION: shell
    // Includes the shell loop, which interprets each inputed command.
    //------------------------------------------------------------------------

    for (int i = 0; 1; i++) {
        write(1, "$ ", strlen("$ "));

        char *cmdline = malloc(STRING_LENGTH * sizeof(char));
        if (fgets(cmdline, STRING_LENGTH, stdin) == NULL) {
            free(cmdline);
            return 0;
        };

        char **command = parse_cmdline(cmdline);
        if (run_command(command) == -2) {
            free(cmdline); free(command);
            return 0;
        };

        free(cmdline); free(command);
    }
}

char **parse_cmdline (char *cmdline) {
    //------------------------------------------------------------------------
    // FUNCTION: parse_cmdline
    // Splits the stdin command into workable chunks for exec().
    // PARAMETERS:
    // char *cmdline - Raw command input from stdin.
    //------------------------------------------------------------------------

    char **command = malloc(strlen(cmdline) * sizeof(char *));
    char delim[] = {' ', '\n'};
    char *tok = strtok(cmdline, delim);

    for (int j = 0; tok != NULL; j++) {
        command[j] = tok;
        tok = strtok(NULL, delim);
    }
    return command;
}

int run_command(char * const* command) {
    //------------------------------------------------------------------------
    // FUNCTION: run_command
    // Creates a child process and executes the passed command.
    // PARAMETERS:
    // char * const* command - Command to be executed by execvp();
    //------------------------------------------------------------------------

    int status = 0;
    pid_t pid = fork ();

    if (pid < 0) {
        perror ("fork");
        status = -1;
    } else if (pid == 0) {
        if (execvp (command[0], command) == -1) {
            perror (command[0]);
            status = -2;
        };
    } else {
        if (waitpid (pid, &status, 0) != pid) {
            perror ("fork");
            status = -1;
        }
    }

    return status;
}