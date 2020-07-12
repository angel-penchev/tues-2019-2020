#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int exec_command(char *const argv[]);

int main(int argc, char *const argv[]) {
    if (argc < 2) {
        printf("Use at least 1 argument.\n");
        return -1;
    }
    while (1) {
        if(exec_command(argv + 1) == -2) {
            return -1;
        }
        sleep(2);
    }
    
    return 0;
}

int exec_command(char *const argv[]) {
    int status;
    pid_t pid = fork();
    
    if (pid == -1) {
        // Error on fork
        perror("Error");
        status = -1;
    } else if (pid == 0) {
        // Child proccess
        if (execvp(argv[0], argv) == -1) {
            perror("Error");
            status = -2;
        }
    } else {
        // Parent
        if (waitpid(pid, &status, 0) != pid) {
            status = -1;
        }
    }

    return status;
}