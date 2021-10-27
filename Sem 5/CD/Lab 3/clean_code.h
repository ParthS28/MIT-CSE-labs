// Header file to remove tabs and spaces
#include <stdio.h>
#include <stdlib.h>


void clean_code(){
	FILE *fa,*fb;
    int ca, cb;
    char* fname;
    // printf("Enter file name\n");
    // scanf("%s", fname);
    fname = "input_program.c";
	fa = fopen(fname,"r");
	if(fa == NULL){
		printf("Cannot open file \n");
		exit(0);
	}
    fb = fopen("cleanOut.c", "w");

    ca = getc(fa);
    while(ca != EOF){
        if(ca == ' '){
            putc(' ', fb);
            while(ca == ' '){
                ca = getc(fa);
            }
            putc(ca, fb);
        }
        else{
            putc(ca, fb);
        }
        ca = getc(fa);
    }
    fclose(fa);
    fclose(fb);
}