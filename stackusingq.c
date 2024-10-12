#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct stack{
    node *head;
}stack;

void push(stack*,int);
void pop(stack*);
void display(stack*);
void seek(stack*,int);


void main(){
    stack* stack;
    stack->head=NULL;
    int ch,n;
    do{
        printf("enter choice:\n1.push\n2.pop\n3.display\n4.seek\n5.end\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter data:");
            scanf("%d",&n);
            push(stack,n);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
        display(stack);
        case 4:
            seek(stack,5);
        case 5:
            break;
        }
    }while(ch!=5);
}

void push(stack* stack,int data){
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=stack->head;
    stack->head=new;
}

void pop(stack* stack){
    if(stack->head==NULL)
        printf("UNDERFLOW");
    else{
        node* temp=stack->head;
        printf("%d",temp->data);
        stack->head=stack->head->next;
        free(temp);
    }
}

void display(stack* stack){
    node* temp=stack->head;
    if(temp==NULL)
        printf("empty stack");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}

void seek(stack* stack,int x){
    node* temp=stack->head;
    int i=0;
    while(temp!=NULL){
        if(temp->data==x){
        
            printf("%d",i);
            break;
        }
        i++;
        temp=temp->next;
    }

}