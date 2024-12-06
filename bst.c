#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node *left;
    int data;
    struct node *right;
}node;

node* createnode(int data){
    node *n=(node*)malloc(sizeof(node));
    n->left=NULL;
    n->data=data;
    n->right=NULL;
    return n;

}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

node *search(node *root,int target){
    if(root==NULL)
        return NULL;
    else{
        if(root->data==target)
            return root;
        else if(root->data>target)
            return search(root->left,target);
        else
            return search(root->right,target);
    }
}

node *searchitr(node *root,int target){
    while(root!=NULL){
        if(root->data==target)
            return root;
        else if(root->data>target)
            root=root->left;
        else
            root=root->right;
    }
    return NULL;
}

void insert(node *root,int key){

    node *prev=(node*)malloc(sizeof(node));


    while(root!=NULL){
        prev=root;
        if(key==root->data)
            return; 
        else if(key<root->data)
            root=root->left;
        else if(key>root->data)
            root=root->right;
    }




    node *new=createnode(key);

    if(key<prev->data)
        prev->left=new;
    else
        prev->right=new;

}

int main(){
    node *root=createnode(34);
    node *lc=createnode(3);
    node *lc1=createnode(1);
    node *lc2=createnode(9);
    node *rc=createnode(64);
    
    //        34
    //       /  \
    //      3    64
    //     / \
    //    1   9

    root->left=lc;
    lc->left=lc1;
    lc->right=lc2;
    root->right=rc;

    
    
    inorder(root);

    // node *res=search(root,7);
    // if(res==NULL)
    //     printf("element not found");
    // else
    // printf("%d",res->data);

    insert(root,54);
    inorder(root);


    return 0;

}