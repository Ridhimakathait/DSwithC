#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
}q;

void enq(q* q,int data){
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    if(q->rear){
        q->rear->next=new;
        q->rear=new;
    }
    else{
        q->front=q->rear=new;
    }
}

void dq(q* q){
    if(q->front==NULL){
        printf("\nunderflow");
    }
    node* temp=q->front;
    q->front=q->front->next;
    printf("\ndequed element:%d",temp->data);
    free(temp);
}

void display(q* q){
    node* temp=q->front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main(){
    q* q;
    q->front=q->rear=NULL;
    enq(q,4);
    enq(q,5);
    enq(q,7);

    display(q);

    dq(q);
    display(q);
    dq(q);
    dq(q);
    dq(q);



}