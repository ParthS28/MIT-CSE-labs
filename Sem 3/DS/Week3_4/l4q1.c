// Evaluate a given prefix expression using stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_operations.h"

int eval(int a, int b, char x){
	if(x=='+')
		return(a+b);
	if(x=='-')
		return(a-b);
	if(x=='*')
		return(a*b);
	if(x=='/')
		return(a/b);
	if(x=='%')
		return(a%b);
}
int main(){
	char *str = (char *)calloc(10, sizeof(char));
	printf("Enter Expression\n");
	scanf("%s", str);
	Stack s; s.top = 0;
	// printf("%d\n", strlen(str));
	for(int i = strlen(str)-1; i >= 0; i--){
		// printf("%d\n", i);
		if(str[i]>='0' && str[i]<='9'){
			int d = str[i]-'0'; 
			// printf("%d\n", d);
			push(&s, d);
			// display(&s);
		}

		else{
			int a = pop(&s);
			int b = pop(&s);
			int value = eval(a, b, str[i]);
			push(&s, value); 
		}
		// display(&s);

	}
	int ans = pop(&s);
	printf("Answer = %d\n", ans);

	return 0;
}