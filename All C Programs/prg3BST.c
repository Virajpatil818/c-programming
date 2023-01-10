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

void search(struct tree *root,int data){
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
        preorder(root->left);
        preorder(root->right);
    }
}

struct tree * minValueNode(struct tree * temp){
    struct tree *current;
    current = temp;
    while (current != NULL && current->left != NULL)
        current = current->left;
  
    return current;
    
}

struct tree* deleteNode(struct tree* root, int key)
{
    // Step 1: Find the node to be deleted
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Step 2: If the node has no children (i.e., it is a leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Step 3: If the node has one child
        else if (root->left == NULL)
        {
            struct node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node* temp = root;
            root = root->left;
            free(temp);
        }
        // Step 4: If the node has two children
        else
        {
            struct tree* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
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
            printf("Enter data to delete\n");
             scanf(" %d",&data);
             root=deleteNode(root,data);
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
