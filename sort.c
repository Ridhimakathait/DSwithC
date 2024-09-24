#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}sl;

void traverse(sl* head){
    sl* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
sl* merge(sl* first,sl* second){
    sl* res;
    if (first == NULL) return second; 
    if (second == NULL) return first;
    if(first->data < second->data){
        res=first;
        res->next=merge(first->next,second);
    }
    else{
        res=second;
        res->next=merge(first,second->next);
    }
    return res;
}

sl* mergesort(sl* head){
    if (head == NULL || head->next == NULL) return head;
    sl* slow=head;
    sl* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    sl* left=head;
    sl* right=slow->next;
    slow->next=NULL;

    left=mergesort(left);
    right=mergesort(right);

    head=merge(left,right);
    return head;
}

void main(){
    sl *head=(sl*)malloc(sizeof(sl));
    sl *second=(sl*)malloc(sizeof(sl));
    sl *third=(sl*)malloc(sizeof(sl));
    sl *fourth=(sl*)malloc(sizeof(sl));

    head->data=223;
    second->data=157;
    third->data=65;
    fourth->data=89;

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    traverse(head);
    head=mergesort(head);
    traverse(head);


}