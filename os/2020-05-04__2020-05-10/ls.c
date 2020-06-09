//------------------------------------------------------------------------
// NAME: Angel Penchev
// CLASS: XIv
// NUMBER: 3
// PROBLEM: #1
// FILE NAME: ls.c
// FILE PURPOSE:
// /bin/ls clone
//------------------------------------------------------------------------

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#define HALF_YEAR_IN_SECONDS 60 * 60 * 24 * 30 * 6

void print_dir(const char *path, unsigned int show_hidden, unsigned int long_description, unsigned int show_header, unsigned int recurse);
void print_dirent(const char *path, unsigned int long_description);
int is_dir(const char *path);

int main(int argc, char *argv[]) {
    // Parsing arguments
    unsigned int show_hidden = 0, long_description = 0, show_header = 0, recurse = 0, found_dirs_in_argv = 0;
    for (int i = 1; i < argc; i++) {
        // If it's a flag (starts with '-')
        if (argv[i][0] == '-') {
            for (int j = 1; j < strlen(argv[i]); j++) {
                switch (argv[i][j]) {
                    case 'A': show_hidden = 1; break;               // Show hidden flag (except '.' & '..')
                    case 'a': show_hidden = 2; break;               // Show hidden flag (including '.' & '..')
                    case 'l': long_description = 1; break;          // Long description flag
                    case 'R': recurse = 1, show_header = 1; break;  // Recursive flag
                }
            }
        } else {
            // If it's not a flag; ++ on paths count
            if (is_dir(argv[i])) found_dirs_in_argv++;
        }
    }

    // At least 2 paths are needed for the header to show
    if (found_dirs_in_argv >= 2) show_header = 1;

    // Iterrating over filepaths in argv
    for (int i = 1, dirs_found = 0; i < argc; i++) {
        if (argv[i][0] != '-') {

            // Check if the path exists
            struct stat path_stat;
            if (stat(argv[i], &path_stat) == -1) {
                fprintf(stderr, "ls: cannot access %s: %s\n", argv[i], strerror(errno));
                return -1;
            };

            // Checking whether the path is a dir or a file
            if (S_ISDIR(path_stat.st_mode)) {
                print_dir(argv[i], show_hidden, long_description, show_header, recurse);
                dirs_found++;
            } else print_dirent(argv[i], long_description);

            // NW between '-R' entries except for the last one
            if (show_header && dirs_found != found_dirs_in_argv - 2) printf("\n");
        }
    }

    // If no paths are fount -> run on current dir
    if (!found_dirs_in_argv){
        print_dir(".", show_hidden, long_description, show_header, recurse);
    }
}

void print_dir(const char *path, unsigned int show_hidden, unsigned int long_description, unsigned int show_header, unsigned int recurse) {
    //--------------------------------------------
    // FUNCTION: print_dir
    // Displays "ls" information for a directory.
    //
    // PARAMETERS:
    // const char *path - Path to target
    // unsigned int show_hidden - Display hidden files (1 - '-a' - hidden files except '.' & '..'; 2 - '-A' - all hidden files)
    // unsigned int long_description - Displays all stat information - '-l'
    // unsigned int show_header - Displays the title of the directory being listed - used for '-R'
    // unsigned int recurse - Recurse over directory - '-R'
    //----------------------------------------------

    struct dirent *file;
    struct stat file_stat;
    char *inner_dirs[100], relative_path[PATH_MAX];
    unsigned int inner_dirs_count = 0;

    DIR *curr_dir;
    if ((curr_dir = opendir(path)) == NULL) {
        fprintf(stderr, "ls: cannot open directory %s: %s\n", path, strerror(errno));
        return;
    };

    if (show_header) {
        printf("%s:\n", path);
    }

    // Print total blocks in directory
    if (long_description) {
        unsigned int total_size = 0;

        // Summing all file st_blocks
        while ((file = readdir(curr_dir)) != NULL) {
            if (file->d_name[0] != '.' || show_hidden) {
                if (show_hidden != 2 && (!strcmp(file->d_name, ".") || !strcmp(file->d_name, ".."))) continue;
                snprintf(relative_path, sizeof(relative_path), "%s/%s", path, file->d_name);
                stat(relative_path, &file_stat);
                total_size += file_stat.st_blocks;
            }
        }
        printf("total %d\n", total_size/2); // Devision due to usage of 1024b instad of 512b
    }

    // Reopening dir after calculation of total block size
    closedir(curr_dir);
    if ((curr_dir = opendir(path)) == NULL) {
        fprintf(stderr, "ls: cannot open directory %s: %s\n", path, strerror(errno));
        return;
    };

    // Print every path in the directory
    while ((file = readdir(curr_dir)) != NULL) {

        // Skip hidden files unless show_hidden is set
        if (file->d_name[0] != '.' || show_hidden) {

            // Skipping '.' & '..' unless show_hidden is set
            if (show_hidden != 2 && (!strcmp(file->d_name, ".") || !strcmp(file->d_name, ".."))) continue;

            // Creating total file path and printing path information
            snprintf(relative_path, sizeof(relative_path), "%s/%s", path, file->d_name);
            print_dirent(relative_path, long_description);

            // If current file is directory and recurse flag is set -> save path to recurse later
            if (recurse && file->d_type == DT_DIR && !(!strcmp(file->d_name, ".") || !strcmp(file->d_name, ".."))) {
                inner_dirs[inner_dirs_count++] = strcat(strcat(strcpy(malloc(strlen(path) + strlen("/") + strlen(file->d_name) +  1), path), "/"), file->d_name);
            }
        }
    }
    closedir(curr_dir);
    curr_dir = NULL;

    // Recursing over saved directories
    if (recurse) {
        for (int i = 0; i < inner_dirs_count; i++) {
            printf("\n");
            print_dir(inner_dirs[i], show_hidden, long_description, show_header, recurse);
            free(inner_dirs[i]);
        }
    }
}

void print_dirent(const char *path, unsigned int long_description) {
    //--------------------------------------------
    // FUNCTION: print_dirent
    // Displays "ls" information for a file.
    //
    // PARAMETERS:
    // const char *path - Path to target
    // unsigned int long_description - Displays all stat information - '-l'
    //----------------------------------------------

    struct stat file_stat;
    stat(path, &file_stat);

    // Print file type
    if (S_ISREG(file_stat.st_mode)) printf("-");
    else if (S_ISDIR(file_stat.st_mode)) printf("d");
    else if (S_ISBLK(file_stat.st_mode)) printf("b");
    else if (S_ISCHR(file_stat.st_mode)) printf("c");
    else if (S_ISFIFO(file_stat.st_mode)) printf("p");
    else if (S_ISLNK(file_stat.st_mode)) printf("l");
    else if (S_ISSOCK(file_stat.st_mode)) printf("s");
    else printf("?");

    // If long_description is set, additional information is display
    if (long_description) {
        // Print file premissions
        if (file_stat.st_mode & S_IRUSR) printf("r"); else printf("-");
        if (file_stat.st_mode & S_IWUSR) printf("w"); else printf("-");
        if (file_stat.st_mode & S_IXUSR) printf("x"); else printf("-");
        if (file_stat.st_mode & S_IRGRP) printf("r"); else printf("-");
        if (file_stat.st_mode & S_IWGRP) printf("w"); else printf("-");
        if (file_stat.st_mode & S_IXGRP) printf("x"); else printf("-");
        if (file_stat.st_mode & S_IROTH) printf("r"); else printf("-");
        if (file_stat.st_mode & S_IWOTH) printf("w"); else printf("-");
        if (file_stat.st_mode & S_IXOTH) printf("x"); else printf("-");

        // Print file number of links
        printf(" %ld", file_stat.st_nlink);

        // Print file owner name
        printf(" %4s", getpwuid(file_stat.st_uid)->pw_name);

        // Print file group name
        printf(" %4s", getgrgid(file_stat.st_gid)->gr_name);
        
        // Print modification date
        printf(" %ld", file_stat.st_size);

        // Print modification date
        time_t file_timer;
        unsigned int current_time = time(0);
        struct tm *file_timer_info;
        char mod_time_str[88];

        file_timer = time(&file_stat.st_mtime);
        file_timer_info = localtime(&file_timer);

        // Comparison - if file is older than 6 months -> display year instead of HH:MM in mod info
        if (file_stat.st_mtime - current_time > -HALF_YEAR_IN_SECONDS) strftime(mod_time_str, 88, "%b %d %H:%M", file_timer_info);
        else strftime(mod_time_str, 88, "%b %d %Y", file_timer_info);
        printf(" %s", mod_time_str);
    }

    // Print file name (strips parent dir info if needed)
    if (strstr(path, "/") != NULL) {
        printf(" %s\n", strrchr(path, '/') + 1);
    } else {
        printf(" %s\n", path);
    }
    
}

int is_dir(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}