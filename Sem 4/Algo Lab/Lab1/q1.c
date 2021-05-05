#include<stdio.h>
#include<stdlib.h>


typedef struct node* nodeptr;
typedef struct node{
    int data;
    nodeptr left;
    nodeptr right;
}node;

nodeptr search(nodeptr root, int key){
    if (!root){
        nodeptr temp = (nodeptr)malloc(sizeof(node));
        temp->data = key;
        temp->left = temp->right = NULL;
        printf("Element inserted\n");
        return temp;
    }
    if (root->data == key){
        printf("Element found \n");
    }
    else if (root->data > key)
        root->left = search(root->left, key);
    else
        root->right = search(root->right, key);
    return root;
}

void inorder(nodeptr root){
    if (root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(nodeptr root){
    if (root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(nodeptr root){
    if (root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    nodeptr root = NULL;
    
    int ch;
    do{
        printf("Enter the option\n");
        printf("1) Search\n2) Inorder\n3) Preorder\n4) Postorder\n5) Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter the key ");
            int a;
            scanf("%d", &a);
            root = search(root, a);
            break;
            case 2:printf("Inorder:\n");
            inorder(root);
            printf("\n");
            break;
            case 3:printf("Preorder:\n");
            preorder(root);
            printf("\n");
            break;
            case 4:printf("Postorder:\n");
            postorder(root);
            printf("\n");
            break;
            default: printf("Exiting\n");
        }
    }while(ch != 5);
    return 0;
}