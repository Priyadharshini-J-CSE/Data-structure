#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int *arr;
    int front;
    int rear;
    int capacity;
}queue;
queue * CreateQueue(int capacity){
    queue * q=(queue *) malloc(sizeof(queue));
    q->capacity=capacity;
    q->arr=(int *)malloc(capacity*sizeof(queue));
    q->front =q->rear=-1;
}
// if(rear==-1 && front==-1) //if(rear==-1)
// front++ // front=0 
// rear++ //rear=0
// arr[rear]=val;
// else{
//     rear++;
//     arr[rear]=val;//arr[++rear]=val
// }
int isfull(queue *q){
    if(q->rear==q->capacity-1) return 1;
    else return 0;
}
int isempty(queue *q){
    if(q->front==-1) return 1;
    else return 0;
}
void enqueue(queue * q,int val){
    if(isfull(q)) 
    printf("Queue is full\n");
    else{
        if(q->rear==-1){
            q->front=0;
            q->rear=0;
            q->arr[q->rear]=val;
        }
        else
        q->arr[++q->rear]=val;
    }
}

int dequeue(queue *q){
    if(isempty(q)) return -999;
    else return q->arr[q->front++];
}
int getFront(queue * q){
    if(isempty(q))  return -999;
    else return q->arr[q->front];
}
int getRear(queue * q){
    if(isempty(q))  return -999;
    else return q->arr[q->rear];
}
//Can main function have parameters?
void display(queue * q){
    for(int i=q->front ;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}


int main(){
    int capacity;
    printf("Enter the capacity of the queue: ");
    scanf("%d",&capacity);
    queue * q=CreateQueue(capacity);
    int choice,val,deval;
    int front,rear;
    do{
        printf("1)Enqueue\n2)Dequeue\n3)Get Front\n4)Get Rear\n5)isempty\n6)isfull\n Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&val);
            enqueue(q,val);
            display(q);
            break;

            case 2:

            deval=dequeue(q);
            if(deval!=-999) 
            printf("The dequeued value is : %d\n",deval);
            display(q);
            break;

            case 3:
             front=getFront(q);
             if(front!=-999) 
            printf("The front value of the queue is :%d\n ",front);
            display(q);
            break;
            case 4:
            rear=getRear(q);
            if(rear!=-999) 
            printf("The rear value of the queue is :%d\n ",rear);
            display(q);
            break;
            case 5:
            if(isempty(q)==1) printf("Queue is empty\n");
            else printf("Queue is not empty\n");
            display(q);
            break;
            case 6:
            if(isfull(q)==1) printf("Queue is full\n");
            else printf("Queue is not full\n");
            display(q);
            break;
            



        }
    }while(choice>=1 && choice <=6);
    return 0;
}
