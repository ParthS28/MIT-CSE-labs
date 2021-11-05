// Program to remove spaces and comments
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int removeSpaceComment(){
	FILE *fin,*fout;
	int ca,cb;
	fin = fopen("input_program.c","r");
	if(!fin){
		printf("cannot open file\n");
		exit(0);
	}
	fout = fopen("space_out.c","w");
	ca = fgetc(fin);
	while(ca!=EOF){
		if(ca == ' ' || ca == '\t'){
			putc(' ',fout);
			while(ca == ' '||ca == '\t')
				ca = fgetc(fin);
		}
		if(ca == '/'){
			cb = fgetc(fin);
			if(cb == '/'){
				while(ca != '\n')
					ca = fgetc(fin);
			}
			else if(cb == '*'){
				do{
					while(ca != '*')
						ca = fgetc(fin);
					ca = fgetc(fin);
				}while(ca != '/');
			}
			else{
				putc(ca,fout);
				putc(cb,fout);
			}
		}
		else
			putc(ca,fout);
		ca = fgetc(fin);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
