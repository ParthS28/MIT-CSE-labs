// Program to remove single and multiline comments from a given C file
// Also, removing string literals

#include <stdio.h>
#include <stdlib.h>

int remCom(){
	FILE *fa,*fb;
	int ca,cb;
    char* fname;
    // printf("Enter file name\n");
    // scanf("%s", fname);
    fname = "cleanOut.c";
	fa = fopen(fname,"r");
	if(fa == NULL){
		printf("Cannot open file \n");
		exit(0);
	}
	fb = fopen("remCommentsOut.c","w");
	ca = getc(fa);
	while(ca != EOF){
		if(ca == ' '){
			putc(ca,fb);
			while(ca == ' ') ca = getc(fa);
		}
		if(ca == '/'){
			cb = getc(fa);
			if(cb == '/'){
				while(ca != '\n') 
					ca = getc(fa);
			}
			else if(cb == '*'){
				do{
					while(ca !='*')
						ca = getc(fa);
					ca = getc(fa);
				}while(ca !='/');
			}
			else{
				putc(ca,fb);
				putc(cb,fb);
			}
		}
        else if(ca == '"'){
            ca = getc(fa);
            while(ca != '"'){
                ca = getc(fa);
            }
        }
		else putc(ca,fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}