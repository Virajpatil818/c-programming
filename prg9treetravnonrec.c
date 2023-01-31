#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root) {
    struct node *current = root;
    struct node *stack[100];
    int top = -1;
    
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorder(struct node *root) {
    struct node *current = root;
    struct node *stack[100];
    int top = -1;
    
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            printf("%d ", current->data);
            stack[++top] = current;
            current = current->left;
        }
        
        current = stack[top--];
        current = current->right;
    }
}

void postorder(struct node *root) {
    struct node *current = root;
    struct node *stack1[100];
    int top1 = -1;
    struct node *stack2[100];
    int top2 = -1;
    
    stack1[++top1] = current;
    while (top1 >= 0) {
        current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left) stack1[++top1] = current->left;
        if (current->right) stack1[++top1] = current->right;
    }
    
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

int main() {
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    
    return 0;
}
