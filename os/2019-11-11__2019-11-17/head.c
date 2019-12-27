#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    int fd = open("a.txt", O_RDONLY);
    for (int i = 0; i < 10; i++) {
        char j;
        read(fd, &j, sizeof(char));
        write(1, &j, sizeof(char));

        while (j != '\n') {
            read(fd, &j, sizeof(char));
            write(1, &j, sizeof(char));
        }
    }
    close(fd);

    return 0;
}
