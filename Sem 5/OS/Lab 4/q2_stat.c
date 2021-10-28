// Write a program to print out the complete stat structure of a file.

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

char* todate(char* str, time_t val){
    strftime(str, 36, "%d.%m.%Y %H:%M:%S", localtime(&val));
    return str;
}

int main(int argc, char* argv[]){
    struct stat sb;
    int ret;
    char date[100];
    if(argc < 2){
        fprintf (stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }

    ret = stat(argv[1], &sb);
    
    if (ret){
        perror("stat");
        return 1;
    }

    printf("ID of device: %ld\n", sb.st_dev);
    printf("Inode number: %ld\n", sb.st_ino);
    printf("File mode - %hu\n", sb.st_mode);
    printf("Number of hard links - %ld\n", sb.st_nlink);
    printf("User ID - %d\n", sb.st_uid);
    printf("Group owner - %d\n", sb.st_gid);
    printf("File size - %ld\n", sb.st_size);
    printf("Blocksize - %ld\n", sb.st_blksize);
    printf("Number of Blocks - %ld\n", sb.st_blocks);
    printf("Last access time - %s\n", todate(date,sb.st_atime));
    printf("Last modification time - %s\n", todate(date,sb.st_mtime));
    printf("Last change time - %s\n", todate(date,sb.st_ctime));

    DIR * dp;
 
    struct dirent * entry;
    struct stat statbuf;
 
    if((dp = opendir(".")) == NULL)
    {
        printf("Cannot open directory \n"); 
        return 0;
    }
 
    chdir(".");
 
    while((entry = readdir(dp)) != NULL){
        lstat(entry->d_name,&statbuf);
 
        if(!S_ISDIR(statbuf.st_mode)){
            if(strcmp(entry->d_name,argv[1])==0){
                printf("Permissions\t");
                printf((S_ISDIR(statbuf.st_mode)) ? "d" : "-");
                printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
                printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
                printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
                printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
                printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
                printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
                printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
                printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
                printf((statbuf.st_mode & S_IXOTH) ? "x" : "-");
                printf("\n");
            }
        }
    }
}