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

int main(){
    int sd, len, n;
    struct sockaddr_in seraddress, cliaddr;
    int buf[256];
    char c;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd == -1){
        printf("Error in creating socket\n");
        exit(1);
    }
    seraddress.sin_family = AF_INET;
    seraddress.sin_addr.s_addr = INADDR_ANY;
    seraddress.sin_port = htons(10200);
    len = sizeof(seraddress);
    connect(sd, (struct sockaddr *)&seraddress, len);

    printf("Making request for time\n");
    int a[] = {1};
    n = write(sd, &a, sizeof(int));

    int h, m, s;
    n = read(sd, &h, sizeof(int));
    n = read(sd, &m, sizeof(int));
    n = read(sd, &s, sizeof(int));
    printf("Time is %d:%d:%d\n", h, m, s);
    getchar();
    exit(0);
}