#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#define PORT 5555

struct Person{
    char *name;
    // char name[100];
    int age;
};

int main(){
    int sd, nd, len, n;

    struct sockaddr_in servaddr, cliaddr;
    
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd == -1){
        printf("Error\n");
        exit(1);
    }
    servaddr.sin_addr.s_addr = inet_addr("172.16.57.36");
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    len= sizeof(servaddr);
    connect(sd, (struct sockaddr *)&servaddr, len);

    printf("Connection succesful\n");

    struct Person *P = (struct Person*)malloc(sizeof(struct Person));

    P->name = "Parth\0";
    P->age = 20;
    printf("Sending\nName: %s\nAge:%d\n", P->name, P->age);
    n = write(sd, &P, sizeof(P));
    
    
    struct Person *P1 = (struct Person*)malloc(sizeof(struct Person));
    n = read(sd, &P1, sizeof(P1));
    
    printf("Server sent\nName: %s\n Age:%d\n", P1->name, P1->age);
    close(sd);
    getchar();
    exit(0);
}