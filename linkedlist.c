#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
    int data;
    struct linkedlist *next;
}sl;

void linkedlisttraversal(sl*);
sl* insertatfirst(sl*,int);
sl* insertbetween(sl*,int,int);
sl* insertatend(sl*,int);
sl* insertafternode(sl*,sl*,int);

void main(){
    sl *head,*second,*third,*fourth;
    head=(sl*)malloc(sizeof(sl));
    second=(sl*)malloc(sizeof(sl));
    third=(sl*)malloc(sizeof(sl));
    fourth=(sl*)malloc(sizeof(sl));
    
    head->data=7;
    head->next=second;

    second->data=21;
    second->next=third;

    third->data=67;
    third->next=fourth;

    fourth->data=90;
    fourth->next=NULL;

    linkedlisttraversal(head);
    head=insertatfirst(head,88);
    linkedlisttraversal(head);
    head=insertbetween(head,3333,3);
    linkedlisttraversal(head);
    head=insertatend(head,100000);
    linkedlisttraversal(head);
    head=insertafternode(head,second,999999999);
    linkedlisttraversal(head);
}

void linkedlisttraversal(sl* head){
        while(head!=NULL){
            printf("%d\n",head->data);
            head=head->next;
        }
}

sl* insertatfirst(sl* head,int data){
    sl* ptr=(sl*)malloc(sizeof(sl));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

sl* insertbetween(sl* head,int data,int index){
    sl* ptr=(sl*)malloc(sizeof(sl));
    sl *p=head;
    int i=0;

    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

sl* insertatend(sl* head,int data){
    sl* ptr=(sl*)malloc(sizeof(sl));
    ptr->data=data;
    sl *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
   
sl* insertafternode(sl *head,sl *prevnode,int data){
    sl* ptr=(sl*)malloc(sizeof(sl));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;

}