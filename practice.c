#include<stdio.h>
#include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node *next;
// }node;

// node* createnode(int data){
//     node *new=(node*)malloc(sizeof(node));
//     new->data=data;
//     new->next=NULL;
//     return new;
// }

// void traverse(node* head){
//     node* temp=head;
//     while(temp!=NULL){
//         printf("%d ",temp->data);
//         temp=temp->next;
//     }
//     printf("\n");
// }

// node* insertatbegin(node* head,int data)
// {
//     node* ptr=(node*)malloc(sizeof(node));
//     ptr->data=data;
//     ptr->next=head;
//     return ptr;
// }

// node* insertbetween(node* head,int data,int pos){
//     node* ptr=(node*)malloc(sizeof(node));
//     ptr->data=data;
//     node* temp=head;
//     int i=1;
//     if(pos==1)
//         head=insertatbegin(head,data);
//     while(i!=pos-1){
//         temp=temp->next;
//         i++;
//     }
//     ptr->next=temp->next;
//     temp->next=ptr;
//     return head;
// }

// node* insertatlast(node* head,int data){
//     node* ptr=(node*)malloc(sizeof(node));
//     ptr->data=data;
//     node* last=head;
//     while(last->next!=NULL){
//         last=last->next;
//     }
//     last->next=ptr;
//     ptr->next=NULL;
//     return head;
// }

// node* rev(node* head){
//     node* prev=NULL;
//     node* curr=head;
//     node* temp=NULL;

//     while(curr!=NULL){
//         temp=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=temp;
//     }
//     return prev;
// }

// node* deletebetween(node* head,int pos){
//     node* temp=head;
//     node* prev=NULL;
//     int i=1;
//     while(i!=pos && temp!=NULL){
//         i++;
//         prev=temp;
//         temp=temp->next;
//     }
//     prev->next=temp->next;
//     free(temp);
//     return head;

// }
// void main(){
//     node* head=createnode(23);
//     head->next=createnode(45);
//     head->next->next=createnode(89);

//     traverse(head);

//     head=insertatbegin(head,78);
//     traverse(head);

//     head=insertbetween(head,890,2);
//     traverse(head);

//     head=insertatlast(head,123456);
//     traverse(head);

//     head=rev(head);
//     traverse(head);

//     head=deletebetween(head,3);
//     traverse(head);

// }

int operator(char exp){
    if(exp=='^'||exp=='*'||exp=='/'||exp=='+'||exp=='-')
        return 1;
}

int precedence(char exp){
    if(exp=='^')
        return 3;
    else if(exp=='/'||exp=='*')
        return 2;
    else
        return 1;
}

void push(int stack[],int *top,char exp){
    top++;
    stack[top]=exp;
    
}

int pop(int stack[],int *top){

    return stack[top];
    top--;
}

void main(){
    char  exp[10],post[10]={};
    int top=-1;
    int stack[10];
    int i=0,k=0;
    printf("Enter the expression: ");
    gets(exp);
    while(exp[i]!='\0'){
        if(exp[i]=='(')
            push(stack,&top,exp[i]);
        else if(exp[i]==')'){
        while(pop(stack,top)!='(')
                post[k++]=pop(stack,top);
        }
        else if(operator){
            while(top!=-1&&precedence(exp[i])<=precedence(pop(stack,top)))
                post[k++]=pop(stack,top);
            
        }
        i++;
    }

}