#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}sl; 

sl* createnode(int data){
    sl* ptr=(sl*)malloc(sizeof(sl));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void traverse(sl* head){
    sl* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void main(){
    sl *head1;
    sl *ptr1;
    int n;
    printf("enter head ptr 1 data:::");
    scanf("%d",&n);
    head1=createnode(n);
    sl* curr1=head1;
    while(1){
        printf("do you want to continue:::");
        scanf("%d",&n);
        if(n==0)
            break;
        scanf("%d",&n);
        ptr1=createnode(n);
        curr1->next=ptr1;
        curr1=ptr1;
    }
    traverse(head1);

    sl *head2;
    sl *ptr2;
    printf("enter head ptr 2 data:::");
    scanf("%d",&n);
    head2=createnode(n);
    sl* curr2=head2;
    while(1){
        printf("do you want to continue:::");
        scanf("%d",&n);
        if(n==0)
            break;
        scanf("%d",&n);
        ptr2=createnode(n);
        curr2->next=ptr2;
        curr2=ptr2;
    }
    traverse(head2);


    sl *head3=NULL;
    sl *ptr3;sl* curr3;
    int sum,carry=0;
    ptr1=head1;
    ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL){
        sum=ptr1->data+ptr2->data+carry;
        
        if(sum<10)
            carry=0;
        else
            carry=1;
        ptr3=createnode(sum%10);
        if(head3==NULL){
            head3=ptr3;
            curr3=head3;}
        else{
            curr3->next=ptr3;
            curr3=ptr3;}
        
        ptr1=ptr1->next;ptr2=ptr2->next;
    }
    if(carry==1){
        ptr3=createnode(1);
        curr3->next=ptr3;
        
    }
    traverse(head3);


}