#include<stdio.h>
#define max 10
int enq(int [],int);
int deq(int[],int,int);
void disp(int [],int,int);
void peek(int [],int,int);

int main(){
    int q[max],f=-1,r=-1,ch;
    do{
         printf("enter choice:\n1.enque\n2.deque\n3.display\n4.peek\n5.end\n");
         scanf("%d",&ch);
    switch(ch){
        case 1:
            r=enq(q,r);
            if(f==-1)
                f=0;
            break;
        case 2:
            f=deq(q,f,r);
            if(f==-1)
                r=-1;
            break;
        case 3:
            disp(q,f,r);
            break;
        case 4:
            peek(q,f,r);
            break;  

    }}while(ch<=4);
    return 0;
}

int enq(int q[],int r){
    int x;
    if(r==max-1)
        printf("overflow\n");
    else{
        r++;
        scanf("%d",&x);
        q[r]=x;
    }
    return r;
}

int deq(int q[],int f,int r){
    int x;
    if(f==-1)
      printf("empty queue\n");
    else{
        x=q[f];
        printf("%d\n",x);
        if(f==r)
            f=-1;
        else
             f++;
    }
    return f;
}


void disp(int q[],int f,int r){
   
    int i=f;
    if(f==-1)
        printf("empty queue\n");
    else{
        while(i<=r){
            printf("%d\n",q[i]);
            i++;
        }
        
    }
}

void peek(int q[],int f,int r){
    if(f==-1 && r==-1)
        printf("queue is empty\n");
    else
        printf("%d\n",q[f]);
}

