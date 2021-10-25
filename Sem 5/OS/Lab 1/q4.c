#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char* argv[]){
	if(argc!=3){
	    printf("Insufficient Arguments\n");
        exit(1);
	}
	int in, out;
	char c;
	char buffer[128];
    int nread;
	in=open(argv[1],O_RDWR);
    out=open(argv[2],O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    printf("Contents of first file\n");
    read(in, buffer, 128);
    printf("File 1 content now: %s\n", buffer);
    if(in == -1 || out == -1){
    	printf("File not found\n");
    	exit(1);
    }

    while(read(in, &c, 1) == 1){
    	write(out, &c, 1);
    }
    printf("Contents of second file now\n");
    read(out, buffer, 128);
    printf("File 2 content now: %s\n", buffer);
    exit(0);
}