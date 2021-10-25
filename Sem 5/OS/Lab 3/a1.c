
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
        printf("Parent PID before parent dies: %d\n", getppid());
        sleep(7);
        printf("Adopted parent PID: %d\n", getppid());
    }
    else{
        sleep(2);
        printf("In the parent\nKilling parent now.\n");
        exit(0);
    }
    return 0;
}