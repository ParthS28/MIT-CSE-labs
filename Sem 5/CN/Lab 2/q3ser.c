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
#include <time.h>

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
            int a[5];
            n = read(sd, &a, sizeof(int));
            printf("%c\n", a[0]);
            if(a[0] == 1){
                time_t cur_time;
                struct tm* timeinfo;
                time(&cur_time);
                timeinfo = localtime(&cur_time);
                int h = timeinfo->tm_hour;
                int m = timeinfo->tm_min;
                int s = timeinfo->tm_sec;
                printf("Time is %d:%d:%d\n", h, m, s);
                
                n = write(nd, &h, sizeof(int));
                n = write(nd, &m, sizeof(int));
                n = write(nd, &s, sizeof(int));
                getchar();
                close(sd);
                exit(0);
            }
        }
    }
}
