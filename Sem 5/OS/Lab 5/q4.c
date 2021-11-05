#include<stdio.h>
#include<stdlib.h>
 
int main(){
    FILE* fptr;
    int num=0;
    fptr=fopen("q4.bin","wb+");
 
    printf("Enter 5 numbers: \n");
 
    for(int i = 0; i < 5; i++){
        scanf("%d",&num);
        fwrite(&num, sizeof(int), 1, fptr);
    }
 
    printf("Writing done!\n");
    fclose(fptr);
 
    fptr=fopen("q4.bin","rb");
 
    for(int i = 0; i < 5; i++){
        fread(&num,sizeof(int),1,fptr);
        printf("%d\n",num);
    }
 
}