// Write a program to print out the complete stat structure of a file.

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <string.h>

char* todate(char* str, time_t val){
    strftime(str, 36, "%d.%m.%Y %H:%M:%S", localtime(&val));
    return str;
}

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
    char date[100];

    while((entry = readdir(dp)) != NULL){
        if(strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0) continue;

        ret = stat(entry->d_name,&sb);

        printf("Stat for %s\n", entry->d_name);

        printf("\tID of device: %ld\n", sb.st_dev);
        printf("\tInode number: %ld\n", sb.st_ino);
        printf("\tFile mode - %hu\n", sb.st_mode);
        printf("\tNumber of hard links - %ld\n", sb.st_nlink);
        printf("\tUser ID - %d\n", sb.st_uid);
        printf("\tGroup owner - %d\n", sb.st_gid);
        printf("\tFile size - %ld\n", sb.st_size);
        printf("\tBlocksize - %ld\n", sb.st_blksize);
        printf("\tNumber of Blocks - %ld\n", sb.st_blocks);
        printf("\tLast access time - %s\n", todate(date,sb.st_atime));
        printf("\tLast modification time - %s\n", todate(date,sb.st_mtime));
        printf("\tLast modification time - %s\n", todate(date,sb.st_mtime));
        printf("\tLast change time - %s\n", todate(date,sb.st_ctime));

        printf("\tPermissions\t");
        printf((S_ISDIR(sb.st_mode)) ? "d" : "-");
        printf((sb.st_mode & S_IRUSR) ? "r" : "-");
        printf((sb.st_mode & S_IWUSR) ? "w" : "-");
        printf((sb.st_mode & S_IXUSR) ? "x" : "-");
        printf((sb.st_mode & S_IRGRP) ? "r" : "-");
        printf((sb.st_mode & S_IWGRP) ? "w" : "-");
        printf((sb.st_mode & S_IXGRP) ? "x" : "-");
        printf((sb.st_mode & S_IROTH) ? "r" : "-");
        printf((sb.st_mode & S_IWOTH) ? "w" : "-");
        printf((sb.st_mode & S_IXOTH) ? "x" : "-");
        printf("\n");
    }
    return 0;
}