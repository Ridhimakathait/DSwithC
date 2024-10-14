#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
    int data;
    struct linkedlist *next;
}sl;

sl*  create(int data){
    sl* newnode = (sl*)malloc(sizeof(sl));
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
}

void main(){
    sl* head1;sl* head2;
    head1=create(1);
    head1->next=create(2);
    head1->next->next=create(3);

    head2=create(1);
    head2->next=create(4);
    head2->next->next=create(3);

    
    
    sl* ptr1=head1;
    sl* ptr2=head2;

    while(ptr1!=NULL){
        int flag=0;
        ptr2=head2;
        while(ptr2!=NULL){
            if(ptr1->data==ptr2->data){
                flag=1;
                break;
            }
            ptr2=ptr2->next;
        }
        if(flag==1){
            printf("%d ",ptr1->data);
        }
        ptr1=ptr1->next;
        
    }
    // while(ptr1!=NULL){
    //     printf("%d",ptr1->data);
    //    ptr1=ptr1->next;
    // }
    // sl* ptr3=head1;
    // while(ptr2!=NULL){
    //     int found=0;
       
    //     while(ptr3!=NULL){
            
    //         if(ptr2->data==ptr3->data){
    //             found=1;
    //             break;
    //         }
    //         ptr3=ptr3->next;

    //     }
    //     if(!found)
    //         printf("%d",ptr2->data);
    //      ptr2=ptr2->next;
    //      ptr3=head1;
    // }

}




// void main(){
//     sl *head=NULL;
//     sl *ptr=NULL;
//     head=(sl*)malloc(sizeof(sl));
//     ptr=(sl*)malloc(sizeof(sl));
//     printf("enter data:");int n,ch;
//     scanf("%d",&n);
//     head->data=n;
//     head->next=NULL;

//     ptr=head;
//     do{
//         printf("do you want to enter more(1/0):");
//         scanf("%d",&ch);
//         sl *newnode=(sl*)malloc(sizeof(sl));
//         if(ch==1){
//             printf("enter data:");
//             scanf("%d",&n);
//             newnode->data=n;
//             newnode->next=NULL;
//             ptr->next=newnode;
//             ptr=newnode;}
//     }while(ch==1);

   

//     ptr=head;
//     while(ptr!=NULL){
//         printf("%d ",ptr->data);
//         ptr=ptr->next;
//     }

//     sl *prev=NULL,*curr=head,*temp=NULL;
//     while(curr!=NULL){
//         temp=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=temp;
//     }
//     ptr=prev;
//     while(ptr!=NULL){
//         printf("%d ",ptr->data);
//         ptr=ptr->next;
//     }

// }