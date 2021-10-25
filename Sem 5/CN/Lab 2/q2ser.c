#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <netdb.h> 
#include <arpa/inet.h> 
#include <sys/wait.h> 
#include <signal.h> 

int calc(int a, int b, char c){
    switch(c){
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '/':
            return a / b;
            break;
        case '*':
            return a * b;
            break;
        default:
            return 0;
            break;
    }
}
int main(){
    int sd, nd, len, n, size;
    struct sockaddr_in seraddress, cliaddr; 
    char buf[256], c;
    int buffer_int[256];
    printf("Initiating server\n");
    sd=socket(AF_INET, SOCK_STREAM, 0); 
    if(sd == -1){
		printf("Error in creating socket");
        exit(1);
	}
    seraddress.sin_family=AF_INET; 
    seraddress.sin_addr.s_addr=INADDR_ANY; 
    seraddress.sin_port=htons(10200); 

    bind(sd,(struct sockaddr*)&seraddress,sizeof(seraddress)); 

    listen(sd,5); 
    len=sizeof(cliaddr); 

    while(1){
        nd = accept(sd, (struct sockaddr *)&cliaddr, &len);
        puts("Connected to client");

        if(fork() == 0){
            // child process, only concerned with data transfer
            close(sd);
            n = read(nd, buffer_int, 2*sizeof(int));  // read integers
            n = read(nd, buf, 1*sizeof(char));
            printf("Calculating %d %c %d", buffer_int[0], buf[0], buffer_int[1]);
            int ans = calc(buffer_int[0], buffer_int[1], buf[0]);
            n = write(nd, &ans, sizeof(int));
            // n = write(nd, &pid, sizeof(int));
            // n = write(nd, buffer_int, size * sizeof(int));
            getchar();    
            close(nd);
        }
    }
}