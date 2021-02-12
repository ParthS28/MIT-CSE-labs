// Implement two stacks in an array.

#include <stdio.h> 
#include <stdlib.h> 

typedef struct TwoStacks 
{
	int* arr; 
	int size; 
	int top1, 
	top2;
}TwoStacks;

TwoStacks* init_Stack(int size)
{
	TwoStacks* s = (TwoStacks *)malloc(sizeof(TwoStacks));
	s->arr = (int *)calloc(size, sizeof(int));
	s->top1 = -1; 
	s->top2 = size;
	return s;
}

void push1(TwoStacks* s, int n)
{
	if(s->top1 < s->top2 -1)
	{
		s->top1++; 
		s->arr[s->top1] = n;
	}
	else
	{ 
		printf("Overflow\n");
		exit(0);
	}
}

void push2(TwoStacks* s, int n)
{
	if(s->top1 < s->top2 -1)
	{
		s->top2--; 
		s->arr[s->top2] = n;
	}
	else
	{ 
		printf("Overflow\n");
		exit(1);
	}
}

int pop1(TwoStacks* s, int sz)
{
	if(s->top1 >= 0)
	{
		int x = s->arr[s->top1]; 
		s->top1--;
		return x;
	}

	else
	{ 
		printf("Underflow\n");
		exit(1);
	}
}

int pop2(TwoStacks* s, int size)
{
	if(s->top2 < size)
	{
		int x = s->arr[s->top2]; 
		s->top2++;
		return x; 
	}
	else
	{ 
		printf("Underflow\n");
		exit(1);
	}
}

int main(int argc, char const *argv[])
{
	TwoStacks* s = init_Stack(5);
	printf("Pushing 1 to stack 1\n");
	push1(s, 1); 
	printf("Pushing 2 to stack 2\n");
	push2(s, 2); 
	printf("Pushing 3 to stack 2\n");
	push2(s, 3); 
	printf("Pushing 4 to stack 1\n");
	push1(s, 4); 
	printf("Pushing 5 to stack 2\n");
	push2(s, 5);
	printf("Popped Element from stack 1 is: %d\n", pop1(s, 5)); 
	printf("Popped Element from stack 1 is: %d\n", pop1(s, 5)); 
	printf("Pushing 6 to stack 2\n");
	push2(s, 6);
	printf("Popped Element from stack 2 is %d\n", pop2(s, 5)); 
	return 0;
}