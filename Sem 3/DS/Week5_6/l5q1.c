// Implement a circular queue of Strings using structures. Include functions insertcq, deletecq and displaycq.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 10

typedef struct{
	char a[MAX][MAX];
	int f;
	int r;
	int count;
}cq;

void init(cq *q){
	q->f = 0;
	q->r = -1;
	q->count = 0;
}

int isFull(cq *q){
	if(q->count == MAX)
		return 1;
	return 0;
}

int isEmpty(cq *q){
	if(q->count == 0)
		return 1;
	return 0;
}

void displaycq(cq *q){
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return;
	}
	for (int i = q->f; i != q->r; i = (i + 1) % MAX){
		printf("%s\n", q->a[i]);
	}
	printf("%s\n", q->a[q->r]);
}

void insertcq(cq *q, char* s){
	if(isFull(q)){
		printf("Queue is full\n"); return;
	}
	q->r = (q->r + 1) % MAX;
	strcpy(q->a[q->r], s);
	q->count++;
}

void deletecq(cq *q){
	if (isEmpty(q)) {
	printf("Queue is empty\n"); return;
	}
	int temp = q->f;
	q->f = (q->f+1) % MAX;
	q->count--;
}

int main(){
	cq queue;

	cq* q = &queue;
	init(q);
	int ch;
	char* item = (char *)calloc(MAX, sizeof(char));
	do{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Input the element for insertion: ");
			scanf("%s", item);
			insertcq(q, item);
			break;
			case 2:
			deletecq(q);
			break;
			case 3:
			displaycq(q);
			break;
			case 4:
			printf("Exiting\n");
			break;
			default:
			printf("Invalid choice\n");
		}
	}while(ch != 4);
	return 0;
}