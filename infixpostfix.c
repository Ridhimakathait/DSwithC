#include<stdio.h>
char stack[50];
int top=-1;

int isalpnum(char);
int priority(char);
int push(char);
char pop();

void main(){
    char infix[50],postfix[50];
    int x,i=0,k=0;
    scanf("%s",infix);

    while(infix[i]!='\0'){
        if(isalpnum(infix[i]))
            postfix[k++]=infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]!=')'){
            while(stack[top]!='(')
                postfix[k++]=pop();
            pop();
        }
        else if(priority(infix[i])>=priority(stack[top]))
            push(infix[i]);
        postfix[k++]=pop();
        i++;
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k] = '\0';
    printf("%s",postfix);

}

int isalpnum(char c)
{
    if((c>=65&&c<=90) || (c>=97&&c<=122) || (c>='1'&&c<='9'))
        return 1;
    else
        return 0;
}

int priority(char c){
    if(c=='^')
        return 3;
    else if(c=='/'||c=='*')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
}

int push(char c){
    stack[++top]=c;
    return top;
}

char pop(){
    return stack[top--];
}
#include<stdio.h>
char stack[50];
int top=-1;

int isalpnum(char);
int priority(char);
void push(char);
char pop();

void main(){
    char infix[50],postfix[50];
    int x,i=0,k=0;
    scanf("%s",infix);

    while(infix[i]!='\0'){
        if(isalpnum(infix[i]))
            postfix[k++]=infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')'){
            while(stack[top]!='(')
                postfix[k++]=pop();
            pop();
        }
        else{
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[k++]=pop();
            }
            push(infix[i]);}
        i++;
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k] = '\0';
    printf("%s",postfix);

}

int isalpnum(char c)
{
    if((c>=65&&c<=90) || (c>=97&&c<=122) || (c>='1'&&c<='9'))
        return 1;
    else
        return 0;
}

int priority(char c){
    if(c=='^')
        return 3;
    else if(c=='/'||c=='*')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return 0;
}

void push(char c){
    stack[++top]=c;
    
}

char pop(){
    return stack[top--];
}