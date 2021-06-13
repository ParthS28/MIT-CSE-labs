#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
int max(int a, int b); 
int height(struct node* node); 

struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	
	return(node); 
} 

int diameter(struct node *root){
    if(root == NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(lh+rh+1, max(ld, rd));
}

int height(struct node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int max(int a, int b){
    return a>b?a:b;
}

int main(){
    /*
    Tree - 
                1
            2       3
        4   5
      8|10  6
        9   7  

    */
    struct node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
    root->left->right->left = newNode(6);
    root->left->right->left->left = newNode(7);
	root->left->left->left  = newNode(8);
    root->left->left->left->left  = newNode(9);
	root->left->left->right  = newNode(10); 

	printf("Diameter of the given Binary Tree is %d\n", diameter(root)); 
}