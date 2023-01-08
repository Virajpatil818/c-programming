#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct tree{
    char data;
    struct tree *left;
    struct tree *right;
};

int top=-1;
struct tree *stack[20];

void push(struct tree *root){
    top=top+1;
    stack[top]=root;
    printf("\nStack Data :%p",stack[top]);
}

struct tree *pop(){
    return stack[top--];
}

void inorder(struct tree *root){
    if(root==NULL){
        return ;
    }
    else{
        if(root!=NULL){
            inorder(root->left);
        }
        printf(" %c",root->data);
        inorder(root->right);
    }
}

void operand(char b){
    struct tree *root;
    root=(struct tree *)malloc(sizeof(struct tree));
    root->data=b;
    root->left=NULL;
    root->right=NULL;
    printf("\n%c",root->data);
    printf("\nOperand address : %p",root);
    push(root);
}

void operator(char a){
    struct tree *root;
    root=(struct tree *)malloc(sizeof(struct tree));
    root->data=a;
    printf("\nOperator Data : %c",root->data);
    root->right=pop();
    root->left=pop();
    push(root);
}

void main(){
    int i=0;
    char exp[20];
    printf("Enter expression in postfix\n");
    scanf(" %s",exp);

    while(exp[i]!='\0'){
        if(isalnum(exp[i])){
            printf("\nOperand : %c",exp[i]);
            operand(exp[i]);
        }
        else{
            printf("\nOperator : %c",exp[i]);
            operator(exp[i]);
        }
        i++;
    }
    printf("\nThe Inorder traversal of the tree is :");
    inorder(stack[top]);
    printf("\n");
}
