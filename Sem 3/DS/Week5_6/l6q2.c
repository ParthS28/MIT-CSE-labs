// Implement a queue of strings using an output restricted dequeue (no   deleteRight). 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct{
	int data[MAX];
	int front, rear;
}dequeue;

void init(dequeue *dq){
	dq->front = -1;
	dq->rear = -1;
}

int isEmpty(dequeue *dq){
	if(dq->front == -1 && dq->rear == -1)
		return 1;
	return 0;
}

int isFull(dequeue *dq){
	if((dq->rear+1) % MAX == dq->front)
		return 1;
	return 0;
}

void display(dequeue *q){
	if(isEmpty(q)){
		printf("Empty queue\n"); return;
	}
	printf("Queue:\n");
	int i = q->front;
	for(; i != q->rear+1; ++i%MAX){
		printf("%d ", q->data[i]);
	}
	printf("\n");
}

void enqueueR(dequeue *q, int x){
	if(isEmpty(q)){
		q->rear=0;
		q->front=0;
		q->data[0]=x;
	}
	else{
		q->rear=(q->rear+1)%MAX;
		q->data[q->rear]=x;
	}
}

void enqueueF(dequeue *q, int x)
{
	if(isEmpty(q)){
		q->rear=0;
		q->front=0;
		q->data[0]=x;
	}
	else{
		q->front = (q->front-1);
		q->data[q->front]=x;
	}
}

int dequeueF(dequeue *q){
	int x;
	x=q->data[q->front];
	if(q->rear==q->front)
		init(q);
	else
		q->front = (q->front+1) % MAX;
	return x;
}

int main(){
	dequeue dq;
	dequeue* q = &dq;
	int n, ch;
	init(q);
	do{
		printf("1.Insert - Rear\n");
		printf("2.Insert - Front\n");
		printf("3.Delete - Front\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch){
		case 1:
		printf("Enter value to be inserted: ");
		scanf("%d",&n);
		enqueueR(q, n);
		break;
		case 2:
		printf("Enter value to be inserted: ");
		scanf("%d",&n);
		enqueueF(q, n);
		break;
		case 3:
		dequeueF(q);
		break;
		case 4:
		display(q);
		break;
		case 5:
		printf("Exiting\n");
		break;
		default:
		printf("\nInvalid option\n");
		}
	}while(ch != 5);
}