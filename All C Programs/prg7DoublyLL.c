#include <stdio.h>
#include <stdlib.h>

struct abc{
    char name[20];
    int id;
    struct abc *prev;
    struct abc *next;
};

void insert(struct abc *head){
    struct abc *new;
    new=(struct abc *)malloc(sizeof(struct abc));
    printf("\nEnter name of member : ");
    scanf(" %s",new->name);
    printf("\nEnter ID : ");
    scanf(" %d",&new->id);
    new->next=NULL;
    new->prev=NULL;
    
    new->next=head->next;
    new->next->prev=new;
    new->prev=head;
    head->next=new;
}

void secretary(struct abc *head){
    struct abc *new;
    new=(struct abc *)malloc(sizeof(struct abc));
    printf("\nEnter name of secretary : ");
    scanf(" %s",new->name);
    printf("\nEnter ID : ");
    scanf(" %d",&new->id);
    new->next=NULL;
    new->prev=NULL;

    new->prev=head;
    head->next=new;
}

struct abc *deletep(struct abc *head){
    struct abc *temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    free(temp);

    return head;
}

void deletes(struct abc *head){
    struct abc *temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void display(struct abc *head){
    struct abc *temp=head;
    int i=1;
    printf("SR \t Name \t Id \n");
    while(temp!=NULL){
        printf("%d \t %s \t %d \n",i,temp->name,temp->id);
        temp=temp->next;
        i++;
        printf("\n");
    }

}

void count(struct abc *head){
    struct abc *temp=head;
    int j=0;
    while(temp!=NULL){
        temp=temp->next;
        j++;
    }
    printf("Count : %d",j);
}

void main(){
    struct abc *head;
    head=(struct abc *)malloc(sizeof(struct abc));
    printf("\nEnter name of President : ");
    scanf(" %s",head->name);
    printf("\nEnter ID : ");
    scanf(" %d",&head->id);
    head->prev=NULL;
    head->next=NULL;

    secretary(head);
    int choice;
    do
    {
        printf("\n1.Insert member\n2.delete president\n3.delete secreatry\n4.count members\n5.display\n");
        scanf(" %d",&choice);

        switch(choice){
            case 1:
             insert(head);
             break;
            case 2:
             head=deletep(head);
             break;
            case 3:
             deletes(head);
             break;
            case 4:
             count(head);
             break;
            case 5:
             display(head);
             break;
        }
    } while (choice!=0);
    
}