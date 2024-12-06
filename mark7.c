#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node*left;
    int data;
    struct node*right;
}node;

node *createnode(int data){
    node *new=(node*)malloc(sizeof(node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    
}

int search(node *root,int key){
    if(root==NULL)
        return 0;
    else{
        if(root->data=key)
            return 1;
        else if(root->data>key)
            return(root->left,key);
        else
            return(root->right,key);
    }
}

node* insert(node *root,int data){
    node *newnode=createnode(data);
    node *prev;
    node *current=root;
    while(current!=NULL){
        prev=current;
        if(data<current->data)
            current=current->left;
        else
            current=current->right;
    }
    if(data<prev->data)
        prev->left=newnode;
    else
        prev->right=newnode;
    return root;
}
node *inorderpred(node *root){
    node *curr=root->left;
    while(curr->right!=NULL)
        curr=curr->right;
    return curr;
}


node *deletenode(node *root,int data){
  
    if(root==NULL)
        return NULL;
    if(root->right==NULL && root->left==NULL){
        free(root);
        return NULL;}
    
        if(data<root->data)
            root->left=deletenode(root->left,data);
        else if(data>root->data)
            root->right=deletenode(root->right,data);
        else{
            node *ipre=inorderpred(root);
            root->data=ipre->data;
            root->left=deletenode(root->left,ipre->data);}
    
    return root;
}

node *secondhigh(node *root){
    node *curr=root;
    if(root!=NULL || (root->right==NULL&&root->left==NULL))
        return NULL;
    while(curr->right->right!=NULL && curr->right->left==){
        curr=curr->right;}
    return curr;
}

void main(){
    node *root=createnode(5);            
    root->left=createnode(3);
    root->right=createnode(7);
    root->left->left=createnode(2);
    root->left->right=createnode(4);
    /*
          5
       /    \
      3      7
    /   \   / \
    2   4  6   8
                \
                 9   
    */
   //inorder(root);printf("\n");
   //int ans=search(root,7);
   //printf("%d",ans);printf("\n");
   insert(root,6);
   insert(root,8);
   insert(root,9);
   //deletenode(root,7);
   inorder(root);printf("\n");
   node *ans=secondhigh(root);
   printf("%d",ans->data);
}