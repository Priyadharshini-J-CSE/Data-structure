//stack using queue
#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int size;
    int front;
    int rear;
    int * arr;
}queue;
int isFull(queue *q){
    return q->rear==q->size-1;
}
int isEmpty(queue * q){
    return q->front==-1;
}
queue * CreateQueue(int size){
    queue * q=(queue *)malloc(sizeof(queue));
    q->size=size;
    q->front=q->rear=-1;
    q->arr=(int *)malloc(sizeof(int)*size);
return q;
}
void Enqueue(queue * q,int val){
    if(isFull(q)) printf("Queue Overflow");
    else if(q->front==-1){
        q->front=q->rear=0;
        q->arr[q->rear]=val;
    }
    else{
        q->arr[++q->rear]=val;
    }
}
/*int Dequeue(queue * q){
    if(isEmpty(q)) return -999;
    else{
    return q->arr[q->front++];
    }
}*/
void push(queue * q1,int val){
      Enqueue(q1,val);
}
int pop(queue *q1){//int pop(queue *q1,queue * q2){
    if(isEmpty(q1)) return -999;
   
   return q1->arr[q1->rear--];
    
}
void display(queue * q){
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}
int main(){
    int size,choice,val,val1;
    printf("Enter the size of the array: ");
  scanf("%d",&size);
    queue * q1=CreateQueue(size);
    // queue * q2=CreateQueue(size);
    do{
    printf("1)Push\n2)Pop\n3)Display\nEnter the choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the value to be pushed: ");
        scanf("%d",&val);
        push(q1,val);
        display(q1);
        break;
        case 2:
        val1=pop(q1);//val1=pop(q1,q2);
        if(val1!=-999){
            printf("The dequeued value is: %d\n",val1);
        }
        display(q1);
        break;
        case 3:
        display(q1);
        break;



    }
}while(choice>=1 && choice<=3);
    return 0;
}