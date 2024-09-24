#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
    int data;
    struct linkedlist *next;
}sl;

void main(){
    sl *head=NULL;
    sl *ptr=NULL;
    head=(sl*)malloc(sizeof(sl));
    ptr=(sl*)malloc(sizeof(sl));
    printf("enter data:");int n,ch;
    scanf("%d",&n);
    head->data=n;
    head->next=NULL;

    ptr=head;
    do{
        printf("do you want to enter more(1/0):");
        scanf("%d",&ch);
        sl *newnode=(sl*)malloc(sizeof(sl));
        if(ch==1){
            printf("enter data:");
            scanf("%d",&n);
            newnode->data=n;
            newnode->next=NULL;
            ptr->next=newnode;
            ptr=newnode;}
    }while(ch==1);

   

    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

    sl *prev=NULL,*curr=head,*temp=NULL;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    ptr=prev;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

}