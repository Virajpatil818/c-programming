#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree *left,*right;
};

struct tree *createNode(int data){
    struct tree *newNode;
    newNode=(struct tree *)malloc((sizeof(struct tree)));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

struct tree *insert(struct tree *root,int data){
    if(root==NULL){
        return createNode(data);
    }
    else if(data < root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }

    return root;
}

struct tree *search(struct tree *root,int data){
    if(root==NULL){
        printf("Tree is empty\n");
    }
    else if(data==root->data){
        printf("Found\n");
    }
    else if(data < root->data){
        search(root->left,data);
    }
    else if(data > root->data){
        search(root->right,data);
    }
    else{
        printf("Not Found\n");
    }
}

void inorder(struct tree *root){
    if(root==NULL){
        return;
    }
    else{
        if(root!=NULL){
            inorder(root->left);
        }
        printf(" %d",root->data);
        inorder(root->right);
    }
}

void postorder(struct tree *root){
    if(root==NULL){
        return;
    }
    else{
        if(root!=NULL){
            postorder(root->left);
        }
        postorder(root->right);
        printf(" %d",root->data);
    }
}

void preorder(struct tree *root){
    if(root==NULL){
        return;
    }
    else{
        if(root!=NULL){
            printf(" %d",root->data);
        }
        preorder(root->right);
        preorder(root->left);
    }
}

void main(){
    struct tree *root=NULL;
    int choice,data;

    do
    {
        printf("\n1.Insert\n2.Search\n3.Delete\n4.Traverse\n");
        scanf(" %d",&choice);

        switch(choice){
            case 1:
             printf("Enter data\n");
             scanf(" %d",&data);
             root=insert(root,data);
             break;
            case 2:
             printf("Enter data to Find\n");
             scanf(" %d",&data);
             search(root,data);
             break;
            case 3:
             break;
            case 4:
             printf("Inorder traverse :");
             inorder(root);
             printf("\npostorder traverse :");
             postorder(root);
             printf("\npreorder traverse :");
             preorder(root);
             break;
        }
    }while (choice!=0);    
}