#include <stdio.h>
struct node{
    int data;
    int next;
};
struct stack{
   struct node * head;
   struct node *tail;
};
struct stack * CreateStack(){
    struct stack * s=(struct stack *)malloc(sizeof(struct stack));
    s->head=NULL;
    return s;
}
struct node * CreateNode(int data){
    struct node * nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    return nn;
}
struct stack * push(struct stack *s,int data){
    struct node *nn=CreateNode(data);
 if(s->head==NULL) return s;
 else {
    nn->next=s->head;
    s->head=nn;
    return s;
 }
}
void pop(struct stack *s){
    if(s->head==NULL) 
    printf("Cannot be popped\n");
 else{
   s->head=s->head->next;
 }
    }

void peek(struct stack *s){
    if(s->head==NULL) printf("There is no node..\n") ;
    else{
        printf("The peek value is: %d ",s->head->data);
    }
}
void display(struct stack *s){
    if(s->head==NULL) printf("There is no node..\n");
    else{
        s->tail=s->head;
        while(s->tail->next!=NULL){
        printf("%d ",s->tail->data);
    }
    printf("\n");
}
}


int main(){
    int choice,val,pval;
struct stack *s=createStack();
do{
    printf("1)Push\n2)Pop\n3)Peek\nEnter the choice: ");
scanf("%d",&choice);
switch(choice){
    case 1:
    printf("Enter the value to be pushed: ");
    scanf("%d",&val);
    s=push(s,val);
    display(s);
    break;
    case 2:
    pop(s);
    display(s);
    break;
    case 3:
    display(s);
    break;
}
}while(choice>=1 && choice<=3);




    return 0;
}
