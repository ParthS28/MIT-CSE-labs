#include <stdlib.h>
#include <stdio.h>
#define MAX 10

typedef struct{
	int top;
	int arr[MAX];
}stack;

int pop(stack *s);
void push(stack *s, int data);
void display(stack *s);