#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    for (int arg = 1; arg < argc; arg++){
        int fd = open(argv[arg], O_RDONLY);
        for (int i = 0; i < 10; i++) {
            char j;
            read(fd, &j, sizeof(char));
            printf("%c", j);

            while (j != '\n') {
                read(fd, &j, sizeof(char));
                printf("%c", j);
            }
        }
        close(fd);
    }
    
    return 0;
}
