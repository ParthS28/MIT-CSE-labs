#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define TRUE 1
#define FALSE 0

typedef struct stack
{ 
char item[MAX];
int top; 
}stack;

int isEmpty(stack*); 
int isFull(stack*);
int push(stack*, char); 
char pop(stack*); 
void display(stack*); 
stack* init_stack(); 

int isEmpty(stack *s)
{
if(s->top == -1) return TRUE;
return FALSE;
}

int isFull(stack *s)
{ 
if(s->top == MAX - 1) return TRUE;
return FALSE;
}

int push(stack *s, char x)
{
if(isFull(s))
return FALSE;
s->item[++s->top] = x; return TRUE;
}

char pop(stack *s)
{ 
if(isEmpty(s)) return FALSE;
return(s->item[s->top--]);
}

void display(stack *s)
{ 
if(isEmpty(s)) return; 
int i;
for(i = 0; i <= s->top; i++) 
printf("%c ", s->item[i]);
printf("\n");
}

stack* init_stack()
{
stack* s = (stack *)malloc(sizeof(stack)); s->top = -1;
return s;
}