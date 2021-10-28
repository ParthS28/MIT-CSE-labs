// Inode number of all files in directory

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char* argv[]){

    struct stat sb;
    int ret;
    
    if (argc < 2)     {
        fprintf (stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }

    DIR * dp;

    struct dirent * entry;
    struct stat statbuf;

    if((dp = opendir(argv[1])) == NULL)
    {
        printf("Cannot open directory \n"); 
        return 0;
    }
 
    chdir(argv[1]);

    while((entry = readdir(dp)) != NULL){
        lstat(entry->d_name,&statbuf);

        if(!S_ISDIR(statbuf.st_mode)){
            printf("Inode number for %s: %ld\n", entry->d_name, statbuf.st_ino);
        }
    }
    return 0;
}