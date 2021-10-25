#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <dirent.h> 
#include <string.h>

void printdir(char* path, int depth){
    DIR * dp;
    struct dirent * entry;
    struct stat statbuf;

    if((dp = opendir(path)) == NULL){
        printf("Could not open directory\n");
        exit(1);
    }

    chdir(path);

    while((entry = readdir(dp)) != NULL){
        lstat(entry->d_name, &statbuf);
        if(S_ISDIR(statbuf.st_mode)){
            // found sub directory
            if(strcmp(".", entry->d_name)==0 || strcmp("..", entry->d_name) == 0){
                continue;
            }

            printf("%*s%s/\n",depth,"",entry->d_name); 
            printdir(entry->d_name, depth+4); 

        } 


        else{ 
            printf("%*s%s\n",depth,"",entry->d_name); 
        } 

  } 

  chdir(".."); 

  closedir(dp); 
}
int main(){
    printdir(".", 0);
    return 0;
}