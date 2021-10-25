// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// const char* directives[] = {"#include", "#define"};
// int isDirective(const char *str){
// 	for(int i = 0;i<sizeof(directives)/sizeof(char*);i++){
// 		if(strncmp(str,directives[i],strlen(directives[i])) == 0){
// 			return 1;
// 		}
		
// 	}
// 	return 0;
// }

// int main(){
// 	FILE *fa,*fb;
//     int ca, cb;
//     char* fname[100];
//     printf("Enter file name\n");
//     scanf("%s", fname);
// 	fa = fopen(fname,"r");
// 	if(fa == NULL){
// 		printf("Cannot open file \n");
// 		exit(0);
// 	}
//     fb = fopen("q2out.c", "w");

//     ca = getc(fa);
//     char* buf[1024];

//     while(fgets(buf, 1024, fa)){
// 		if(!isDirective(buf))
// 			fputs(buf,fb);
// 	}
//     fclose(fa);
//     fclose(fb);
// }

//remove preprocessor directives
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

int main(){
	FILE *fa,*fb;
	char buff[2048];
	char filename[100];
	printf("enter filename to open:\n");
	scanf("%s",filename);
	fa = fopen(filename,"r");
	
	fb = fopen("q2out.c","w");
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
