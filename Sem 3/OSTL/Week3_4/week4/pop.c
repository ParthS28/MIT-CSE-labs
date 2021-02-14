#include "stack_header.h"
#define MAX 10

int pop(stack *s){
	if(s->top == -1)
		return 0;
	int n = s->arr[--(s->top)];
	return n;
}