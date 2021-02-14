#include "stack_header.h"
#define MAX 10

void display(stack *s){
	printf("Stack: \n");
	for(int i = 0; i < s->top; i++){
		printf("%d ", s->arr[i]);
	}
	printf("\n");
}
