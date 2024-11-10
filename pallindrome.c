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

node* reverse(node* head){
    node* prev=NULL;
    node* curr=head;
    node* temp=NULL;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
int ispallindrome(node* head){
    node* slow=head;
    node* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    node* secondstart=reverse(slow->next);
    node* secondcopy=secondstart;
    node* firststart=head;
    int res=1;
    while(secondstart!=NULL){
        if(firststart->data!=secondstart->data){
            res=0;
        }
    firststart=firststart->next;
    secondstart=secondstart->next;
    }
    slow->next=reverse(secondcopy);
    return res;
}



int main(){
    node *head=(node*)malloc(sizeof(node));

    head=createnode(2);
    head->next=createnode(1);
    head->next->next=createnode(3);
    head->next->next->next=createnode(1);
    head->next->next->next->next=createnode(2);
    head->next->next->next->next->next=NULL;

    node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

    if(ispallindrome(head))
        printf("pallindrome");
    else
        printf("not");

    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;

}