// Determine whether a given string is palindrome or not using stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_operations.h"

int main(){
	char *str = (char *)calloc(5, sizeof(char));
	printf("Enter string\n");
	scanf("%s", str);

	Stack s;
	for(int i = 0; i < strlen(str); i++){
		push(&s, str[i]);
		// display(&s);
	}
	int c = 0, flag = 0;
	while(s.top > c){
		char e = pop(&s);
		// printf("%c\n", e);
		if(str[c] != e){
			flag = 1; break;
		}
		c++;
	}
	if(flag == 1)
		printf("Not a palindrome\n");
	else
		printf("Palindrome\n");
	return 0;
}