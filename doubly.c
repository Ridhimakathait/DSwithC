#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}sl;

sl* createnode(int data){
    sl* ptr=(sl*)malloc(sizeof(sl));
    ptr->data=data;
    ptr->prev=NULL;
    ptr->next=NULL;
}

void traverse(sl* head){
    sl* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
        
}

sl* insertatfirst(sl* head,int data){
    sl* ptr=createnode(data);
    ptr->next=head;
    head->prev=ptr;
    head=ptr;
    return head;
}

sl* insertatend(sl* head,int data){
    sl* ptr=createnode(data);
    sl* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->prev=p;
    return head;
}

sl* insertbetween(sl* head,int index,int data){
    sl* ptr=createnode(data);
    sl* prev=head;
    int i=0;
    while(prev!=NULL && i<index-1){
        prev=prev->next;
        i++;
    } 
    ptr->next=prev->next;
    prev->next->prev=ptr;
    prev->next=ptr;
    ptr->prev=prev;

    return head;
}


void main(){
    sl* head;
    sl* second;
    sl* third;
    sl* fourth;
    head=createnode(4);
    second=createnode(8);
    third=createnode(10);
    fourth=createnode(44);

    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=fourth;
    fourth->prev=third;
    
    traverse(head);
    head=insertatfirst(head,9);
    traverse(head);
    head=insertatend(head,89);
    traverse(head);
    head=insertbetween(head,2,1014);
    traverse(head);
    
}