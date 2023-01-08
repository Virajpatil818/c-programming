#include <stdio.h>
#define N 5

int queue[N];
int front=-1,rear=-1;

void insert(int data){
    if(rear==(N-1) && front==0 || ((rear+1)%N==front)){
        printf("Queue is Full\n");
    }
    else if(rear==-1){
        front=0;
        rear=0;
        queue[rear]=data;
    }
    else{
        rear=((rear+1)%N);
        queue[rear]=data;
    }
}

void dequeue(){
    if(front==-1){
        printf("Queue is Empty\n");
    }
    else{
        if(front==rear){
            printf("Deleted element : %d",queue[front]);
            front=-1;
            rear=-1;
        }
        else{
            printf("Deleted element : %d",queue[front]);
            front=((front+1)%N);
        }
    }
}

void display(){
    int temp;
    temp=front;
    if(front==-1 && rear==-1){
        printf(" underflow \n");
    }
    else{
    while(temp!=rear){
        printf(" %d",queue[temp]);
        temp=((temp+1)%N);
    }
        printf(" %d",queue[temp]);

    }
}

void main(){
    int choice,data;
    do{
        printf("\n1.Insert\n2.Delete\n3.Display\n");
        scanf(" %d",&choice);

        switch(choice){
            case 1:
             printf("Enter data to Enter\n");
             scanf(" %d",&data);
             insert(data);
             break;
            case 2:
             dequeue();
             break;
            case 3:
             display();
             break;
        }
    }while(choice!=0);
}