// Convert a given decimal number to binary using stack.

#include <stdio.h>
#include <stdlib.h>
#include "stack_operations.h"

int main(){
	int dec;
	printf("Enter decimal: ");
	scanf("%d", &dec);
	if(dec > 511){
		printf("Number too big\n");
	}
	else{
		Stack s;
		while(dec != 0){
			push(&s, dec%2+'0');
			dec = dec/2;
		}
		while(isEmpty(&s) == 0){
			printf("%c", pop(&s));
		}
		printf("\n");
	}
}