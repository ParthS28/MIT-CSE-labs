// Perform UNION  and  INTERSECTION set  operations on  singly  linked  lists  with header node.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void display(struct Node *node){
	printf("List: \n");
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int push(struct Node ** head, int data){
	if(head == NULL){
		struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
		new_node->data = data;
		new_node->next = NULL;
		*head = new_node;
	}
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = (*head);
	(*head) = new_node;
}

int isPresent(struct Node *head, int data){
	struct Node *temp = head;
	while(temp != NULL){
		if(temp->data == data)
			return 1;
		temp = temp->next;
	}
	return 0;
}

struct Node * getUnion (struct Node *head1, struct Node *head2){
	struct Node *u = NULL;
	struct Node *t1 = head1, *t2 = head2;
	while (t1 != NULL){
		push (&u, t1->data);
		t1 = t1->next;
	}
	while (t2 != NULL){
		if (!isPresent (u, t2->data))
			push (&u, t2->data);
		t2 = t2->next;
	}
	return u;
}

struct Node * getIntersection (struct Node *head1, struct Node *head2){
	struct Node *i = NULL;
	struct Node *t1 = head1;
	while (t1 != NULL){
		if (isPresent (head2, t1->data))
			push (&i, t1->data);
		t1 = t1->next;
	}
	return i;
}

int main(){
	printf("Enter 5 elements for the first list: \n");
	int n;
	struct Node *h1 = NULL;
	for(int i = 0; i < 5; i++){
		scanf("%d", &n);
		push(&h1, n);
	}

	printf("Enter 5 elements for the second list: \n");
	struct Node *h2 = NULL;
	for(int i = 0; i < 5; i++){
		scanf("%d", &n);
		push(&h2, n);
	}

	display(h1);
	display(h2);

	struct Node *un = getUnion(h1, h2);
	struct Node *intersection = getIntersection(h1, h2);
	printf("Union\n");
	display(un);
	printf("Intersection\n");
	display(intersection);
	return 0;
}


