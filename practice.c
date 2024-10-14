#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* createnode(int data){
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    return new;
}

void traverse(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

node* insertatbegin(node* head,int data)
{
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

node* insertbetween(node* head,int data,int pos){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=data;
    node* temp=head;
    int i=0;
    while(i!=pos-1){
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    return head;
}

node

void main(){
    node* head=createnode(23);
    head->next=createnode(45);
    head->next->next=createnode(89);

    traverse(head);

    head=insertatbegin(head,78);
    traverse(head);

    head=insertbetween(head,890,3);
    traverse(head);

}