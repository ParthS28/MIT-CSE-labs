
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
        printf("In the child\n");
        printf("Parent PID: %d\n", getppid());
        sleep(5);
        exit(1);
    }
    else{
        // sleep(2);
        printf("In the parent\n");
        wait(&status);
        printf("Child process returned: %d\n", status);
        int es = WEXITSTATUS(status);
        printf("Exit status code: %d\n", es);
    }
    return 0;
}