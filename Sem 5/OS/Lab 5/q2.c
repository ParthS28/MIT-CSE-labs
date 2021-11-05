#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<limits.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char* argv[]){
    int n;
    int fd[2];
    char buf[1024];
    char *data = "Hello from q2.c";
    pipe(fd);

    write(fd[1], data, strlen(data));
    if((n=read(fd[0], buf, 1023)) >= 0){
        buf[n] = '\0';
        printf("Read %d bytes\n%s\n", n, buf);
    }else{
        perror("Read");
        exit(0);
    }
}