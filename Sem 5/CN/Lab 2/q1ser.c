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


void sort(int arr[],int n){
	for(int i =0;i<n-1;i++){
		for(int j = 0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				int temp=arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
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
            int pid = getpid();
            n = read(nd, &size, sizeof(int));
            n = read(nd, buffer_int, size * sizeof(int));
            printf("array from client:\n");
            for(int i =0; i<size; i++){
            	printf("%d\t",buffer_int[i]);
            }
            sort(buffer_int, size);
            printf("\nProcess ID:%d",pid);
            n = write(nd, &pid, sizeof(int));
            n = write(nd, buffer_int, size * sizeof(int));
            getchar();    
            close(nd);
        }
    }
}