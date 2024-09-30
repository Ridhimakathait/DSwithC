#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *next;
    int data;
};

void traversal(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("Elements : %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node* insertbetween(struct node *head,int data,int index){
    struct node *ptr,*p;
    ptr=(struct node*)malloc(sizeof(struct node));
    p=head;

    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

int main()
{
    struct node *head,*second,*third;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;

    second->data=10;
    second->next=third;

    third->data=11;
    third->next=NULL;
    
     traversal(head);
    head=insertbetween(head,1,2);
     traversal(head);
    return 0;
}