// Not working
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
  
int main(){
    // We use two pipes
    // First pipe to send input string from parent
    // Second pipe to send concatenated string from child
  
    int fd1[2];  // Used to store two ends of first pipe
    int fd2[2];  // Used to store two ends of second pipe
  
    char fixed_str[] = "forgeeks.org";
    char input_str[100];
    pid_t p;
  
    if (pipe(fd1)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
    if (pipe(fd2)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
  
    scanf("%s", input_str);
    p = fork();
  
    if (p < 0)
    {
        fprintf(stderr, "fork Failed" );
        return 1;
    }
  
    // Parent process
    else if (p > 0){
        // int s;
        // wait(&s);
        printf("In the parent process\nMessage received: ");
        char buf[1000];
        close(fd1[0]);
        write(fd1[1], "1", strlen("1")+1);
        close(fd1[1]);
        close(fd2[1]);
        read(fd2[0], buf, 1000);
        printf("%s\n", buf);
        close(fd2[0]);
    }
    // child process
    else{
        printf("In the child process\nWrite a message: ");
        close(fd1[1]);
        char* temp;
        read(fd1[0], temp, 100);  
        if(strcmp(temp, "1") != 0) exit(1);
        char buf[1000];
        fgets(buf, 1000, stdin);
  
        close(fd1[0]);
        close(fd2[0]);
  
        write(fd2[1], buf, strlen(buf)+1);
        close(fd2[1]);
  
        // exit(0);
    }
}