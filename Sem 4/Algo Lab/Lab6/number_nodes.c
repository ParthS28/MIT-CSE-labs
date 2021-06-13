
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *createnode(int key){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}


int opcount = 0;
int countnodes(struct node *root){
    if(root == NULL){
        return 0;
    }
    else{
        opcount++;
        return 1+countnodes(root->left)+countnodes(root->right);
    }
}

int main(){
    int prev = 0;
    struct node* root = createnode(1);
    printf("The total no. of Nodes: %d\n", countnodes(root));
    printf("Opcount : %d\n",opcount);
    prev = opcount;
    root->right = createnode(3);
    printf("The total no. of Nodes: %d\n", countnodes(root));
    printf("Opcount : %d\n",opcount-prev);
    prev = opcount;
    root->left = createnode(2);
    printf("The total no. of Nodes: %d\n", countnodes(root));
    printf("Opcount : %d\n",opcount-prev);
    prev = opcount;
    root->left->right = createnode(5);
    printf("The total no. of Nodes: %d\n", countnodes(root));
    printf("Opcount : %d\n",opcount-prev);
    prev = opcount;
    root->left->left = createnode(4);
    printf("The total no. of Nodes: %d\n", countnodes(root));
    printf("Opcount : %d\n",opcount-prev);
    prev = opcount;
    root->right->left = createnode(6);
    printf("The total no. of Nodes: %d\n", countnodes(root));
    printf("Opcount : %d\n",opcount-prev);
    prev = opcount;
    root->right->right = createnode(7);
    printf("The total no. of Nodes: %d\n", countnodes(root));
    printf("Opcount : %d\n",opcount-prev);
    prev = opcount;
    root->left->left->right = createnode(8);
    printf("The total no. of Nodes: %d\n", countnodes(root));
    printf("Opcount : %d\n",opcount-prev);
    prev = opcount;
    root->left->left->left = createnode(9);
    printf("The total no. of Nodes: %d\n", countnodes(root));
    printf("Opcount : %d\n",opcount-prev);
    prev = opcount;
    root->left->right->left = createnode(10);
    printf("The total no. of Nodes: %d\n", countnodes(root));
    printf("Opcount : %d\n",opcount-prev);
    prev = opcount;
}