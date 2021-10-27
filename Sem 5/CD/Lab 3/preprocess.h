#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

const char *directives[] = {"#define","#include"};

int isDirective(const char *str){
	for(int i = 0;i<sizeof(directives)/sizeof(char*);i++){
		if(strncmp(str,directives[i],strlen(directives[i])) == 0){
			return 1;
		}
		
	}
	return 0;
}

int preprocess(){
	FILE *fa,*fb;
	char buff[2048];
	char* filename;
	// printf("enter filename to open:\n");
	// scanf("%s",filename);
    filename = "remCommentsOut.c";
	fa = fopen(filename,"r");
	
	fb = fopen("pre_out.c","w");
	if(!fa||!fb){
		printf("cannot open file\n");
		exit(0);
	}
	while(fgets(buff,2048,fa)){
		if(!isDirective(buff))
			fputs(buff,fb);
	}
	fclose(fa);
	fclose(fb);

}