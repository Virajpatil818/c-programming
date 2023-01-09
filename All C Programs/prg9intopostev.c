#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct abc{
    char c;
    struct abc *next;
}*top=NULL;

void push(char op){
    struct abc *new;
    new=(struct abc *)malloc(sizeof(struct abc));
    new->c=op;
    new->next=NULL;

    if(top==NULL){
        top=new;
    }
    else{
        new->next=top;
        top=new;
    }
}


char pop(){
    char b;
    struct abc *temp;
    if(top==NULL){
        printf("overflow\n");
    }
    else if(top->next==NULL){
        temp=top;
        b=temp->c;
        top=NULL;
        free(temp);
    }
    else{
        temp=top;
        b=temp->c;
        top=top->next;
        free(temp);
    }
    return b;
}

int pre(char op){
    switch(op){
        case '^':return 3;
        break;
        case '*':return 2;
        break;
        case '/':return 2;
        break;
        case '+':return 1;
        break;
        case '-':return 1;
        break;
    }
}

int estack[20],etop=-1;

void epush(int op){
    etop++;
    estack[etop]=op;
}

int epop(){
    int a;
    a=estack[etop];
    etop--;
    return a;
}

void evaluate(char postfix[]){
    int i=0,num,n1,n2,n3;
    while(postfix[i]!='\0'){
        if(isdigit(postfix[i])){
            num=postfix[i]-48;
            epush(num);
        }
        else{
            n1=epop();
            n2=epop();

            switch(postfix[i]){
                case '^':n3=n2^n1;
                break;
                case '*':n3=n2*n1;
                break;
                case '/':n3=n2/n1;
                break;
                case '+':n3=n2+n1;
                break;
                case '-':n3=n2-n1;
                break;
            }
            epush(n3);
        }
        i++;
    }
    printf("\nEvatuation : %d\n",epop());
}

void main(){
    char infix[20],postfix[20];

    printf("\nEnter infix expression : ");
    scanf(" %s",infix);

    int i=0,j=0;

    while(infix[i]!='\0'){
        if(isalnum(infix[i])){
            postfix[j]=infix[i];
            j++;
        }
        else{
            if(top==NULL){
                push(infix[i]);
            }
            else{
                while(top!=NULL &&pre(top->c)>=pre(infix[i])){
                    postfix[j++]=pop();
                }
                push(infix[i]);
            }
        }
        i++;
    }
    while(top!=NULL){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("\nPostfix expression : %s",postfix);
    evaluate(postfix);
}
