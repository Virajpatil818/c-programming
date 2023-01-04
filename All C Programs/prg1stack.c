#include <stdio.h>
#include <stdlib.h>

int size ;
int i=-1;

struct abc{
    int data;
    struct abc *next;
};

 struct abc *top=NULL;

//push function to insert elements in stack 
void push(){
    struct abc *newNode;
    
    if(i==(size-1)){
        printf(" Stack is Full \n");
    }
    else{
        newNode=(struct abc *)malloc(sizeof(struct abc));
        printf(" Enter data\n");
        scanf(" %d",&newNode->data);
        newNode->next=NULL;
        if(top==NULL){
            top=newNode;
            i++;
        }
        else{
            newNode->next=top;
            top=newNode;
            i++;
        }
    }
}

//pop function to delete element from stack 
void pop(){
    struct abc *temp;
    temp=top;
    if(i==-1){
        printf(" stack is Empty\n");
    }
    else{
        temp=top;
        printf(" Popped element is : %d",temp->data);
        top=top->next;
        free(temp);
        i--;
    }
}

void display(){
    struct abc *temp;
    temp=top;
    if(i==-1){
         printf(" stack is Empty\n");
    } 
    else{
        while(temp!=NULL){
         printf(">%d",temp->data);
         temp=temp->next;
        }  
    } 
}


void main(){
    int choice;

    printf(" Enter size of stack \n");
    scanf(" %d",&size);

    do
    {
        printf("\n1.Push\n2.pop\n3.Display\n");
        scanf("%d",&choice);

       switch (choice)
       {
       case 1:
        
        push();
        break;
       case 2:
        pop();
        break;
       case 3:
        display();
        break;
       default:
        break;
       }

    } while (choice!=0);
        
}
