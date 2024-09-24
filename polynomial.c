#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int coeff;
	int exp;
	struct node* next;
}sl;

sl* createnode(int coeff,int exp){
	sl* new=(sl*)malloc(sizeof(sl));
	new->coeff=coeff;
	new->exp=exp;
	new->next=NULL;
	}

void traverse(sl* head)
{
	sl* ptr=head;
	while(ptr!=NULL){
		printf("%d %d ",ptr->coeff,ptr->exp);
		ptr=ptr->next;
	}
	printf("\n");	
}

sl* merge(sl* first,sl* second){
    sl* res;
    if (first == NULL) return second; 
    if (second == NULL) return first;
    if(first->exp > second->exp){
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
	int n,l;
	printf("enter headptr data::::");
	scanf("%d%d",&n,&l);
	head=createnode(n,l);
	sl *curr=(sl*)malloc(sizeof(sl));
	sl *ptr=(sl*)malloc(sizeof(sl));
	curr=head;
	
	int ch=1;
	
	do{
		printf("enter node data:");
		scanf("%d%d",&n,&l);
		ptr=createnode(n,l);
		curr->next=ptr;
		curr=ptr;
		printf("do you still want to enter:");
		scanf("%d",&ch);
		
	
	}while(ch==1);
	traverse(head);
	
	sl *head2=(sl*)malloc(sizeof(sl));
	printf("enter headptr of second data::::");
	scanf("%d%d",&n,&l);
	head2=createnode(n,l);
	sl *curr2=(sl*)malloc(sizeof(sl));
	sl *ptr2=(sl*)malloc(sizeof(sl));
	curr2=head2;
	ch=1;
	
	do{
		printf("enter node2 data:");
		scanf("%d%d",&n,&l);
		ptr2=createnode(n,l);
		curr2->next=ptr2;
		curr2=ptr2;
		printf("do you still want to enter:");
		scanf("%d",&ch);
		
	
	}while(ch==1);
	traverse(head2);
	ptr=head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=head2;
	sl* head3=mergesort(head);
	traverse(head3);
		
}