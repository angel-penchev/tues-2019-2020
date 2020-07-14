#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>

int main() {
    const char *dir_path = "./demo/";
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error");
        return -1;
    }

    struct dirent *current_file;
    struct stat current_stat;
    while (1) {
        current_file = readdir(dir);
        if (current_file == NULL) {
            break;
        }

        if (current_file->d_name[0] == '.') {
            continue;
        }

        char pathname[1000];
        strcpy(pathname, dir_path);
        strcat(pathname, current_file->d_name);
    
        int status = stat(pathname, &current_stat);
        if (status != 0) {
            perror("Error");
            return -1;
        }

        if (current_stat.st_size <= 100000) {
            continue;
        }
        
        printf("%s - ", current_file->d_name);
        printf("%d - ", current_file->d_type);
        printf("%ld - ", current_stat.st_size);
        printf("%s\n", getpwuid(current_stat.st_uid)->pw_name);
        // printf("%d\n", current_stat.st_gid);
    }

    if (closedir(dir) == -1) {
        perror("Error");
        return -1;
    }
    return 0;
}