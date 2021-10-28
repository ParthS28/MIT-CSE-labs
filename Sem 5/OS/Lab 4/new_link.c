// Write a program to create a new hard link to an existing file and unlink the same. Accept the old path as input and print the newpath.

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

int main(int argc, char* argv[]){
    struct stat sb;
    int ret;
    
    if (argc < 2)     {
        fprintf (stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }
 
    ret = stat(argv[1], &sb);
    
    if (ret){
        perror("stat");
        return 1;
    }

    printf("Number of hard links: %ld\n", sb.st_nlink);
    
    char* new_path = "q2_stat.c";

    int ret2 = link(argv[1], new_path);

    printf("Linking %s to %s\n", argv[1], new_path);

    struct stat intermediate;
    int ret3 = stat(argv[1],&intermediate);
    printf("Number of hard links: %ld\n", intermediate.st_nlink);

    printf("Unlinking\n");
    int ret4 = unlink(argv[1]);

    struct stat final;
    int ret5 = stat(new_path, &final);
    printf("Number of hard links: %ld\n", final.st_nlink);

    return 0;
    
}