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

void preorder(node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
} 

void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
        
    }
}

int bst(node* root,node* max,node* min){
    if(root==NULL){
        return 1;
    }
    if((max!=NULL && root->data>=max->data) || (min!=NULL && root->data<=min->data))
        return 0;
    

    return bst(root->left,root,min) && bst(root->right,max,root);
}

int main(){
    node *root=createnode(34);
    node *lc=createnode(3);
    node *lc1=createnode(1);
    node *lc2=createnode(9);
    node *rc=createnode(64);
    
    //        34
    //       /  \
    //      3    74
    //     / \
    //    1   9

    root->left=lc;
    lc->left=lc1;
    lc->right=lc2;
    root->right=rc;

    
    
    inorder(root);
    printf("\n");
    int ans=bst(root,NULL,NULL);
    printf("%d",ans);
    return 0;

}