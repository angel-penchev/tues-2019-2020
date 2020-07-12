#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct
{
    char data;
    unsigned char nextElementAdress;
} block;

int main(int argc, char *argv[]) {
    block current_block;
    int fd = open(argv[1], O_RDONLY);

    for (int i = 0; i < 128; i++) {
        read(fd, &current_block, sizeof(block));
        write(1, &current_block.data, sizeof(current_block.data));

        if (current_block.nextElementAdress == 0) {
            break;
        }

        lseek(fd, current_block.nextElementAdress, SEEK_SET);
    }
    close(fd);
}