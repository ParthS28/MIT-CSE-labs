// Implement a queue using singly linked list without header node.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*rear = NULL, *front = NULL;

int isEmpty (){
	return rear == NULL && front == NULL;
}

struct Node * newNode (int item){
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));

	if (node != NULL){
		node->data = item;
		node->next = NULL;
		return node;
	}
	else
	{
	printf ("Overflow\n");
	exit(0);
	}
}

void enqueue (int item){
	struct Node *node = newNode(item);

	if (front == NULL){
		front = node;
		rear = node;
	}
	else{
		rear->next = node;
		rear = node;
	}
}

int dequeue(){
	if (front == NULL){
		printf ("Underflow\n");
		exit (0);
	}
	struct Node *temp = front;
	front = front->next;
	int item = temp->data;
	free (temp);
	return item;
}

void display(){
	if(isEmpty()){
		printf("Empty queue\n");
		return;
	}
	printf("Queue: \n");
	struct Node* temp = front;
	while(1){
		printf("%d ", temp->data);
		if(temp == rear) break;
		temp = temp->next;
	}
	printf("\n");
}

int peek (){
	if (front != NULL){
		return front->data;
	}
	else{
		exit (0);
	}
}


int main (){
	printf("Inserting 1\n");
	enqueue (1);
	printf("Inserting 2\n");
	enqueue (2);
	printf("Inserting 3\n");
	enqueue (3);
	display();
	printf("Removing 1\n");
	int a = dequeue();
	display();
	printf("Removing 2\n");
	int b = dequeue();
	display();
	
	return 0;
}