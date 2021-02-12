// Implement a menu driven program to define a stack of characters. Include push, pop and
// display functions. Also include functions for checking error conditions such as underflow
// and overflow (ref. figure 1) by defining isEmpty and isFull functions. Use these function
// in push, pop and display functions appropriately. Use type defined structure to define a
// STACK containing a character array and an integer top. Do not use global variables.

#include <stdio.h>
#include <stdlib.h>
#include "stack_operations.h"

int main(){
	printf("Stack operations\n");
	Stack s;
	int ch = 0;
	do{
		ch = 0;
		printf("Menu: 1)Push 2)Pop 3)Display 4)Exit\n");
		scanf("%d", &ch);
		// printf("dhwj\n");
		switch(ch){
			case 1: 
			printf("Enter a character to push\n");
			char c;
			scanf(" %c", &c);
			push(&s, c);
			break;
			case 2: 
			printf("Popped character: ");
			char p = pop(&s);
			printf("%c\n", p);
			break;
			case 3:
			display(&s);
			break;
			case 4:
			printf("Exiting\n");
			break;
			default: printf("Invalid operation\n");
		}
	}while(ch != 4);
	return 0;
}