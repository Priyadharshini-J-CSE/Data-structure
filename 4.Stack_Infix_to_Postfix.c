#include<stdlib.h>
#include<stdio.h>
struct stack{
    char * arr;
    int size;
    int top;;
};
struct stack * createStack(int size){
struct stack * s=(struct stack *)malloc(sizeof(struct stack));
s->arr=(int *)malloc(size*sizeof(int));
s->top=-1;
s->size=size;
return s;
}
int priority(char ch){
    if(ch=='^') return 3;
   else if(ch=='*' || ch=='/') return 2;
   else if(ch=='+' || ch=='-') return 1;
   else return -1;

}

int isempty(struct stack * s){
    if(s->top==-1) return 1;
    else return 0;
}
int isfull(struct stack * s){
    if(s->top+1==s->size) return 1;
    else return 0;
}
void push(struct stack *s,char ch){
    if(isfull(s)) printf("Stack Overflow\n");
    else{
        s->arr[++s->top]=ch;
    }
}
char pop(struct stack*s){
    if(isempty(s)) {
        printf("Stack overflow");
        return '$';
    }
    else{
        return s->arr[s->top--];
    }
}
char peek(struct stack *s){
    if(isempty(s)) {
        printf("Stack overflow");
        return '$';
    }
    else{
        return s->arr[s->top];
    }
}
int main(){
    struct stack * s=NULL;
    int size;
    char arr[100],ch;
    char postfix[100];
    int j=0;
    scanf("%s%n",arr,&size);
    s=createStack(size);

    for(int i=0;i<size;i++){
        ch=arr[i];
        switch(ch){
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
            push(s,ch);
            break;
            case 'a' ... 'z':
            postfix[j++]=ch;
            break;
  
        }
    }
    for(;j<size;j++){
    postfix[j]=s->arr[s->top--];
    }
    printf("%s",postfix);
    
    return 0;
}