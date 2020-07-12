#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char buff;
    int fd = open("a.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error");
        return -1;
    }

    int length = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    for (int i = 0; i < length; i++) {
        read(fd, &buff, sizeof(buff));
        write(1, &buff, sizeof(buff));
        write(1, &buff, sizeof(buff));
    }

    if (close(fd) == -1) {
        perror("Error");
        return -1;
    }
    return 0;
}
