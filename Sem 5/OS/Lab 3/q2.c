// Load the binary of the previous program in child and use exec()

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    int status = 0;

    pid = fork();

    if(pid == -1){
        printf("Error in forking\n");
        exit(1);
    }
    else if(pid == 0){
        execlp("./q1", "q1", NULL);
    }
    else{
        printf("Creating child.\n");
        wait(&status);
    }
    return 0;
}