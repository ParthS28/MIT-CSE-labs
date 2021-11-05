// Program to remove preprocessing directive. Function also returns the row number after removing the directives

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *directives[] = {"#define","#include"};

int isDirective(const char *str){
	for(int i = 0;i<sizeof(directives)/sizeof(char*);i++){
		if(strncmp(str,directives[i],strlen(directives[i])) == 0){
			return 1;
		}
		
	}
	return 0;
}

int removePreprocess(){
	FILE *fa,*fb;
	char buff[2048];
	char* filename;
	int row = 1;
	// printf("enter filename to open:\n");
	// scanf("%s",filename);
    filename = "space_out.c";
	fa = fopen(filename,"r");
	
	fb = fopen("pre_out.c","w");
	if(!fa||!fb){
		printf("cannot open file\n");
		exit(0);
	}
	while(fgets(buff,2048,fa)){
		if(!isDirective(buff))
			fputs(buff,fb);
		else{
			row++;
			fputs("\n", fb);
		}
	}
	fclose(fa);
	fclose(fb);

}

// int removePreprocess(){
// 	FILE *fin = fopen("space_out.c","r");
// 	char c= 0;
// 	char buf[100];
// 	buf[0] = '\0';
// 	int i = 0;
// 	char *include = "include",*define="define",*main = "main";
// 	int flag =0,row=1;
// 	while(c !=EOF){
// 		c = fgetc(fin);
// 		if(c == '#' && flag == 0){
// 			c = 'a';
// 			while(isalpha(c) != 0){
// 				c = fgetc(fin);
// 				buf[i++] = c;
// 			}
// 			buf[i] = '\0';
// 			if(strstr(buf,include) != NULL || strstr(buf,define) != NULL){
// 				row++;
// 				while(c != '\n')
// 					c = fgetc(fin);
// 			}
// 			else{
// 				while(c!='\n'){
// 					c = fgetc(fin);
// 				}
// 			}
// 			i = 0;
// 			buf[0] = '\0';
// 		}
// 		else{
// 			if(flag == 0){
// 				buf[i++] = c;
// 				buf[i] = '\0';
// 				if(strstr(buf,main) != NULL){
// 					flag = 1;
// 				}
// 				if(c == ' ' || c == '\n'){
// 					buf[0] = '\0';
// 					i = 0;
// 				}
// 			}
// 		}
// 	}
// 	fclose(fin);
// 	return row;
// }