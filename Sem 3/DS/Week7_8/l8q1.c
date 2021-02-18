// Add  two  long  positive  integers represented  using  circular  doubly  linked  list  with  header node.

#include <stdio.h>
#include <stdlib.h>

typedef struct node * nodeptr;

typedef struct node{
	nodeptr rlink, llink;
	int data;
}node;

nodeptr create(){
	nodeptr temp = malloc(sizeof(node));
	return temp;
}

void push(nodeptr *n,int x){
	if(*n == NULL){
		*n = create();
		(*n)->data = x;
		(*n)->llink = (*n)->rlink = *n;
	}
	else{
		nodeptr temp = *n;
		while(temp->llink != *n)
			temp = temp->llink;

		nodeptr newnode = create();
		newnode->data = x;
		temp->llink = newnode;
		newnode->rlink = temp;
		newnode->llink = *n;
		(*n)->rlink = newnode;
	}
}

nodeptr read(){
	nodeptr head;
	char str[100];
	int i;
	scanf("%s",str);
	nodeptr n = create();
	n->llink = n->rlink = n;
	for(i=0;str[i];i++)
		push(&n,str[i]-'0');
	return n;
}

nodeptr add(nodeptr A, nodeptr B)
{
	int digit, sum, carry=0;
	nodeptr head,r,R,a,b;
	a=A->rlink;
	b=B->rlink;
	head = create();
	head->llink = head->rlink = head;
	while(a!=A && b!=B){
		sum = a->data + b->data +carry;
		digit = sum%10;
		carry = sum/10;
		push(&head,digit);
		a=a->rlink;
		b=b->rlink;
	}

	if(a!=A){
		r=a;
		R=A;
	}
	else{
		r=b;
		R=B;
	}
	while(r!=R){
		sum = r->data + carry;
		digit = sum%10;
		carry = sum/10;
		push(&head,digit);
		r = r->rlink;
	}

	if(carry)
		push(&head,carry);
	return head;
}

void display(nodeptr *n){
	for(nodeptr temp=(*n)->rlink; temp!=*n; temp=temp->rlink)
		printf("%d",temp->data);
	printf("\n");
}

int main()
{	
	printf("Enter two numbers:\n");
	nodeptr A,B,sum;
	A = read();
	B = read();
	sum = add(A,B);
	printf("Sum: ");
	display(&sum);
	return 0;
}