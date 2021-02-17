// Implement two circular queues of integers in a single array where first queue will run from 0 to N/2 
// and second queue will run from N/2+1 to N-1 where N is the size of the array.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 10

typedef struct{
	int* q;
	int size;
	int f1, f2;
	int r1, r2;
	int count1, count2;
}cqd;

void cqd_init(cqd* c, int n) {
	c->q = (int*)calloc(n, sizeof(int));
	c->size = n;
	c->r1 = -1;
	c->f1 = -1;
	c->r2 = (n / 2);
	c->f2 = (n / 2);
	c->count1 = 0;
	c->count2 = 0;
}

int cqd_empty(cqd* c, int qno) {
	if (qno == 1) {
		return !(c->count1);
	}
	else if (qno == 2) {
		return !(c->count2);
	}
}

int cqd_full(cqd* c, int qno) {
	if (qno == 1){
		return c->count1 == (c->size / 2) ? 1 : 0;
	}
	else if (qno == 2){
		return c->count2 == (c->size / 2) ? 1 : 0;
	}
}

void insertcqd(cqd* c, int qno, int e){
	if (qno == 1) {
		if (cqd_full(c, qno)) {
			printf("Queue 1 is full");
			return;
		}
		c->r1 = (c->r1 + 1) % (c->size / 2);
		c->q[c->r1] = e;
		if(cqd_empty(c, qno)){
			c->f1=c->r1;
		}
		c->count1++;
		return;
	}
	else if (qno == 2) {
		if (cqd_full(c, qno))
		{
			printf("Queue 2 is full");
			return;
		}
		c->r2 = (c->r2 + 1) % (c->size / 2) + c->size / 2;
		c->q[c->r2] = e;
		if(cqd_empty(c, qno)){
			c->f2=c->r2;
		}
		c->count2++;
		return;
	}
}

int deletecqd(cqd* c, int qno) {
	if (qno == 1) {
		if (cqd_empty(c, qno)) {
		printf("Queue 1 is empty\n");
		return 0;
		}
		int element = c->q[c->f1];
		c->f1 = (c->f1 + 1) % (c->size / 2);
		c->count1--;
		return element;
	}
	else if (qno == 2) {
		if (cqd_empty(c, qno)){
			printf("Queue 2 is empty\n");
			return 0;
		}
		int element = c->q[c->f2];
		c->f2 = (c->f2 + 1) % (c->size / 2) + (c->size / 2);
		c->count2--;
		return element;
	}
}

void display(cqd* c, int qno) {
	printf("Queue:\n");
	if (qno == 1) {
		if (cqd_empty(c, qno)) {
			printf("Queue 1 is empty");
			return;
		}
		for (int i = c->f1; i != c->r1; i = (i + 1) % (c->size / 2))
		{
			printf("%d, ", c->q[i]);
		}
		printf("%d\n", c->q[c->r1]);
	}
	else if (qno == 2) {
		if (cqd_empty(c, qno))
		{
			printf("Queue 2 is empty \n");
			return;
		}
		for (int i = c->f2; i != c->r2; i = (i + 1) % (c->size / 2) + (c->size / 2))
		{
			printf("%d, ", c->q[i]);
		}
		printf("%d\n", c->q[c->r2]);
	}
}

int main() {
	cqd cqdouble;
	cqd* c = &cqdouble;
	cqd_init(c, MAX);
	int n, ch, qno;
	do{
		printf("1 - Insert");
		printf("\n2 - Delete");
		printf("\n3 - Display");
		printf("\n4 - Exit");
		printf("\nEnter queue number and choice: ");
		scanf("%d %d", &qno, &ch);
		switch (ch)
		{
			case 1:
			printf("Enter value to be inserted: ");
			scanf("%d",&n);
			insertcqd(c, qno, n);
			break;
			case 2:
			deletecqd(c, qno);
			break;
			case 3:
			display(c, qno);
			break;
			case 4:
			printf("Exiting\n");
			break;
			default:
			printf("Invalid option");
		}
	}while(ch != 4);
	return 0;
}