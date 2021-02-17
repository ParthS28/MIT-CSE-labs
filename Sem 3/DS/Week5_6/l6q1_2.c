// Implement an ascending priority queue.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 10

typedef struct{
	int pri_que[MAX];
	int front, rear;
}pq;

void init(pq* q){
	q->front = -1;
	q->rear = -1;
}

void check(pq* q, int data)
{
	int i,j;
	for (i = 0; i <= q->rear; i++){
		if (data >= q->pri_que[i]){
			for (j = q->rear + 1; j > i; j--){
				q->pri_que[j] = q->pri_que[j - 1];
			}
			q->pri_que[i] = data;
			return;
		}
	}q->pri_que[i] = data;
}

void pqinsert(pq* q, int data)
{
	if (q->rear >= MAX - 1){
		printf("Queue overflow\n");
		return;
	}
	if((q->front == -1) && (q->rear == -1)){
		q->front++;
		q->rear++;
		q->pri_que[q->rear] = data;
		return;
	}
	else
		check(q, data);
	q->rear++;
}



void pqmindelete(pq* q){
	int i;
	if ((q->front==-1) && (q->rear==-1)){
		printf("\nQueue Underflow");
		return;
	}
	q->rear = q->rear - 1;
}

void display_pqueue(pq* q){
	if ((q->front == -1) && (q->rear == -1))
	{
		printf("\nQueue is empty");
		return;
	}
	printf("Queue:\n");
	for (; q->front <= q->rear; q->front++)
	{
		printf("%d ", q->pri_que[q->front]);
	}
	printf("\n");
	q->front = 0;
}

int main(){
	pq pri;
	pq* q = &pri;
	int n, ch;
	init(q);
	do{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch){
		case 1:
		printf("Enter value to be inserted: ");
		scanf("%d",&n);
		pqinsert(q, n);
		break;
		case 2:
		pqmindelete(q);
		break;
		case 3:
		display_pqueue(q);
		break;
		case 4:
		printf("Exiting\n");
		break;
		default:
		printf("\nInvalid option\n");
		}
	}while(ch != 4);
}