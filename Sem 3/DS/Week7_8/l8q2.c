// Write a menu driven program to do the following using iterative functions:
// i) To create a BST for a given set of integer numbers
// ii)  To delete a given element from BST.
// iii) Display the elements using iterative in-order traversal.

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
	int key;
	struct node *left, *right;
}*Node;

typedef struct{
	Node S[MAX];
	int tos;
}Stack;

Node newNode (int item){
	Node temp = (Node)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void push(Stack *s, Node n){
	s->S[++(s->tos)] = n;
}

Node pop(Stack *s){
	return s->S[(s->tos)--];
}

void inorder(Node root){
	Node curr;
	curr = root;
	Stack S;
	S.tos = -1;
	push(&S, root);
	curr = curr->left;
	while (S.tos != -1 || curr != NULL){
		while (curr != NULL){
			push(&S, curr);
			curr = curr->left;
		}
		curr = pop(&S);
		printf("%d ", curr->key);
		curr = curr->right;
	}
	printf("\n");
}

Node insert (Node node, int key){
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}

Node minValueNode(Node node){
	Node current = node;
	while (current && current->left != NULL)
		current = current->left;
	return current;
}

Node deleteNode(Node root, int key){
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else{
		if (root->left == NULL){
		Node temp = root->right;
		free(root);
		return temp;
		}
		else if (root->right == NULL){
			Node temp = root->left;
			free(root);
			return temp;
		}
		Node temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main(){
	Node root = NULL;
	int k;
	printf("Enter the root:\t");
	scanf("%d", &k);
	root = insert(root, k);
	int ch;
	do{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit:\n");
		printf("Enter your choice:\n");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
			printf("Enter element to be inserted:\t");
			scanf("%d", &k);
			root = insert(root, k);
			break;
			case 2:
			printf("Enter element to be deleted:\t");
			scanf("%d", &k);
			root = deleteNode(root, k);
			break;
			case 3:
			inorder(root);
			break;
			case 4:
			printf("Exiting\n");
			break;
			default:
			printf("Invalid choice\n");
		}
	}while(ch < 4);
}