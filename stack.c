#include<stdio.h>
#define max 10
int push(int [],int);
int pop(int [],int);
void display(int [],int);
void peek(int [],int);
void seek(int [],int);
int main(){
    int stack[max],top=-1,ch=0;
    
    do{
        printf("enter choice:\n1.push\n2.pop\n3.display\n4.peek\n5.seek\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                top=push(stack,top);
                break;
            case 2:
                top=pop(stack,top);
                break;
            case 3:
                display(stack,top);
                break;
            case 4:
                peek(stack,top);
                break;
            case 5:
                seek(stack,top);
                break;

        }

    }while(ch<=5);
    return 0;
}

int push(int stack[],int top){
    int x;
    if(top==max-1){
        printf("overflow");
    }
    else{
        top++;
        scanf("%d",&x);
        stack[top]=x;

    }
    return top;
}

int pop(int stack[],int top){
    int x;
    if(top==-1)
        printf("underflow");
    else{
        x=stack[top];
        top--;
        printf("%d",x);

    }
    return top;
}

void display(int stack[],int top){
    if(top==-1)
        printf("underflow");
    else{
        while(top>=0){
        printf("%d",stack[top]);
        top--;}
    }
}

void peek(int stack[],int top){
    if(top==-1)
        printf("underflow");
    else{
        printf("%d",stack[top]);
        top--;
    }
}

void seek(int stack[],int top){
    int x;
    scanf("%d",&x);
    if(top==-1)
        printf("underflow");
    else{
        while(top>=0){
        if(x==stack[top]){
            printf("%d",top);
            break;
        }
        top--;}
    }

}