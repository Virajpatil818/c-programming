#include <stdio.h>
#include <stdlib.h>

struct abc{
    char name[20];
    int id;
    int phone;
    int salary;
    struct abc *prev;
    struct abc *next;
};

struct abc *head=NULL;

void insert(){
    struct abc *new;
    struct abc *temp;
    new=(struct abc *)malloc(sizeof(struct abc));
    printf("\nEnter name :");
    scanf(" %s",new->name);
    printf("Enter ID :");
    scanf(" %d",&new->id);
    printf("Enter phone number : ");
    scanf(" %d",&new->phone);
    printf("Enter salary : ");
    scanf(" %d",&new->salary);
    new->prev=NULL;
    new->next=NULL;

    if(head==NULL){
        head=new;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
    }
}

struct abc *delete(){
    int i,count=1;
    printf("\nEnter ID number to delete : ");
    scanf(" %d",&i);

    struct abc *temp=head;

    while(temp->id!=i){
        temp=temp->next;
    }

    if(count==1){
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    else{
        temp->prev->next=temp->next;
        free(temp);
    }
    return head;
}

void Dforward(){
    struct abc *temp=head;
    printf("ID \tName \tPhone \tsalary\n"); 
    while(temp!=NULL){
        printf("%d \t%s \t%d \t%d \n",temp->id,temp->name,temp->phone,temp->salary);
        temp=temp->next;
    }
}

void Dbackward(){
    struct abc *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    printf("ID \tName \tPhone \tsalary\n");   
    while(temp!=NULL){
        printf("%d \t%s \t%d \t%d \n",temp->id,temp->name,temp->phone,temp->salary);
        temp=temp->prev;
    }
}

void modify(){
    int i,id;
    printf("\nEnter ID to modify : ");
    scanf(" %d",&i);
    struct abc *temp=head;
    while(temp->id!=i){
        temp=temp->next;
    }
    printf("\nModify Data\n");
    printf("\nEnter name :");
    scanf(" %s",temp->name);
    printf("Enter ID :");
    scanf(" %d",&temp->id);
    printf("Enter phone number : ");
    scanf(" %d",&temp->phone);
    printf("Enter salary : ");
    scanf(" %d",&temp->salary);

}

void main(){
    int choice;
    do{
        printf("\n1.Insert\n2.Delete\n3.Modify\n4.Display Forward\n5.Display Backward\n");
        scanf(" %d",&choice);

        switch(choice){
            case 1:
             insert();
             break;
            case 2:
             head=delete();
             break;
            case 3:
             modify();
             break;
            case 4:
             Dforward();
             break;
            case 5:
             Dbackward();
             break;
        }
    }while(choice!=0);
}