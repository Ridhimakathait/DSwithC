#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createnode(int data){
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    return new;
}


node* insertatbegin(node* last,int data){
    node* ptr=createnode(data);
    ptr->next=last->next;
    last->next=ptr;
    return last;
}

node* insertatend(node** last, int data) {
    node* ptr = createnode(data);
    if (*last == NULL) {
        *last = ptr;
    } else {
        ptr->next = (*last)->next;
        (*last)->next = ptr;
        *last = ptr;
    }
    return *last;
}

node* insertbetween(node* last,int pos,int data){
    node* ptr=createnode(data);
    node* head=last;
    if(pos==1){
        insertatbegin(last,data);
    }
    int i=1;
    while(i<pos){
        head=head->next;
        i++;
    }
   
    ptr->next=head->next;
    head->next=ptr;
    
    return last;
}

void printlist(node* last){
    node* ptr=last->next;
    while(1){
        printf("%d ",ptr->data);
        ptr=ptr->next;
        if(ptr==last->next)
            break;
    }
    printf("\n");
}

int main(){
    node *head=(node*)malloc(sizeof(node));
    node *second=(node*)malloc(sizeof(node));
    node *third=(node*)malloc(sizeof(node));

    head->data=12;
    second->data=87;
    third->data=45;

    head->next=second;
    second->next=third;
    third->next=head;

    printlist(third);
    insertatbegin(third,100);
    printlist(third);
    insertatend(&third,6700);
    printlist(third);
    insertbetween(third,3,2);
    printlist(third);
    return 0;
}