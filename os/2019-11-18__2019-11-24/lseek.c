#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define SYSTEM_SIZE 128

typedef struct
{
    char data;
    unsigned char nextElementAdress;
} block;

int main(int argc, char **argv) {
    int fd = open(argv[1], O_RDONLY);

    for (int i = 0; i < SYSTEM_SIZE; i++) {
        block current_block;
        read(fd, &current_block.data, sizeof(char));
        read(fd, &current_block.nextElementAdress, sizeof(unsigned char));
        write(1, &current_block.data, sizeof(char));

        if (!current_block.nextElementAdress) {
            break;
        }
        
        lseek(fd, current_block.nextElementAdress, SEEK_SET);
    }
    
    close(fd);

    return 0;
}