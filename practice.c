#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void readgraph(node* adj[],int v){
    int k,data;
    node* new;node *last;
    for(int i=0;i<v;i++){
        printf("enter the number of neigbours of %d:",i);
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            printf("enter neighbour %d of %d:",j,i);
            scanf("%d",&data);
            new=(node*)malloc(sizeof(node));
            new->data=data;
            new->next=NULL;

            if(adj[i]==NULL)
                adj[i]=new;
            else{
                last->next=new;
            }
            last=new;
        }
    }
}

void printgraph(node* adj[],int v){
    node *temp=NULL;
    
    for(int i=0;i<v;i++){
        printf("neighbours of %d ",i);
        temp=adj[i];
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void bfs(node *adj[],int visited[],int start,int v){
    int q[v],f=-1,r=-1;

    q[++r]=start;
    visited[start]=1;
    printf("%d",start);

    while(f<r){
        node *ptr=adj[q[++f]];
        while(ptr!=NULL){
            if(!visited[ptr->data]){
                visited[ptr->data]=1;
                printf("%d",ptr->data);
                q[++r]=ptr->data;
            }

            ptr=ptr->next;
        }
    }
}

void dfs(node *adj[],int visited,int start,int v){
    viisted[start]=1;
    printf("%d",start);
    node *ptr=adj[start];
    while(ptr!=NULL){
        if(!visited[ptr->data]){
            dfs(adj,visited,ptr->data,v);
        }
        ptr=ptr->next;
    }
}

void main(){
    int v,start;
    scanf("%d",&v);
    node *adj[v];
    int visited[v];
    for(int i=0;i<v;i++){
        adj[i]=NULL;
    }
    for(int i=0;i<v;i++){
        visited[i]=0;
    }
    readgraph(adj,v);
    printgraph(adj,v);
    printf("enter start:");
    scanf("%d",&start);
    bfs(adj,visited,start,v);
}