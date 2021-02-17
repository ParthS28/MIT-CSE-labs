// Implement a queue with two stacks without transferring the elements of the second stack back to stack one. 
// (use stack1 as an input stack and stack2 as an output stack).

#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node** top, int data);
int pop(struct node** top);
struct queue
{
	struct node *stack1;
	struct node *stack2;
};

void enqueue(struct queue *q, int x)
{
	push(&q->stack1, x);
}
void dequeue(struct queue *q)
{
	int x;
	if (q->stack1 == NULL && q->stack2 == NULL) {
	printf("queue is empty");
	return;
	}
	if (q->stack2 == NULL) {
		while (q->stack1 != NULL) {
			x = pop(&q->stack1);
			push(&q->stack2, x);
		}
	}
	x = pop(&q->stack2);
	printf("Deleted: %d\n", x);
}

void push(struct node** top, int data) {
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	if (newnode == NULL) {
		printf("Stack overflow \n");
		return;
	}
	newnode->data = data;
	newnode->next = (*top);
	(*top) = newnode;
}

int pop(struct node** top){
	int buff;struct node *t;
	if (*top == NULL) {
		printf("Stack underflow \n");
	}
	else {
		t = *top;
		buff = t->data;
		*top = t->next;
		free(t);
		return buff;
	}
}

void display(struct node *top1,struct node *top2)
{
	while (top1 != NULL) {
	printf("%d ", top1->data);
	top1 = top1->next;
	}
	while (top2 != NULL) {
	printf("%d ", top2->data);
	top2 = top2->next;
	}
	printf("\n");
}
int main(){
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	int f = 0, a;
	// char ch = 'y';
	q->stack1 = NULL;
	q->stack2 = NULL;
	do {
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &f);
		switch(f) {
		case 1 : printf("Enter element: ");
		scanf("%d", &a);
		enqueue(q, a);
		break;
		case 2 : dequeue(q);
		break;
		case 3 : display(q->stack1, q->stack2);
		break;
		case 4 : printf("Exiting\n");
		break;
		default : printf("invalid\n");
		break;
		}
	}while(f != 4);
	return 0;
}