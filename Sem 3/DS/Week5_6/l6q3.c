// Write a program to check whether given string is a palindrome using a dequeue. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct{
	char data[MAX];
	int rear,front;
}dequeue;

void init(dequeue *P)
{
	P->rear=-1;
	P->front=-1;
}

int empty(dequeue *P){
	if(P->rear==-1)
	return(1);
	return(0);
}

int full(dequeue *P){
	if((P->rear+1)%MAX==P->front)
		return(1);
	return(0);
}

void enqueueR(dequeue *P,char x){
	if(empty(P)){
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else{
		P->rear=(P->rear+1)%MAX;
		P->data[P->rear]=x;
	}
}

void enqueueF(dequeue *P,char x){
	if(empty(P)){
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}else{
		P->front=(P->front-1+MAX)%MAX;
		P->data[P->front]=x;
	}
}

char dequeueF(dequeue *P){
	char x;
	x=P->data[P->front];
	if(P->rear==P->front)
		init(P);
	else
		P->front=(P->front+1)%MAX;
	return x;
}

char dequeueR(dequeue *P){
	char x;
	x=P->data[P->rear];
	if(P->rear==P->front)
		init(P);
	else
		P->rear=(P->rear-1+MAX)%MAX;
	return x;
}

void print(dequeue *P){
	if(empty(P))
	{
		printf("Queue is empty");exit(0);
	}
	int i;
	i=P->front;
	while(i!=P->rear){
		printf("\n%c",P->data[i]);
		i=(i+1)%MAX;
	}
	printf("\n%c\n",P->data[P->rear]);
}

int main(){
	int i,x,n;
	int ans=0;
	char c[20];
	dequeue q;
	init(&q);
	printf("Enter string to check for palindrome\n");
	scanf("%s",c);
	n= strlen(c);
	for(i=0;i<n;i++){
		enqueueF(&q,c[i]);
	}
	for(i=0;i<n/2;i++){
		if(dequeueF(&q)!=dequeueR(&q))
		{
			ans = 1;
			break;
		}
	}
	if(ans == 0)
		printf("%s is palindrome\n",c);
	else
		printf("%s is not palindrome\n",c);
	return 0;
}