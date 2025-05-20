#include<stdio.h>
#include<stdlib.h>
int main(){
    int size,choice,index;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int * arr=(int *)malloc(sizeof(int)*size+1);
    printf("Enter the values: ");
    for(int i=1;i<=size;i++){
        scanf("%d",&arr[i]);
    }
    /*
    left child->parent*2
    right child->parent*2+1
    parent->child/2
    */
    do{
    printf("1)Left child\n2)Right Child\n3)Parent\n4)Exit\n");
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the index of the parent : ");
        scanf("%d",&index);
        printf("The index of the child is : %d\n",index*2);
        printf("The value at the child is: %d\n",arr[index*2]);
        break;
        case 2:
        printf("Enter the index of the parent: ");
        scanf("%d",&index);
        printf("The index of the child is : %d\n",(index*2)+1);
        printf("The value at the child is : %d\n",arr[(index*2)+1]);
        break;
        case 3:
        printf("Enter the index of the child : ");
        scanf("%d",&index);
        printf("The index of the parent is : %d\n",index/2);
        printf("The value at the child is : %d\n",arr[index/2]);
        break;
        case 4:
        return 0;
    }
}while(choice>=1 && choice<=3);


    return 0;
}