
#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};

struct queue {
    struct node * front;
    struct node * rear;
};
struct queue * CreateQueue(){
    struct queue * q=(struct queue *)malloc(sizeof(struct queue));
    q->front=NULL;
    q->rear=NULL;
}
struct node * CreateNode(int data){
    struct node * nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    return nn;
}
int isempty(struct queue *s){
    if(s->front==NULL) return 1;
    else return 0;
}
struct queue * Enqueue(struct queue * s,int data){
    struct node * nn=CreateNode(data);
   if(isempty(s)){
       s->front=nn;
       s->rear=nn;
       return s;
   }
   else{
       s->rear->next=nn;
       s->rear=nn;
       return s;
   }
}
int Dequeue(struct queue *s){
    if(isempty(s)){
        return NULL;
    }
    else if(s->front->next==NULL){
        s->front=NULL;
        s->rear=NULL;
        return s->front;
    }
    else{
        s->front=s->front->next;
        return s;
    }
}
void  getFront(struct queue * s){
    if(isempty(s)) printf("Queue is empty\n");
    else{
        printf("%d\n",s->front->data);
    }
}
void getRear(struct queue *s){
    if(isempty(s)) printf("Queue is empty\n");
    else{
        printf("%d\n",s->rear->data);
    }
    
}
void display(struct queue * s){
    if(s->front==NULL) printf("Queue is empty\n");
    else{
        struct node * temp=s->front;
        while(temp!=s->rear){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}


int main()
{
    struct queue * q=NULL;
    int choice,val;
   do{
   
    printf("1)Enqueue\n2)Dequeue\n3)Get front\n4)Get rear\n5)Is empty\n Enter the choice: ");
    scanf("%d",choice);
    switch(choice){
        case 1:
        printf("Enter the value to be inserted: ");
        scanf("%d",val);
        q=Enqueue(q,val);
        display(q);
        break;
        case 2:
        val=Dequeue(q);
        printf("The dequed value is: %d",val);
        display(q);
        break;
        case 3:
        getFront(q);
        display(q);
        break;
        case 4:
        getRear(q);
        display(q);
        break;
        case 5:
        display(q);
        break;
    }

   }while(choice>=1 && choice<=5);

    return 0;
}