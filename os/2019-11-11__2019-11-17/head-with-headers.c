#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv) {
    for (int arg = 1; arg < argc; arg++) {
        if (argc > 2) {
            write(1, "==> ", 4);
            write(1, argv[arg], strlen(argv[arg]));
            write(1, " <==\n", 5);
        }

        int fd = open(argv[arg], O_RDONLY);

        for (int i = 0; i < 10; i++) {
            char j;
            read(fd, &j, sizeof(char));
            write(1, &j, sizeof(char));

            while (j != '\n') {
                read(fd, &j, sizeof(char));
                write(1, &j, sizeof(char));
            }
        }
        if (arg != argc - 1) {
            write(1, "\n", 1);
        }
        close(fd);
    }
    
    return 0;
}
