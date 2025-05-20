/*
1. Create array
2. Get value
3. Display/view 
4. Insert at beginning
5. Insert at last
6. Insert at specific position
7. Delete at first
8. Delete at last
9. Delete at specific position
10. Update specific index
*/
#include <stdio.h>
#include <stdlib.h>
int lastindex=0;

int value;
int * createArray(int size){
	int * temp;
	temp = (int*)malloc(sizeof(int)*size);
	return temp;
}

void getvalue(int * arr, int size){
	for(int i=0;i<size;i++){
		scanf("%d",arr+i);
	}
}

void display(int * arr, int size){
	for(int i=0;i<size;i++){
		printf("%d\n",*(arr+i));
	}
}

void insertAtFirst(int * arr, int value){
	for(int i=lastindex;i>0;i--){
		arr[i] = arr[i-1];
	}
	//printf("The value to be inserted: ");
	//scanf("%d",arr+0);
    arr[0]=value;
	lastindex++;
}
void insertAtLast(int *arr,int value){
   arr[lastindex]=value;
   lastindex++;
}

void insertAtSpecificPosition(int *arr,int value,int index){
    if(index>lastindex){
        printf("It cannot insert at the given position");
        return;
    }
    for(int i=lastindex;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=value;
    lastindex++;
}
int deleteAtFirst(int *arr){
    int temp=arr[0];
    for(int i=0;i<lastindex;i++){
        arr[i]=arr[i+1];
    }
    lastindex--;
    return temp;
}
int deleteAtLast(int * arr){
    return arr[--lastindex];

}
int main(){
	int *arr,choice,index; //store starting address
	int size;
	printf("Enter the size of array: ");
	scanf("%d",&size);
	arr = createArray(size);
	getvalue(arr,size);
  

    do{
        printf("Enter the choice : ");
     
        printf("1) Insert At First ");
        printf("2) Insert At Last ");
         printf("3) Insert At Specific position ");
         printf("4) Delete At First ");
         printf("5) Delete At Last ");
         scanf("%d",&choice);
switch(choice){
    case 1:
    printf("Enter the value");
    scanf("%d",value);
    insertAtFirst(arr,value);
    break;
    case 2:
    printf("Enter the value");
    scanf("%d",value);
    insertAtLast(arr,value);
    break;
    case 3:
    printf("Enter the value");
    scanf("%d",&value);
    printf("Enter the index");
    scanf("%d",&index);
    insertAtSpecificPosition(arr,value,index);
    break;
    case 4:
    value=deleteAtFirst(arr);
    printf("The deleted value is %d\n",value);
    printf("Array After Deleting\n");
    display(arr,size);
    break;
    case 5:
    value=deleteAtFirst(arr);
    printf("The deleted value is %d\n",value);
    printf("Array After Deleting\n");
    display(arr,size);
    break;

}
display(arr,size);
}while(choice >=1 && choice <=5);
	//display(arr,size);
	//insertAtFirst(arr,size);
	return 0;
}
