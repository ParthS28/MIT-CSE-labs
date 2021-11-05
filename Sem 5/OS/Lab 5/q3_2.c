#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<limits.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<string.h>
 
#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 1000

int main(int argc, char *argv[]){
    int pipe_fd;
    int res;
    int open_mode_write = O_WRONLY;
    int open_mode_read = O_RDONLY;
    int n=0;
    char buffer[BUFFER_SIZE+1];

    if(access(FIFO_NAME,F_OK)==-1){
        res=mkfifo(FIFO_NAME,0777);
        if(res!=0){
            fprintf(stderr, "Could not create file%s\n",FIFO_NAME );
            exit(EXIT_FAILURE);    
        }
    }

    

    while(1){
        
        printf("Current mode: Reading\n");
        pipe_fd = open(FIFO_NAME, open_mode_read);
        res = read(pipe_fd, buffer, BUFFER_SIZE);
        if(res == -1){
            perror("Read");
            exit(0);
        }
        printf("%s\n", buffer);
        close(pipe_fd);
        

        printf("Current mode: Writing\n");
        pipe_fd = open(FIFO_NAME, open_mode_write);
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        write(pipe_fd, buffer, BUFFER_SIZE);
        close(pipe_fd);
        printf("\n");
    }
    (void)close(pipe_fd);

    printf("Process %d Finished\n",getpid() );
    exit(EXIT_SUCCESS);
}