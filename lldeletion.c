#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist{
    int data;
    struct linkedlist * next;
}sl;

void traverselinkedlist(sl*);
sl* deletefirstnode(sl*);
sl* deletelastnode(sl*);
sl* deletebetween(sl*,int);

void main(){
    sl*head=(sl*)malloc(sizeof(sl));
    sl*second=(sl*)malloc(sizeof(sl));
    sl*third=(sl*)malloc(sizeof(sl));
    sl*fourth=(sl*)malloc(sizeof(sl));

    head->data=77;
    head->next=second;

    second->data=87;
    second->next=third;

    third->data=113;
    third->next=fourth;

    fourth->data=91;
    fourth->next=NULL;

    traverselinkedlist(head);
    head=deletebetween(head,8);
    traverselinkedlist(head);
    
}

void traverselinkedlist(sl *head){
    sl *p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

sl* deletefirstnode(sl *head){
    sl *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

sl* deletelastnode(sl *head){
    sl *ptr=head;
    sl* prev;
    while(ptr->next!=NULL){
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=NULL;
    free(ptr);
}
sl* deletebetween(sl* head,int index){
    sl* ptr=head;
    sl* prev=NULL;
    int i=0;
    while(i<index&&ptr!=NULL){
        prev=ptr;
        ptr=ptr->next;
        i++;
    }
    if(ptr!=NULL){
        prev->next=ptr->next;
        free(ptr);
    }

    else{
        printf("incorrect data");
    }
    return head;
}
