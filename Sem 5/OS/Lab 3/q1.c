// Block parent till child completes process using wait

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
        printf("In the child process\n");
        printf("Completing child process\n");
    }
    else{
        printf("In the parent process.\nWaiting for child process to get over.\n");
        wait(&status);
        printf("Child process returned: %d\n", status);
        printf("Completing parent process.\n");
    }
    return 0;
}