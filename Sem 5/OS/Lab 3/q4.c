/* Create a zombie (defunct) child process (a child with exit() call, but no corresponding wait() in the sleeping parent) 
and allow the init process to adopt it (after parent terminates). 
Run the process as a background process and run the “ps” command.*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();
 
    if(pid == -1){
        printf("Error\n");
        exit(-1);
    }
 
    if(pid == 0){
        printf("Child process\n");
        printf("PID: %d\n", getpid());
        exit(0);
    }
 
    else{
        sleep(5);
        printf("Parent process\n");
        printf("PID: %d\n", getpid());
    }
 
    return 0;
}