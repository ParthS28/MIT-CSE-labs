#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[]){

	if(argc!=3){
		printf("Insufficient arguments\n");
		exit(1);
	}

	int f1;
	f1 = open(argv[1], O_RDONLY);
	if(f1 == -1){
		printf("File not found\n");
		exit(1);
	}
	int f2;
	f2 = open(argv[2], O_RDONLY);
	if(f2 == -1){
		printf("File not found\n");
		exit(1);
	}

	char c1[4096], c2[4096], c;
	int count = 0, i = 0, flag = 0;
	while(read(f1, &c, 1)){
		if(c!='\n'){
			
			c1[i++] = c; 
		}
		else{
			c1[i++] = '\n';
			count++;
			if(count == 20){
				flag = 1;
				printf("File 1 done\n");
				printf("%s\n", c1);
				break;
			}
		}
	}
	if(flag == 0){
		printf("File 1 done\n");
		printf("%s\n", c1);
	}
	close(f1);
	i = 0; count = 0; flag = 0;
	while(read(f2, &c, 1)){
		if(c!='\n'){
			
			c2[i++] = c; 
		}
		else{
			c2[i++] = '\n';
			count++;
			if(count == 20){
				flag = 1;
				printf("File 2 done\n");
				printf("%s\n", c2);
				break;
			}
		}
	}
	if(flag == 0){
		printf("File 2 done\n");
		printf("%s\n", c2);
	}
	close(f2);
	exit(0);
}