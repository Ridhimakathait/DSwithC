#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}sl;

sl* createnode(int data){
    sl* ptr=(sl*)malloc(sizeof(sl));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;

}
void printlist(sl* last){
    sl* ptr=(sl*)malloc(sizeof(sl));
    ptr=last->next;
    do
    {
        printf("%d ",ptr->data);
       ptr=ptr->next;
    } while (ptr!=last->next);
    printf("\n");
}  

sl* deletenode1(sl* last){
    sl* ptr=last->next;
    last->next=ptr->next;
    free(ptr);
    return last;
}

sl* deletelastnode(sl* last){
    sl* ptr=last->next;
    sl* prev=NULL;
    while(ptr!=last){
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=ptr->next;
    free(ptr);
    return prev;
    
}

sl* deletebtw(sl* last,int index){

}

int main(){
    sl* head=(sl*)malloc(sizeof(sl));
    sl* second=(sl*)malloc(sizeof(sl));
    sl* third=(sl*)malloc(sizeof(sl));

    head=createnode(12);
    second=createnode(13);
    third=createnode(14);
    
    head->next=second;
    second->next=third;
    third->next=head;

    printlist(third);
    third=deletelastnode(third);
    printlist(third);

    return 0;
}