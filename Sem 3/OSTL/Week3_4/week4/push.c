#include "stack_header.h"
#define MAX 10

void push(stack *s, int n){
	if(s->top == MAX-1)
		return;
	s->arr[s->top] = n;
	s->top++;
}