#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fa,*fb;
    int ca, cb;
    char* fname[100];
    printf("Enter file name\n");
    scanf("%s", fname);
	fa = fopen(fname,"r");
	if(fa == NULL){
		printf("Cannot open file \n");
		exit(0);
	}
    fb = fopen("q1out.c", "w");

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