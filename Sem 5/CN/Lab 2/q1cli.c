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

    printf("Enter number of elements: \n");
    scanf("%d", &size);
    printf("Enter %d elements: \n", size);

    for (int i = 0; i < size; i++){
        scanf("%d", &buffer_int[i]);
    }

    n = write(sd, &size, sizeof(int));
    n = write(sd, buffer_int, size * sizeof(int));
    // printf("-------");
    n = read(sd, &pid, sizeof(int));
    n = read(sd, buffer_int, size * sizeof(int));
    printf("\nSorted array: ");
    for (int i = 0; i < size; i++){
        printf("%d ", buffer_int[i]);
    }
    printf("\nProcess ID: %d\n", pid);
    getchar();
}