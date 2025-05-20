#include<stdio.h>
#include <stdlib.h>
struct stack{
    int * arr;
    int size;
    int top;
};
struct stack *createStack(int size){
    struct stack *ns=(struct stack*)malloc(sizeof(struct stack));
    ns->size=size;
    ns->arr=(int*)malloc(sizeof(int));
    ns->top=-1;
    return ns;
}
/*
isempty()
0 ->stack is not empty
1 -> stack is empty
*/
int isempty(struct stack *s){
    if(s->top==-1) return 1;
    else return 0;
}
/*
isfull()
0 -> stack is not full
1 -> stack is full
*/
int isfull(struct stack * s){
    if(s->top==s->size-1) return 1;
    else return 0;
}

void push(struct stack * s,int val){
    if(isfull(s)) printf("Stack is full\n");
    else{
        
       s->arr[++s->top]=val;
    }
    
}

int pop(struct stack * s){
    if(isempty(s)){
        // printf("Stack is Empty\n");
    //return random large value beacause -1 also shows that it(stack) has value
    return -9999;//flag value is return
    }
    else{
       return s->arr[s->top--];
    }
}
int peek(struct stack * s){
     if(isempty(s)){
        // printf("Stack is Empty\n");
    //return random large value beacause -1 also shows that it(stack) has value
    return -9999;//flag value is return
    }
    else
    return s->arr[s->top];
}
void display(struct stack *s){
    if(isempty(s)) 
    printf("Stack is empty\n");
    else{
        // for(int i=0;i<=s->top;i++){
            for(int i=s->top;i>=0;i--){
              printf("%d ",s->arr[i]);
        }
        printf("\n");

    }
}


int main()
{
    struct stack * s=NULL;
     int choice,size,val;
         printf("Enter the size: ");
         scanf("%d",&size);
        s= createStack(size);
    do{
        
        printf("\n1)Push\n2)Pop\n3)Peek\n4)is full\n5)is empty\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d",&val);
            push(s,val);
            display(s);
            break;
            
            case 2:
            val= pop(s);
            if(val!=-9999)
            printf("The deleted element is: %d\n",val);
            display(s);
            break;
            
            case 3:
             val= peek(s);
            if(val!=-9999)
            printf("The top element is: %d\n ",val);
            display(s);
            break;
            
            case 4:
            if(isfull(s)){
                printf("The stack is full!!\n");
            }
            else{
                printf("The stack is not full\n");
            }
            break; 
            
            case 5:
            if(isempty(s)){
                 printf("The stack is empty!!\n");
            }
            else{
                 printf("The stack is not empty\n");
            }

            break;
            
        }
    }while(choice>=1 && choice<=5);
   
    return 0;
}