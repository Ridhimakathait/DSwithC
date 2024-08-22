#include<stdio.h>
#define max 10
int enq(int [],int,int);
int deq(int [],int,int);
void disp(int [],int,int);
void peek(int [],int,int);


int main(){
    int cq[max],n,ch,f=-1,r=-1;
    do{
        printf("1.enqueue\n2.dequeue\n3.display\n4.peek\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                r=enq(cq,f,r);
                if(f==-1)
                    f=0;
                break;
            case 2:
                f=deq(cq,f,r);
                if(f==-1)
                    r=-1;
                break;
            case 3:
                disp(cq,f,r);
                break;
            case 4:
                peek(cq,f,r);
                break;
        }
    }while(ch<=4);
    return 0;
}

int enq(int cq[],int f,int r){
    int x;
    if(((r+1)%max)==f){
        printf("overflow\n");
    }
    else{
        r=(r+1)%10;
        printf("enter the value:");
        scanf("%d",&x);
        cq[r]=x;
        
    }
    return r;
}

int deq(int cq[],int f,int r){
    int x;
    if(f==-1&&r==-1){
        printf("underflow\n");
    }
    else{
        printf("dequed value\n");
        x=cq[f];
        printf("%d\n",x);

        if(f==r)
            f=-1;
        else
            f=(f+1)%max;
    }
    return f;
}
void disp(int cq[],int f,int r){
    if(f==-1){
        printf("empty stack\n");
    }
    else{
        for(int i=f;i<=r;i++){
            printf("%d ",cq[i]);
        }
    }

}

void peek(int cq[],int f,int r){
    if(f==-1){
        printf("empty stack\n");
    }
    else{
        printf("%d",cq[f]);
    }
}