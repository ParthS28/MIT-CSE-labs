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
    char buf[256];
    int buffer_int[256];
    int size, pid;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd == -1){
		printf("Error in creating socket");
        exit(1);
	}
    seraddress.sin_family = AF_INET;
    seraddress.sin_addr.s_addr = INADDR_ANY;
    seraddress.sin_port = htons(10200);
    len = sizeof(seraddress);
    connect(sd, (struct sockaddr *)&seraddress, len);
    printf("Enter expressions\n");
    scanf("%d %c %d", &buffer_int[0], &buf[0], &buffer_int[1]);

    n = write(sd, &buffer_int, 2*sizeof(int));
    n = write(sd, &buf, sizeof(char));
    int ans;
    n = read(sd, &ans, sizeof(int));
    printf("Answer = %d\n", ans);
    getchar();
    exit(0);
}